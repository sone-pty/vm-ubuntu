#pragma once

#include <base/tcpserver.h>
#include <base/callback.h>

#include <google/protobuf/message.h>

namespace sone
{
    using namespace utils;

    namespace entry
    {
        class EntryServer : public TcpServer
        {
        public:
            EntryServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port);
            ~EntryServer();
            void Init();

        private:
            void OnMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp time);
            void On_C2E_LoginRequest(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time);
        };
    }
}