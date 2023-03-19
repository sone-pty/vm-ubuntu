#pragma once

#include "countLatch.h"
#include <functional>

namespace sone
{

namespace utils
{
    // 线程回调
    using ThreadCallback = std::function<void()>;
class Thread
{
public:
    // 线程执行函数
    using ThreadFunc = std::function<void()>;

    explicit Thread(ThreadFunc func);
    ~Thread();

    pid_t tid() const { return tid_; }
    bool started() const { return started_; }
    void setStartCb(const ThreadCallback& cb) { startCb_ = std::move(cb); }  
    void setStopCb(const ThreadCallback& cb) { stopCb_ = std::move(cb); } 

    int join();
    void start();

private:
    pthread_t pth_;
    pid_t tid_;
    ThreadFunc func_;
    bool started_;
    bool joined_;
    CountLatch cl_;

    // 需要自己确保是线程安全的调用
    ThreadCallback startCb_;
    ThreadCallback stopCb_;
};

}

}