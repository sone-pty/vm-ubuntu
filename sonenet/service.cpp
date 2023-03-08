#include "service.h"
#include "msg.h"
#include "sonenet.h"

#include <iostream>

using namespace sonenet;
using namespace sonenet::define;

std::atomic_uint32_t Service::s_base_id(1);

Service::Service()
    : _isExiting(false), _isInGlobalQue(false)
{
    pthread_spin_init(&_msgQueueLock, PTHREAD_PROCESS_PRIVATE);
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
            std::cout << "this is " << _id << ", from: " << T->_sourceId << ", msg: " << T->_msg << std::endl;
            Sonenet::GetInstance()->Send(T->_sourceId, Sonenet::GetInstance()->MakeMessage(_id, "response", 8));
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
        auto T = std::static_pointer_cast<ServiceMsg>(msg);
        _msgQueue.push(msg);
        std::cout << T->_sourceId << ", " << T->_msg << ", " << _msgQueue.size() << std::endl;
    }
    pthread_spin_unlock(&_msgQueueLock);
    std::cout << "after push" << std::endl;
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

/// @brief 检查消息队列
/// @return true/false: 空返回false, 不空返回true
bool Service::CheckMessageQueue()
{
    pthread_spin_lock(&_msgQueueLock);
    {
        if(_msgQueue.empty())
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    pthread_spin_unlock(&_msgQueueLock);
}