#pragma once

#include "currentThread.h"
#include "timerId.h"
#include "callback.h"

#include <sys/types.h>
#include <memory>
#include <vector>
#include <pthread.h>

namespace sone
{
    namespace utils
    {
        class Poller;
        class Channel;
        class TimerQueue;

        class EventLoop
        {
        public:
            using Functor = std::function<void()>;

            EventLoop();
            ~EventLoop();

            /// Loops forever.
            ///
            /// Must be called in the same thread as creation of the object.
            ///
            void loop();

            /// Quits loop.
            ///
            /// This is not 100% thread safe, if you call through a raw pointer,
            /// better to call through shared_ptr<EventLoop> for 100% safety.
            void quit();

            /// Runs callback at 'time'.
            /// Safe to call from other threads.
            ///
            TimerId runAt(Timestamp time, TimerCallback cb);
            ///
            /// Runs callback after @c delay seconds.
            /// Safe to call from other threads.
            ///
            TimerId runAfter(double delay, TimerCallback cb);
            ///
            /// Runs callback every @c interval seconds.
            /// Safe to call from other threads.
            ///
            TimerId runEvery(double interval, TimerCallback cb);
            ///
            /// Cancels the timer.
            /// Safe to call from other threads.
            ///
            void cancel(TimerId timerId);

            /// Runs callback immediately in the loop thread.
            /// It wakes up the loop, and run the cb.
            /// If in the same loop thread, cb is run within the function.
            /// Safe to call from other threads.
            void runInLoop(Functor cb);
            // push into pendingCallbacks queue & wake up loop
            void queueInLoop(Functor cb);

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

            static EventLoop* getEventLoopOfCurrentThread();

        private:
            void abortNotInLoopThread();
            void wakeup();
            void handleWakeupRead();  // for wake up
            void doPendingFunctors();
            void printActiveChannels() const;

        private:
            const pid_t threadId_;
            bool quit_;
            bool eventHandling_;
            bool callingPendingFunctors_;
            std::unique_ptr<Poller> poller_;
            std::unique_ptr<TimerQueue> timerQueue_;
            Timestamp pollReturnTime_;

            using ChannelList = std::vector<Channel*>;
            ChannelList activeChannels_;
            Channel* currentActiveChannel_;

            pthread_mutex_t pcbLock_;
            std::vector<Functor> pendingCallbacks_;

            int wakeupFd_;
            std::unique_ptr<Channel> wakeupChannel_;
        };
    }
}