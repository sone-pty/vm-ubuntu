#include "sonenet.h"
#include "base_msg.h"
#include "worker.h"

Sonenet* Sonenet::s_inst = NULL;

/// @brief 单例接口
/// @return 单例对象
Sonenet* Sonenet::GetInstance()
{
    if(s_inst == NULL)
    {
        s_inst = new Sonenet();
    }

    return s_inst;
}

Sonenet::~Sonenet()
{

}

/// @brief 开启指定数目线程
/// @param nums 线程数
void Sonenet::Start(int nums)
{
    if(nums <= 0) return;

    for(int i = 0;i < nums; ++i)
    {
        _threads.emplace_back(new std::thread(Worker(2 << i)));
    }
}

/// @brief 关闭服务管理
void Sonenet::Exit()
{
    for(int i = 0; i < _threads.size(); ++i)
    {
        _threads[i]->join();
    }
}

/// @brief 发送消息给具体服务
/// @param id 服务源ID
/// @param msg 消息
void Sonenet::Send(unsigned int id, BaseMsg* msg)
{

}