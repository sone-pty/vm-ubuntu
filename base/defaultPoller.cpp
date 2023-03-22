#include "basepoller.h"
#include "epollPoller.h"

#include <stdlib.h>

using namespace sone::utils;

Poller *Poller::newDefaultPoller(EventLoop *loop)
{
    if (::getenv("MUDUO_USE_POLL"))
    {
        //return new PollPoller(loop);
    }
    else
    {
        return new EPollPoller(loop);
    }
}