#pragma once

#include "noncopyable.h"
#include <pthread.h>

namespace sone
{

namespace utils
{

class CountLatch : noncopyable
{
public:
    CountLatch(int count);
    ~CountLatch();

    void Wait();
    void CountDown();

private:
    pthread_mutex_t countLock_;
    pthread_cond_t releaseCond_;
    int count_;
};

}

}
