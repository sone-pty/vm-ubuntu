#pragma once

#include <pthread.h>
#include <deque>
#include <assert.h>

#include "noncopyable.h"

namespace sone
{
    namespace utils
    {
        template <typename T>
        class BlockingQueue : noncopyable
        {
            class MutexLockGuard
            {
            public:
                MutexLockGuard(pthread_mutex_t* mtx)
                    : mtx_(mtx)
                {
                    if(mtx)
                    {
                        pthread_mutex_lock(mtx);
                    }
                }

                ~MutexLockGuard()
                {
                    if(mtx_)
                    {
                        pthread_mutex_unlock(mtx_);
                    }
                }
            private:
                pthread_mutex_t* mtx_;
            };

        public:
            using queue_type = std::deque<T>;

            BlockingQueue()
                : queue_()
            {
                pthread_mutex_init(&mutex_, NULL);
                pthread_cond_init(&notEmpty_, NULL);
            }

            ~BlockingQueue()
            {
                pthread_mutex_destroy(&mutex_);
                pthread_cond_destroy(&notEmpty_);
            }

            void put(const T &x)
            {
                MutexLockGuard lock(&mutex_);
                queue_.push_back(x);
                pthread_cond_signal(&notEmpty_);
            }

            void put(T &&x)
            {
                MutexLockGuard lock(&mutex_);
                queue_.push_back(std::move(x));
                pthread_cond_signal(&notEmpty_);
            }

            T take()
            {
                MutexLockGuard lock(&mutex_);
                // always use a while-loop, due to spurious wakeup
                while (queue_.empty())
                {
                    pthread_cond_wait(&notEmpty_, &mutex_);
                }
                assert(!queue_.empty());
                T front(std::move(queue_.front()));
                queue_.pop_front();
                return front;
            }

            queue_type drain()
            {
                queue_type queue;
                {
                    MutexLockGuard lock(&mutex_);
                    queue = std::move(queue_);
                    assert(queue_.empty());
                }
                return queue;
            }

            size_t size() const
            {
                MutexLockGuard lock(&mutex_);
                return queue_.size();
            }

        private:
            pthread_mutex_t mutex_;
            pthread_cond_t notEmpty_;
            queue_type queue_;
        };

    }

}