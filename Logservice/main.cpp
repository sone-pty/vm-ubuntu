#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <base/eventLoop.h>
#include <base/tcpserver.h>
#include <base/inetAddress.h>
#include <base/callback.h>
#include <base/logging.h>
#include <base/asyncLogger.h>
#include <base/timezone.h>

#include "LogMessage.pb.h"

using namespace sone;
using namespace sone::utils;

off_t kRollSize = 500 * 1000 * 1000;
AsyncLogging *g_asyncLog = NULL;

void asyncOutput(const char *msg, int len)
{
	g_asyncLog->append(msg, len);
}

void OnMessage(const TcpConnectionPtr& conn, Buffer* buf, Timestamp time)
{
    LogMessage::LogRequest req;
    uint32_t messageLen;
    std::string info;
    Buffer resp;
    bool ret = false;

    while(buf->readableBytes() > 0)
    {
        messageLen = buf->readInt32();

        if(messageLen > 0)
        {
            ret = req.ParseFromArray(buf->peek(), messageLen);
        }

        if(ret)
        {
            buf->retrieve(messageLen);

            switch (req.level())
            {
            case LogMessage::LogRequest_LOG_LEVEL::LogRequest_LOG_LEVEL_TRACE:
                LOG_TRACE << req.content();
                break;
            case LogMessage::LogRequest_LOG_LEVEL::LogRequest_LOG_LEVEL_DEBUG:
                LOG_DEBUG << req.content();
                break;
            case LogMessage::LogRequest_LOG_LEVEL::LogRequest_LOG_LEVEL_INFO:
                LOG_INFO << req.content();
                break;
            case LogMessage::LogRequest_LOG_LEVEL::LogRequest_LOG_LEVEL_WARN:
                LOG_WARN << req.content();
                break;
            case LogMessage::LogRequest_LOG_LEVEL::LogRequest_LOG_LEVEL_ERROR:
                LOG_ERROR << req.content();
                break;
            case LogMessage::LogRequest_LOG_LEVEL::LogRequest_LOG_LEVEL_FATAL:
                LOG_FATAL << req.content();
                break;
            default:
                LOG_INFO << req.content();
                break;
            }

            info = "Log succ";
        }
        else
        {
            break;
            info = "parse error";
        }
    }

    resp.append(info.c_str(), info.size());
    conn->send(&resp);
}

int main(int argc, char *argv[]) 
{
    pid_t pid = fork();

    if (pid < 0) 
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    } 
    else if (pid > 0) 
    {
        // 父进程退出
        exit(EXIT_SUCCESS);
    }

    // 子进程调用setsid()函数
    if (setsid() < 0) 
    {
        perror("setsid error");
        exit(EXIT_FAILURE);
    }

    // 日志线程
	Logger::setOutput(asyncOutput);
	Logger::setTimeZone(TimeZone::China());
	char name[256] = {'\0'};
	strncpy(name, argv[0], sizeof name - 1);
	AsyncLogging log(::basename(name), kRollSize);
	g_asyncLog = &log;
	log.start();
	LOG_INFO << "LOGGER STARTED";

    EventLoop mainLoop;
    InetAddress listenAddr("127.0.0.1", 7096);
    TcpServer server(&mainLoop, listenAddr, "Logserver");
    server.setMessageCallback(std::bind(OnMessage, _1, _2, _3));
    server.start();
    mainLoop.loop();

    return 0;
}