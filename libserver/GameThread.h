#pragma once

#include <base/noncopyable.h>
#include <base/thread.h>

namespace sone
{
    namespace libserver
    {
        class GameThread : noncopyable
        {
        public:

        private:
            utils::Thread thread_;            
        };
    }
}