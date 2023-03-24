#include "callback.h"
#include "timestamp.h"
#include "noncopyable.h"

#include <atomic>

namespace sone
{
    namespace utils
    {

        ///
        /// Internal class for timer event.
        ///
        class Timer : noncopyable
        {
        public:
            Timer(TimerCallback cb, Timestamp when, double interval)
                : callback_(std::move(cb)),
                  expiration_(when),
                  interval_(interval),
                  repeat_(interval > 0.0),
                  sequence_(s_numCreated_.load())
            {
            }

            void run() const
            {
                callback_();
            }

            Timestamp expiration() const { return expiration_; }
            bool repeat() const { return repeat_; }
            int64_t sequence() const { return sequence_; }

            void restart(Timestamp now);

            static int64_t numCreated() { return s_numCreated_.load(); }

        private:
            const TimerCallback callback_;
            Timestamp expiration_;  // 下次触发时间
            const double interval_; // 秒
            const bool repeat_;     // 是否重复
            const int64_t sequence_;

            static std::atomic_int64_t s_numCreated_;
        };

    }
}