#pragma once

#include <pthread.h>
#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <string>
#include <unordered_map>

namespace sonenet
{

class BaseMsg;
class Service;
class Worker;

class Sonenet
{
public:
    static Sonenet* GetInstance();

    // 发送消息给指定服务
    void Send(uint32_t id, std::shared_ptr<BaseMsg> msg);

    // 启动
    void Start();
    // 等待线程结束
    void Wait();

    // 服务的增删
    uint32_t NewService(const std::string& name);
    void KillService(uint32_t id); // 仅限服务自身调用

    // 全局队列增删服务
    std::shared_ptr<Service> PopGlobalQueue();
    void PushGlobalQueue(std::shared_ptr<Service> srv);

    // 线程挂起
    void WorkerWait();

    // 创建消息(测试用)
    std::shared_ptr<BaseMsg> MakeMessage(uint32_t src, const char* buf, size_t len);

private:
    Sonenet(int threadNums);
    ~Sonenet();
    Sonenet(const Sonenet&) = delete;
    void operator=(const Sonenet&) = delete;
    Sonenet(Sonenet&&) = delete;
    void operator=(Sonenet&&) = delete;

    // 开启指定数量工作线程
    void StartWorkers(int nums);
    // 查找服务
    std::shared_ptr<Service> GetService(uint32_t id);

private:
    // 单例
    static Sonenet* s_inst;
    // 工作线程
    int _workerThreadNums;
    std::vector<std::shared_ptr<std::thread>> _threads;
    std::vector<std::shared_ptr<Worker>> _workers;
    // 全局队列
    pthread_spinlock_t _globalQueueLock;
    std::queue<std::shared_ptr<Service>> _globalQueue;
    int _globalQueueLen;
    // 服务ID->对象的映射
    std::unordered_map<uint32_t, std::shared_ptr<Service>> _services;
    pthread_rwlock_t _servicesLock;
    // 动态调节线程运行
    pthread_mutex_t _sleepCountLock;
    pthread_cond_t _sleepCountCond;
    int _sleepCount;
};

}
