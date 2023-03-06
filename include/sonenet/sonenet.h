#pragma once

#include <pthread.h>
#include <vector>
#include <memory>
#include <thread>

class BaseMsg;

class Sonenet
{
public:
    static Sonenet* GetInstance();

    // 开启nums条工作线程
    void Start(int nums);
    // 关闭
    void Exit();
    // 发送消息给指定服务
    void Send(unsigned int id, BaseMsg* msg);

private:
    Sonenet() = default;
    ~Sonenet();
    Sonenet(const Sonenet&) = delete;
    void operator=(const Sonenet&) = delete;
    Sonenet(Sonenet&&) = delete;
    void operator=(Sonenet&&) = delete;

private:
    static Sonenet* s_inst;
    std::vector<std::shared_ptr<std::thread>> _threads;
};