#include "thread.h"
#include <assert.h>
#include <sys/syscall.h>
#include <unistd.h>

using namespace sone::utils;

namespace sone
{

namespace detail
{

pid_t gettid()
{
    return static_cast<pid_t>(::syscall(SYS_gettid));
}

struct ThreadData
{
    Thread::ThreadFunc func_;
    ThreadCallback cb_on_start_;
    ThreadCallback cb_on_stop_;

    pid_t* tid_;
    CountLatch* cl_;

    ThreadData(Thread::ThreadFunc func, ThreadCallback onStart, ThreadCallback onStop, pid_t* tid, CountLatch* cl)
    : func_(std::move(func)), cb_on_start_(std::move(onStart)), cb_on_stop_(std::move(onStop)), tid_(tid), cl_(cl) {}

    void StartThread()
    {
        *tid_ = gettid();
        cl_->CountDown();
        func_();
    }
};

void* thread_func(void* data)
{
    ThreadData* td = static_cast<ThreadData*>(data);
    if(td->cb_on_start_) td->cb_on_start_();    
    td->StartThread();
    if(td->cb_on_stop_) td->cb_on_stop_();
    delete td;
    return NULL;
}

}

}

Thread::Thread(ThreadFunc func) : 
func_(std::move(func)), cl_(1), started_(false), joined_(false)
{

}

Thread::~Thread()
{
    if(!joined_ && started_)
    {
        pthread_detach(pth_);
    }
}

int Thread::join()
{
    assert(started_ == true);
    assert(joined_ == false);
    
    joined_ = true;
    return pthread_join(pth_, NULL);
}

void Thread::start()
{
    assert(started_ == false);
    started_ = true;

    detail::ThreadData* data = new detail::ThreadData(func_, startCb_, stopCb_, &tid_, &cl_);
    int ret = pthread_create(&pth_, NULL, detail::thread_func, data);

    if(ret != 0)
    {
        // log
    }
    else
    {
        cl_.Wait();
    }
}