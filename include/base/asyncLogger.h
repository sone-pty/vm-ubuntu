#pragma once

#include "noncopyable.h"
#include "countLatch.h"
#include "thread.h"
#include "logstream.h"

#include <atomic>
#include <vector>
#include <string>
#include <memory>

namespace sone
{
    namespace utils
    {
        class AsyncLogging : noncopyable
        {
        public:
            AsyncLogging(const std::string &basename,
                         off_t rollSize,
                         int flushInterval = 3);

            ~AsyncLogging()
            {
                if (running_)
                {
                    stop();
                }

                pthread_mutex_destroy(&mutex_);
                pthread_cond_destroy(&cond_);
            }

            void append(const char *logline, int len);

            void start()
            {
                running_ = true;
                thread_.start();
                latch_.Wait();
            }

            void stop()
            {
                running_ = false;
                pthread_cond_signal(&cond_);
                thread_.join();
            }

        private:
            void threadFunc();

            typedef sone::detail::FixedBuffer<sone::detail::kLargeBuffer> Buffer;
            typedef std::vector<std::unique_ptr<Buffer>> BufferVector;
            typedef BufferVector::value_type BufferPtr;

            const int flushInterval_;
            std::atomic<bool> running_;
            const std::string basename_;
            const off_t rollSize_;
            Thread thread_;
            CountLatch latch_;
            pthread_mutex_t mutex_;
            pthread_cond_t cond_;
            BufferPtr currentBuffer_;
            BufferPtr nextBuffer_;
            BufferVector buffers_;
        };
    }

}