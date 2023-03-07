#include "service.h"

std::atomic_uint32_t Service::s_base_id(1);

Service::Service()
    : isExiting(false)
{

}

void Service::OnInit()
{

}

void Service::OnExit()
{
    isExiting = true;
}

void Service::OnMessage()
{

}