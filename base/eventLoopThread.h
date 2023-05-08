#pragma once

#include "thread.h"

#include <string>

namespace sone
{
    namespace utils
    {
        class EventLoop;

        class EventLoopThread : noncopyable
        {
        public:
            typedef std::function<void(EventLoop *)> ThreadInitCallback;

            EventLoopThread(const ThreadInitCallback &cb = ThreadInitCallback(), const std::string &name = std::string());
            ~EventLoopThread();
            EventLoop *startLoop();

        private:
            void threadFunc();

            EventLoop *loop_;
            bool exiting_;
            Thread thread_;
            pthread_mutex_t mutex_;
            pthread_cond_t cond_;
            ThreadInitCallback callback_;
        };
    }
}