#include "entry_server.h"
#include "../proto/entry.pb.h"

#include <base/logging.h>
#include <base/eventLoop.h>

#include <google/protobuf/util/type_resolver.h>
#include <google/protobuf/dynamic_message.h>

using namespace sone;
using namespace sone::entry;

#define REGIST_MESSAGE(_message, _type, _conn, _time) \
    if(_message->GetDescriptor() == Entry::_type::descriptor()) \
    { \
        On_##_type(_conn, _message, _time); \
    }

EntryServer::EntryServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port)
    : TcpServer(baseLoop, InetAddress(ip, port), "Entry", reuse_port > 0 ? kReusePort : kNoReusePort)
{
    
}

EntryServer::~EntryServer()
{

}

void EntryServer::Init()
{
    setMessageCallback(std::bind(&EntryServer::OnMessage, this, _1, _2, _3));
}

void EntryServer::OnMessage(const TcpConnectionPtr& conn, Buffer* buffer, Timestamp time)
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
        REGIST_MESSAGE(message, C2E_LoginRequest, conn, time)
    }
}

void EntryServer::On_C2E_LoginRequest(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time)
{
    Entry::C2E_LoginRequest req;
    req.CopyFrom(*message);
    delete message;

    LOG_INFO << "OnLogin: account = " << req.account() << ", passwd = " << req.passwd();
}