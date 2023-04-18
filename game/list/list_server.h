#pragma once

#include <game/common/base_server.h>
#include <base/callback.h>

#include <google/protobuf/message.h>

namespace sone
{
    using namespace utils;

    namespace list
    {
        class ListServer : public common::BaseServer
        {
        public:
            ListServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port);
            ~ListServer();
            void DispatchMessage(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time) override;
            const google::protobuf::Descriptor* GetDescriptor(int32_t type) override;
        
        private:
            void On_E2L_UploadLoading(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time);
        };
    }
}