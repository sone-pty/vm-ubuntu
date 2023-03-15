#include "countLatch.h"
#include <assert.h>

using namespace sone::utils;

CountLatch::CountLatch(int count) : count_(count)
{
    assert(count > 0);
    pthread_mutex_init(&countLock_, NULL);
    pthread_cond_init(&releaseCond_, NULL);
}

CountLatch::~CountLatch()
{
    pthread_mutex_destroy(&countLock_);
    pthread_cond_destroy(&releaseCond_);
}

void CountLatch::Wait()
{
    pthread_mutex_lock(&countLock_);

    {
        while(count_ > 0)
        {
            pthread_cond_wait(&releaseCond_, &countLock_);
        }
    }

    pthread_mutex_unlock(&countLock_);
}

void CountLatch::CountDown()
{
    pthread_mutex_lock(&countLock_);

    {
        if(--count_ == 0)
        {
            pthread_cond_broadcast(&releaseCond_);
        }
    }

    pthread_mutex_unlock(&countLock_);
}