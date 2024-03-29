#pragma once

#include "timestamp.h"
#include "define.h"

#include <functional>
#include <memory>

namespace sone
{
    using std::placeholders::_1;
    using std::placeholders::_2;
    using std::placeholders::_3;

    // should really belong to base/Types.h, but <memory> is not included there.

    template <typename T>
    inline T *get_pointer(const std::shared_ptr<T> &ptr)
    {
        return ptr.get();
    }

    template <typename T>
    inline T *get_pointer(const std::unique_ptr<T> &ptr)
    {
        return ptr.get();
    }

    // Adapted from google-protobuf stubs/common.h
    // see License in muduo/base/Types.h
    template <typename To, typename From>
    inline ::std::shared_ptr<To> down_pointer_cast(const ::std::shared_ptr<From> &f)
    {
        if (false)
        {
            define::implicit_cast<From *, To *>(0);
        }

#ifndef NDEBUG
        assert(f == NULL || dynamic_cast<To *>(get_pointer(f)) != NULL);
#endif
        return ::std::static_pointer_cast<To>(f);
    }

    namespace utils
    {

        // All client visible callbacks go here.

        class Buffer;
        class TcpConnection;

        typedef std::shared_ptr<TcpConnection> TcpConnectionPtr;
        typedef std::function<void()> TimerCallback;
        typedef std::function<void(const TcpConnectionPtr &)> ConnectionCallback;
        typedef std::function<void(const TcpConnectionPtr &)> CloseCallback;
        typedef std::function<void(const TcpConnectionPtr &)> WriteCompleteCallback;
        typedef std::function<void(const TcpConnectionPtr &, size_t)> HighWaterMarkCallback;

        // the data has been read to (buf, len)
        typedef std::function<void(const TcpConnectionPtr &, Buffer *, Timestamp)> MessageCallback;

        void defaultConnectionCallback(const TcpConnectionPtr &conn);
        void defaultMessageCallback(const TcpConnectionPtr &conn,
                                    Buffer *buffer,
                                    Timestamp receiveTime);

        // A barely usable WeakCallback
        template <typename CLASS, typename... ARGS>
        class WeakCallback
        {
        public:
            WeakCallback(const std::weak_ptr<CLASS> &object,
                         const std::function<void(CLASS *, ARGS...)> &function)
                : object_(object), function_(function)
            {
            }

            // Default dtor, copy ctor and assignment are okay

            void operator()(ARGS &&...args) const
            {
                std::shared_ptr<CLASS> ptr(object_.lock());
                if (ptr)
                {
                    function_(ptr.get(), std::forward<ARGS>(args)...);
                }
                // else
                // {
                //   LOG_TRACE << "expired";
                // }
            }

        private:
            std::weak_ptr<CLASS> object_;
            std::function<void(CLASS *, ARGS...)> function_;
        };

        template <typename CLASS, typename... ARGS>
        WeakCallback<CLASS, ARGS...> makeWeakCallback(const std::shared_ptr<CLASS> &object,
                                                      void (CLASS::*function)(ARGS...))
        {
            return WeakCallback<CLASS, ARGS...>(object, function);
        }

        template <typename CLASS, typename... ARGS>
        WeakCallback<CLASS, ARGS...> makeWeakCallback(const std::shared_ptr<CLASS> &object,
                                                      void (CLASS::*function)(ARGS...) const)
        {
            return WeakCallback<CLASS, ARGS...>(object, function);
        }
    }
}