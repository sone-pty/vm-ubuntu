#include "list_server.h"
#include "../proto/list.pb.h"

#include <base/logging.h>
#include <base/eventLoop.h>

#include <google/protobuf/util/type_resolver.h>
#include <google/protobuf/dynamic_message.h>

using namespace sone;
using namespace sone::list;

ListServer::ListServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port)
    : BaseServer(baseLoop, ip, port, reuse_port > 0 ? kReusePort : kNoReusePort, "Entry")
{
    
}

ListServer::~ListServer()
{

}

void ListServer::DispatchMessage(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time)
{
    DISPATCH_MESSAGE(List, E2L_UploadLoading)
}

const google::protobuf::Descriptor* ListServer::GetDescriptor(int32_t type)
{
    const google::protobuf::Descriptor* descriptor;

    switch (type)
    {
        REGIST_MESSAGE(List::E2L_UPLOAD_LOADING_MESSAGE, List::E2L_UploadLoading)
        default:
            descriptor = NULL; break;
    }

    return descriptor;
}

void ListServer::On_E2L_UploadLoading(const TcpConnectionPtr& conn, google::protobuf::Message* message, Timestamp time)
{
    List::E2L_UploadLoading req;
    req.CopyFrom(*message);
    delete message;
}