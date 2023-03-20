#include "threadPool.h"
#include <assert.h>

using namespace sone::utils;

ThreadPool::ThreadPool(const std::string& name)
    : name_(name), running_(false)
{
    pthread_mutex_init(&taskLock_, NULL);
    pthread_cond_init(&notFull_, NULL);
    pthread_cond_init(&notEmpty_, NULL);
}

ThreadPool::~ThreadPool()
{
    pthread_mutex_destroy(&taskLock_);
    pthread_cond_destroy(&notFull_);
    pthread_cond_destroy(&notEmpty_);
}

void ThreadPool::start(int nums)
{
    assert(running_ == false && nums > 0);
    threads_.reserve(nums);
    running_ = true;

    for(int i = 0; i < nums; ++i)
    {
        threads_.emplace_back(new Thread(std::bind(&ThreadPool::threadFunc, this)));
        threads_[i]->start();
    }
}

void ThreadPool::stop()
{
    pthread_mutex_lock(&taskLock_);

    {
        running_ = false;
        pthread_cond_broadcast(&notEmpty_);
        pthread_cond_broadcast(&notFull_);
    }

    pthread_mutex_unlock(&taskLock_);

    for(auto& th : threads_)
    {
        th->join();
    }
}

bool ThreadPool::isFull()
{
    bool ret = false;
    pthread_mutex_lock(&taskLock_);

    {
        ret = taskqueue_.size() == maxQueueSize_;
    }

    pthread_mutex_unlock(&taskLock_);
    return ret;
}

void ThreadPool::pushTask(Task task)
{
    pthread_mutex_lock(&taskLock_);

    {
        while(isFull() && running_)
        {
            // 等待队列空闲
            pthread_cond_wait(&notFull_, &taskLock_);
        }

        // 检查是否停止
        if(!running_)
        {
            pthread_mutex_unlock(&taskLock_);
            return;
        }

        taskqueue_.push(task);
        // 唤醒消费者
        pthread_cond_signal(&notEmpty_);
    }

    pthread_mutex_unlock(&taskLock_);
}

ThreadPool::Task ThreadPool::take()
{
    Task task = nullptr;
    pthread_mutex_lock(&taskLock_);

    {
        while(taskqueue_.empty() && running_)
        {
            pthread_cond_wait(&notEmpty_, &taskLock_);
        }

        if(!running_)
        {
            pthread_mutex_unlock(&taskLock_);
            return nullptr;
        }

        task = taskqueue_.front();
        taskqueue_.pop();
        pthread_cond_signal(&notFull_);
    }

    pthread_mutex_unlock(&taskLock_);
    return task;
}

void ThreadPool::threadFunc()
{
    while(running_)
    {
        Task task(take());
        if(task)
        {
            task();
        }
    }
}