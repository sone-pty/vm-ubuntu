#pragma once

#include <base/tcpserver.h>
#include <base/callback.h>

#include <google/protobuf/message.h>

#define DISPATCH_MESSAGE(_service, _type) \
    if(message->GetDescriptor() == _service::_type::descriptor()) \
    { \
        On_##_type(conn, message, time); \
    }

#define REGIST_MESSAGE(_type, _message) \
    case _type: \
        descriptor = _message::descriptor(); break;
    
namespace sone
{
    using namespace utils;

    namespace common
    {
        class BaseServer : public TcpServer
        {
        public:
            BaseServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port, const std::string& name);
            ~BaseServer();
            void Init();

            virtual void DispatchMessage(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time) = 0;
            virtual const google::protobuf::Descriptor* GetDescriptor(int32_t type) = 0;
        
        private:
            void OnMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp time);
        };
    }
}