#include "entry_server.h"
#include "../proto/entry.pb.h"

#include <base/logging.h>
#include <base/eventLoop.h>

#include <google/protobuf/util/type_resolver.h>
#include <google/protobuf/dynamic_message.h>

using namespace sone;
using namespace sone::entry;

EntryServer::EntryServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port)
    : BaseServer(baseLoop, ip, port, reuse_port > 0 ? kReusePort : kNoReusePort, "Entry")
{
    
}

EntryServer::~EntryServer()
{

}

void EntryServer::DispatchMessage(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time)
{
    DISPATCH_MESSAGE(Entry, C2E_LoginRequest)
}

const google::protobuf::Descriptor* EntryServer::GetDescriptor(int32_t type)
{
    const google::protobuf::Descriptor* descriptor;

    switch (type)
    {
        REGIST_MESSAGE(Entry::C2E_LOGIN_MESSAGE, Entry::C2E_LoginRequest)
        default:
            descriptor = NULL; break;
    }

    return descriptor;
}

void EntryServer::On_C2E_LoginRequest(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time)
{
    Entry::C2E_LoginRequest req;
    req.CopyFrom(*message);
    delete message;

    LOG_INFO << "OnLogin: account = " << req.account() << ", passwd = " << req.passwd();
}