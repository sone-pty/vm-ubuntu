#include "../include/base/tcpclient.h"
#include "../include/base/eventLoop.h"

#include "LogMessage.pb.h"

using namespace sone;
using namespace sone::utils;

void OnMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp time)
{
    LogMessage::LogRequest req;
    req.set_level(LogMessage::LogRequest_LOG_LEVEL_INFO);
    req.set_content("hello" + time.toString());
    std::string info;
    req.SerializeToString(&info);
    conn->send(info.c_str(), info.size());
}

int main(void)
{
    EventLoop loop;
    TcpClient client(&loop, InetAddress("127.0.0.1", 7096), "testclient");
    client.connect();
    client.setMessageCallback(std::bind(OnMessage, _1, _2, _3));
    client.setConnectionCallback([](const TcpConnectionPtr & conn)->void { OnMessage(conn, NULL, Timestamp::now()); });
    loop.loop();
    return 0;
}