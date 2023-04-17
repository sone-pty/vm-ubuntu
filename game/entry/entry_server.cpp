#include "entry_server.h"
#include "entry.pb.h"

#include <base/logging.h>
#include <base/eventLoop.h>

#include <google/protobuf/util/type_resolver.h>
#include <google/protobuf/util/type_resolver_util.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>
#include <google/protobuf/dynamic_message.h>
#include <google/protobuf/any.pb.h>

using namespace sone;
using namespace sone::entry;

using namespace google::protobuf;
using namespace google::protobuf::io;
using namespace google::protobuf::util;

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
    ArrayInputStream stream(buffer->peek(), buffer->readableBytes());
    ZeroCopyInputStream* input_stream = &stream;
    CodedInputStream coded_input(input_stream);
    Any any_message;
    uint32 message_len;

    while(buffer->readableBytes() > 0)
    {
        message_len = buffer->readInt32();

        if(!any_message.ParseFromArray(buffer->peek(), message_len))
        {
            LOG_ERROR << "proto parse from array failed, with data = [" << std::string(buffer->peek(), message_len) << "]";
            buffer->retrieve(message_len);
            continue;
        }

        DynamicMessageFactory factory;
        const Descriptor *descriptor = any_message.GetDescriptor();
        const Message *prototype = factory.GetPrototype(descriptor);
        
        if (prototype == nullptr)
        {
            LOG_ERROR << "prototype == nullptr, with data = [" << std::string(buffer->peek(), message_len) << "]";
            buffer->retrieve(message_len);
            continue;
        }

        Message* message = prototype->New();

        // 解析 Any 对象中的消息数据
        if (!any_message.UnpackTo(message))
        {
            delete message;
            buffer->retrieve(message_len);
            continue;
        }

        // 分发
        REGIST_MESSAGE(message, C2E_LoginRequest, conn, time)
    }
}

void EntryServer::On_C2E_LoginRequest(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time)
{
    Entry::C2E_LoginRequest req;
    req.CopyFrom(*message);
    delete message;

    LOG_INFO << "OnLogin";
}