#include "worker.h"
#include "sonenet.h"
#include "service.h"

#include <iostream>

using namespace sonenet;

/// @brief 工作线程构造
/// @param processNums 每次处理的消息数目
Worker::Worker(int processNums)
    : _processNums(processNums)
{

}

/// @brief 线程执行体，处理服务的消息队列
void Worker::operator()()
{
    std::cout << "worker start" << std::endl;

    while(true)
    {
        auto srv = Sonenet::GetInstance()->PopGlobalQueue();

        if(srv == NULL)
        {
            Sonenet::GetInstance()->WorkerWait();
        }
        else
        {
            srv->ProcessMessages(_processNums);
            CheckAndPutToGlobalQueue(srv);
        }
    }
}

void Worker::CheckAndPutToGlobalQueue(std::shared_ptr<Service> srv)
{
    if(srv->IsExiting()) return;

    
}