#include "sonenet.h"
#include "msg.h"
#include "worker.h"
#include "service.h"

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
        _threads.emplace_back(new std::thread(Worker(2 << i)));
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
}

/// @brief 发送消息给具体服务
/// @param id dest服务ID
/// @param msg 消息
void Sonenet::Send(unsigned int id, BaseMsg* msg)
{

}

void Sonenet::Start()
{
    pthread_spin_init(&_globalQueueLock, 0);
    pthread_rwlock_init(&_servicesLock, NULL);

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
    std::shared_ptr<Service> srv;
    pthread_spin_lock(&_globalQueueLock);
    {
        if(!_globalQueue.empty())
        {
            srv = _globalQueue.front();
            _globalQueue.pop();
            --_globalQueueLen;
        }
    }
    pthread_spin_unlock(&_globalQueueLock);

    return srv;
}

void Sonenet::PushGlobalQueue(std::shared_ptr<Service> srv)
{
    pthread_spin_lock(&_globalQueueLock);
    {
        _globalQueue.push(srv);
        ++_globalQueueLen;
    }
    pthread_spin_unlock(&_globalQueueLock);
}