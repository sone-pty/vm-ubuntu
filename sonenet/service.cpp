#include "service.h"
#include "msg.h"

#include <iostream>

using namespace sonenet;
using namespace sonenet::define;

std::atomic_uint32_t Service::s_base_id(1);

Service::Service()
    : _isExiting(false)
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
    _isExiting = true;
}

void Service::OnMessage(std::weak_ptr<BaseMsg> wMsg)
{
    const std::shared_ptr<BaseMsg>& msg = wMsg.lock();
    if(msg == NULL) return;

    switch(msg->GetType())
    {
        case MSG_TYPE::SERVICE_MSG:
        {
            auto T = std::static_pointer_cast<ServiceMsg>(msg);
            // test
            std::cout << "SRC_ID: " << T->_sourceId << ", msg: " << T->_msg << std::endl;
        }break;
        default: break;
    }
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
        OnMessage(msg);
    }

    return true;
}