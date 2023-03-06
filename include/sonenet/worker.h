#pragma once

class Worker
{
public:
    Worker(int processNums);
    void operator()();

private:
    int _processNums;
};