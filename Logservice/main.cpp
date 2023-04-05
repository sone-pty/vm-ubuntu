#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#include <base/eventLoop.h>
#include <base/tcpserver.h>
#include <base/inetAddress.h>

using namespace sone;
using namespace sone::utils;

int main() 
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

    // 后台运行的程序代码
    EventLoop mainLoop;
    InetAddress listenAddr("127.0.0.1", 7096);
    TcpServer server(&mainLoop, listenAddr, "Logserver");
    server.start();
    mainLoop.loop();

    return 0;
}