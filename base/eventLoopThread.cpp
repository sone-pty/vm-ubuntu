#include "eventLoopThread.h"
#include "eventLoop.h"

#include <assert.h>

using namespace sone;
using namespace sone::utils;

EventLoopThread::EventLoopThread(const ThreadInitCallback &cb,
                                 const std::string &name)
    : loop_(NULL),
      exiting_(false),
      thread_(std::bind(&EventLoopThread::threadFunc, this)),
      callback_(cb)
{
    pthread_mutex_init(&mutex_, NULL);
    pthread_cond_init(&cond_, NULL);
}

EventLoopThread::~EventLoopThread()
{
    exiting_ = true;
    if (loop_ != NULL) // not 100% race-free, eg. threadFunc could be running callback_.
    {
        // still a tiny chance to call destructed object, if threadFunc exits just now.
        // but when EventLoopThread destructs, usually programming is exiting anyway.
        loop_->quit();
        thread_.join();
    }

    pthread_mutex_destroy(&mutex_);
    pthread_cond_destroy(&cond_);
}

EventLoop *EventLoopThread::startLoop()
{
    assert(!thread_.started());
    thread_.start();

    EventLoop *loop = NULL;
    {
        pthread_mutex_lock(&mutex_);
        while (loop_ == NULL)
        {
            pthread_cond_wait(&cond_, &mutex_);
        }
        loop = loop_;
        pthread_mutex_unlock(&mutex_);
    }

    return loop;
}

void EventLoopThread::threadFunc()
{
    EventLoop loop;

    if (callback_)
    {
        callback_(&loop);
    }

    {
        pthread_mutex_lock(&mutex_);
        loop_ = &loop;
        pthread_cond_signal(&cond_);
        pthread_mutex_unlock(&mutex_);
    }

    loop.loop();

    pthread_mutex_lock(&mutex_);
    loop_ = NULL;
    pthread_mutex_unlock(&mutex_);
}