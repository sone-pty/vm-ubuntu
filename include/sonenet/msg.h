#pragma once

#include <memory>
#include "define.h"

namespace sone
{
    using namespace define;

enum MSG_TYPE
{
    INVALID_MIN_MSG       = 0,
    SERVICE_MSG           = 1, // 服务间消息
    INVALID_MAX_MSG,
    ERROR_MSG             = 255
};

class BaseMsg
{
public:
    BaseMsg(MSG_TYPE type) : _type(type) {} 
    virtual ~BaseMsg() = default;

public:
    uint8_t GetType() const { return _type; }
    void SetType(uint8_t type)
    {
        if(type < MSG_TYPE::INVALID_MAX_MSG && type > MSG_TYPE::INVALID_MIN_MSG)
        {
            _type = type;
        }
        else
        {
            _type = MSG_TYPE::ERROR_MSG;
        }
    }

private:
    uint8_t _type;
};

class ServiceMsg : public BaseMsg
{
public:
    ServiceMsg() : BaseMsg(MSG_TYPE::SERVICE_MSG) {}
    virtual ~ServiceMsg() override {}

public:
    uint32_t _sourceId;
    std::shared_ptr<char> _msg;
    size_t _len;
};

}