#include "GameThread.h"
#include "ThreadObject.h"

using namespace sone;
using namespace sone::libserver;

GameThread::GameThread() 
    : run_(false), thread_(std::bind(&GameThread::run, this))
{
    pthread_mutex_init(&mtx_, NULL);
}

void GameThread::Dispose()
{
    pthread_mutex_destroy(&mtx_);
}

void GameThread::run()
{
    std::vector<std::unique_ptr<ThreadObject>> temp_;

    while(run_)
    {
        pthread_mutex_lock(&mtx_);
        temp_.swap(objects_);
        pthread_mutex_unlock(&mtx_);

        for(int i = 0; i < temp_.size(); ++i)
        {
            temp_[i]->Update();
        }
    }
}

void GameThread::AddObejct(std::unique_ptr<ThreadObject> obj)
{
    pthread_mutex_lock(&mtx_);
    objects_.push_back(std::move(obj));
    pthread_mutex_unlock(&mtx_);
}

void GameThread::Start()
{
    run_ = true;
    thread_.start();
}

void GameThread::Stop()
{
    run_ = false;
    thread_.join();
}