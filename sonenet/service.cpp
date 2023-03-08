#include "service.h"

using namespace sonenet;
using namespace sonenet::define;

std::atomic_uint32_t Service::s_base_id(1);

Service::Service()
    : isExiting(false)
{
    pthread_spin_init(&_msgQueueLock, 0);
}

Service::~Service()
{
    pthread_spin_destroy(&_msgQueueLock);
}

void Service::OnInit()
{

}

void Service::OnExit()
{
    isExiting = true;
}

void Service::OnMessage()
{

}

std::shared_ptr<BaseMsg> Service::PopMsgQueue()
{
    std::shared_ptr<BaseMsg> msg = NULL;

    pthread_spin_lock(&_msgQueueLock);
    {
        msg = _msgQueue.front();
        _msgQueue.pop();
    }
    pthread_spin_unlock(&_msgQueueLock);

    return msg;
}

void Service::PushMsgQueue(std::shared_ptr<BaseMsg> msg)
{
    pthread_spin_lock(&_msgQueueLock);
    {
        _msgQueue.push(msg);
    }
    pthread_spin_unlock(&_msgQueueLock);
}

bool Service::ProcessMessages(size_t nums)
{
    for(size_t i = 0;i < nums; ++i)
    {
        const auto& msg = PopMsgQueue();
        
    }

    return true;
}