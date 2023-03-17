#pragma once

#include "countLatch.h"
#include <functional>

namespace sone
{

namespace utils
{
    using ThreadCallback = std::function<void()>;
class Thread
{
public:
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

    // 需要自己确保线程安全
    ThreadCallback startCb_;
    ThreadCallback stopCb_;
};

}

}