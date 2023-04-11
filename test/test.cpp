#include <base/tcpclient.h>
#include <base/eventLoop.h>
#include <base/buffer.h>
#include <base/logging.h>

#include <unistd.h>

#include "LogMessage.pb.h"

using namespace sone;
using namespace sone::utils;

void OnMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp time)
{
    LogMessage::LogRequest req;
    req.set_level(LogMessage::LogRequest_LOG_LEVEL_INFO);
    req.set_content("send log req on " + time.toString() + ", in the conn: " + conn->name());

    Buffer info;
    std::string msg;
    req.SerializeToString(&msg);
    info.append(msg.c_str(), msg.size());
    // 添加消息长度前缀
    uint32_t messageLen = static_cast<uint32_t>(info.readableBytes());
    info.prependInt32(messageLen);

    conn->send(&info);
}

int main(void)
{
    EventLoop loop;
    InetAddress serverAddr("127.0.0.1", 7096);

    for(int i = 0; i < 100; ++i)
    {
        TcpClient* client = new TcpClient(&loop, serverAddr, "testclient_" + std::to_string(i));
        client->connect();
        client->setMessageCallback(std::bind(OnMessage, _1, _2, _3));
        client->setConnectionCallback([](const TcpConnectionPtr & conn)->void { OnMessage(conn, NULL, Timestamp::now()); });
    }
    
    loop.loop();
    return 0;
}