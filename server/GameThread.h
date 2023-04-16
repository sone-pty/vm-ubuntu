#pragma once

#include <vector>
#include <memory>
#include <pthread.h>

#include <base/noncopyable.h>
#include <base/thread.h>

#include "IDisposeable.h"

namespace sone
{
    namespace libserver
    {
        class ThreadObject;
        
        class GameThread : noncopyable, public IDisposeable
        {
        public:
            GameThread();

            void Start();
            void Stop();
            void Dispose() override;
            void AddObejct(std::unique_ptr<ThreadObject> obj);

        private:
            void run();

        private:
            bool run_;
            pthread_mutex_t mtx_;
            std::vector<std::unique_ptr<ThreadObject>> objects_;
            utils::Thread thread_;
        };
    }
}