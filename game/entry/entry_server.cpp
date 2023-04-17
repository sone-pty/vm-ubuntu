#include "entry_server.h"

#include <base/eventLoop.h>

using namespace sone;
using namespace sone::entry;

EntryServer::EntryServer(EventLoop* baseLoop, const std::string& ip, unsigned short port, int reuse_port)
    : TcpServer(baseLoop, InetAddress(ip, port), "Entry", reuse_port > 0 ? kReusePort : kNoReusePort)
{
    
}

EntryServer::~EntryServer()
{

}