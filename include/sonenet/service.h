#pragma once

#include <string>
#include <atomic>
#include <queue>
#include <pthread.h>
#include <memory>

#include "define.h"

namespace sonenet
{
    using namespace define;

class BaseMsg;

class Service
{
public:
    Service();
    ~Service();

    // 用于创建服务对象
    static std::atomic_uint32_t s_base_id;
    
    // getter && setter
    void SetName(const std::string& name) { _name = name; }
    std::string GetName() const { return _name; }
    void SetID(uint32_t id) { _id = id; }
    uint32_t GetID() const { return _id; }

    bool IsExiting() const { return _isExiting; }

    // 逻辑回调
    void OnInit();
    void OnExit();
    void OnMessage(std::weak_ptr<BaseMsg> wMsg);

    // 消息入队
    void PushMsgQueue(std::shared_ptr<BaseMsg> msg);
    // 处理指定数量消息
    bool ProcessMessages(size_t nums);

    // 检查自己的消息队列
    bool CheckMessageQueue();

private:
    // 弹出一条消息
    std::shared_ptr<BaseMsg> PopMsgQueue();

private:
    // 服务名称
    std::string _name;
    // 服务ID
    uint32_t _id;
    // 是否正在退出
    bool _isExiting;

    // 服务的消息队列
    std::queue<std::shared_ptr<BaseMsg>> _msgQueue;
    pthread_spinlock_t _msgQueueLock;

public:
    // 是否在全局队列中
    std::atomic_bool _isInGlobalQue;
};

}