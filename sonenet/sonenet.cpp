#include "sonenet.h"
#include "msg.h"
#include "worker.h"
#include "service.h"

#include <iostream>
#include <string.h>

using namespace sonenet;
using namespace sonenet::define;

Sonenet* Sonenet::s_inst = NULL;

/// @brief 单例接口
/// @return 单例对象
Sonenet* Sonenet::GetInstance()
{
    if(s_inst == NULL)
    {
        s_inst = new Sonenet(3);
    }

    return s_inst;
}

Sonenet::Sonenet(int threadNums)
    : _workerThreadNums(threadNums), _globalQueueLen(0)
{

}

Sonenet::~Sonenet()
{

}

/// @brief 开启指定数目线程
/// @param nums 线程数
void Sonenet::StartWorkers(int nums)
{
    if(nums <= 0) return;

    for(int i = 0;i < nums; ++i)
    {
        auto worker = std::make_shared<Worker>(2 << i);
        _workers.push_back(worker);
        _threads.push_back(std::make_shared<std::thread>(*worker));
    }
}

/// @brief 关闭服务中心
void Sonenet::Wait()
{
    for(size_t i = 0; i < _threads.size(); ++i)
    {
        _threads[i]->join();
    }

    pthread_spin_destroy(&_globalQueueLock);
    pthread_rwlock_destroy(&_servicesLock);
    pthread_mutex_destroy(&_sleepCountLock);
    pthread_cond_destroy(&_sleepCountCond);
}

/// @brief 发送消息给具体服务
/// @param dest dest服务ID
/// @param msg 消息
void Sonenet::Send(uint32_t dest, std::shared_ptr<BaseMsg> msg)
{
    auto srv = GetService(dest);
    if(srv == NULL || msg == NULL) return;

    // 消息入队
    srv->PushMsgQueue(msg);
    // 进入全局队列
    PushGlobalQueue(srv);

    // 尝试唤醒线程(非线程安全)
    if (_sleepCount == 0)
        return;
    if (_workerThreadNums - _sleepCount <= _globalQueue.size())
    {
        std::cout << "wake up thread" << std::endl;
        pthread_cond_signal(&_sleepCountCond);
    }
}

void Sonenet::Start()
{
    pthread_spin_init(&_globalQueueLock, 0);
    pthread_rwlock_init(&_servicesLock, NULL);
    pthread_mutex_init(&_sleepCountLock, NULL);
    pthread_cond_init(&_sleepCountCond, NULL);

    StartWorkers(_workerThreadNums);
}

uint32_t Sonenet::NewService(const std::string& name)
{
    auto srv = std::make_shared<Service>();

    srv->SetName(name);
    srv->SetID(Service::s_base_id++);

    pthread_rwlock_wrlock(&_servicesLock);
    {
        _services[srv->GetID()] = srv;
    }
    pthread_rwlock_unlock(&_servicesLock);

    srv->OnInit();
    return srv->GetID();
}

void Sonenet::KillService(uint32_t id)
{
    auto srv = GetService(id);

    pthread_rwlock_wrlock(&_servicesLock);
    {
        _services.erase(id);
    }
    pthread_rwlock_unlock(&_servicesLock);

    if(srv)
    {
        // 非线程安全
        srv->OnExit();
    }
}

std::shared_ptr<Service> Sonenet::GetService(uint32_t id)
{
    std::shared_ptr<Service> srv;
    pthread_rwlock_rdlock(&_servicesLock);
    {
        srv = _services[id];
    }
    pthread_rwlock_unlock(&_servicesLock);

    return srv;
}

std::shared_ptr<Service> Sonenet::PopGlobalQueue()
{
    std::shared_ptr<Service> srv = NULL;
    pthread_spin_lock(&_globalQueueLock);
    {
        if(!_globalQueue.empty())
        {
            srv = _globalQueue.front();
            _globalQueue.pop();
            --_globalQueueLen;
            srv->_isInGlobalQue = false;
        }
    }
    pthread_spin_unlock(&_globalQueueLock);

    return srv;
}

void Sonenet::PushGlobalQueue(std::shared_ptr<Service> srv)
{
    pthread_spin_lock(&_globalQueueLock);
    {
        if(!srv->_isInGlobalQue)
        {
            _globalQueue.push(srv);
            srv->_isInGlobalQue = true;
            ++_globalQueueLen;
        }
    }
    pthread_spin_unlock(&_globalQueueLock);
}

void Sonenet::WorkerWait()
{
    pthread_mutex_lock(&_sleepCountLock);
    ++_sleepCount;
    pthread_cond_wait(&_sleepCountCond, &_sleepCountLock);
    --_sleepCount;
    pthread_mutex_unlock(&_sleepCountLock);
}

std::shared_ptr<BaseMsg> Sonenet::MakeMessage(uint32_t src, const char *buf, size_t len)
{
    char* str = new char[len + 1];
    memcpy(str, buf, len);
    str[len] = 0;

    auto msg = std::make_shared<ServiceMsg>();
    msg->_len = len;
    msg->_sourceId = src;
    msg->_msg = std::shared_ptr<char>(str);
    return msg;
}