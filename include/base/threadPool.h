#pragma once

#include "thread.h"
#include <queue>
#include <vector>
#include <memory>
#include <string>

namespace sone
{

namespace utils
{

class ThreadPool : noncopyable
{
public:
    using Task = std::function<void()>;

    explicit ThreadPool(const std::string& name);
    ~ThreadPool();

    // 任务队列上限
    void setMaxQueueSize(int nums) { maxQueueSize_ = nums; }
    // assert: nums > 0
    void start(int nums);
    void stop();

    void pushTask(Task task);

private:
    Task take();
    void threadFunc();
    bool isFull();

private:
    // 线程队列相关
    std::vector<std::unique_ptr<Thread>> threads_;

    // 任务队列
    pthread_mutex_t taskLock_;
    pthread_cond_t notFull_;
    pthread_cond_t notEmpty_;
    std::queue<Task> taskqueue_;
    int maxQueueSize_;

    std::string name_;
    bool running_;
};

}

}