#pragma once

#include <functional>

#include "socket.h"
#include "channel.h"

namespace sone
{
    namespace utils
    {
        class EventLoop;
        class InetAddress;

        ///
        /// Acceptor of incoming TCP connections.
        ///
        class Acceptor : noncopyable
        {
        public:
            typedef std::function<void(int sockfd, const InetAddress &)> NewConnectionCallback;

            Acceptor(EventLoop *loop, const InetAddress &listenAddr, bool reuseport);
            ~Acceptor();

            void setNewConnectionCallback(const NewConnectionCallback &cb)
            {
                newConnectionCallback_ = cb;
            }

            void listen();

            bool listening() const { return listening_; }

            // Deprecated, use the correct spelling one above.
            // Leave the wrong spelling here in case one needs to grep it for error messages.
            // bool listenning() const { return listening(); }

        private:
            void handleRead();

            EventLoop *loop_;
            Socket acceptSocket_;
            Channel acceptChannel_;
            NewConnectionCallback newConnectionCallback_;
            bool listening_;
            int idleFd_;
        };

    } 
}