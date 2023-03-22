#pragma once

#include "currentThread.h"

#include <sys/types.h>
#include <memory>

namespace sone
{
    namespace utils
    {
        class Poller;

        class EventLoop
        {
        public:

            void updateChannel(Channel* channel);
            void removeChannel(Channel* channel);
            bool hasChannel(Channel* channel);

            void assertInLoopThread()
            {
                if (!isInLoopThread())
                {
                    abortNotInLoopThread();
                }
            }

            bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }

        private:
            void abortNotInLoopThread();

        private:
            const pid_t threadId_;
            bool eventHandling_;
            std::unique_ptr<Poller> poller_;

            using ChannelList = std::vector<Channel*>;
            ChannelList activeChannels_;
            Channel* currentActiveChannel_;
        };
    }
}