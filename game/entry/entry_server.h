#pragma once

#include <base/tcpserver.h>

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
        };
    }
}