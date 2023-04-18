#include "base_server.h"
#include "../proto/entry.pb.h"

#include <base/logging.h>
#include <base/eventLoop.h>

#include <google/protobuf/util/type_resolver.h>
#include <google/protobuf/dynamic_message.h>

using namespace sone;
using namespace sone::common;

BaseServer::BaseServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port, const std::string& name)
    : TcpServer(baseLoop, InetAddress(ip, port), name, reuse_port > 0 ? kReusePort : kNoReusePort)
{

}

BaseServer::~BaseServer()
{

}

void BaseServer::Init()
{
    setMessageCallback(std::bind(&BaseServer::OnMessage, this, _1, _2, _3));
}

void BaseServer::OnMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp time)
{
    int64_t trait;
    int32_t message_len; 
    int32_t type;
    const google::protobuf::Descriptor* descriptor;
    const google::protobuf::Message* prototype;

    while(buffer->readableBytes() > sizeof(int64_t))
    {
        trait = buffer->readInt64();
        message_len = (int32_t)(trait >> 32);
        type = (int32_t)(trait & 0xFFFFFFFF);

        switch(type)
        {
            case Entry::C2E_LOGIN_MESSAGE: 
                descriptor = Entry::C2E_LoginRequest::descriptor();
                break;
            default:
                descriptor = NULL; break;
        }

        if(descriptor == NULL)
        {
            LOG_ERROR << "descriptor == NULL";
            buffer->retrieve(message_len);
            continue;
        }

        prototype = google::protobuf::MessageFactory::generated_factory()->GetPrototype(descriptor);
        google::protobuf::Message *message = prototype->New();
        
        if(!message->ParseFromArray(buffer->peek(), message_len))
        {
            LOG_ERROR << "Parse From array failed";
            buffer->retrieve(message_len);
            delete message;
            continue;
        }
        else
        {
            buffer->retrieve(message_len);
        }

        // 分发处理
        DispatchMessage(conn, message, time);
    }
}