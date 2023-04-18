#pragma once

#include <game/common/base_server.h>
#include <base/callback.h>

#include <google/protobuf/message.h>

namespace sone
{
    using namespace utils;

    namespace entry
    {
        class EntryServer : public common::BaseServer
        {
        public:
            EntryServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port);
            ~EntryServer();
            void DispatchMessage(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time) override;
        
        private:
            void On_C2E_LoginRequest(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time);
        };
    }
}