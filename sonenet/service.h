#pragma once

#include <string>
#include <atomic>

class Service
{
public:
    Service();

    // 用于创建服务对象
    static std::atomic_uint32_t s_base_id;
    
    void SetName(const std::string& name) { _name = std::move(name); }
    std::string GetName() const { return _name; }

    void SetID(uint32_t id) { _id = id; }
    uint32_t GetID() const { return _id; }

    void OnInit();
    void OnExit();
    void OnMessage();

private:
    std::string _name;
    uint32_t _id;
    bool isExiting;
};