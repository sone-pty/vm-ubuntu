#pragma once

namespace sonenet
{

enum MSG_TYPE
{
    SERVICE_MSG = 1, // 服务间消息
    INVALID_MSG
};

class BaseMsg
{
public:
    BaseMsg() = default;
    virtual ~BaseMsg() = default;

private:
    unsigned char _type;
};

class ServiceMsg : public BaseMsg
{
    
};

}