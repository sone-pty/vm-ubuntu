#pragma once

#include <memory>


namespace sone
{

class Service;

class Worker
{
public:
    Worker(int processNums);
    void operator()();

private:
    void CheckAndPutToGlobalQueue(std::shared_ptr<Service> srv);

private:
    int _processNums;
};

}