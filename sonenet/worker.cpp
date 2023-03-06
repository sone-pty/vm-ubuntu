#include "worker.h"

#include <iostream>

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
}