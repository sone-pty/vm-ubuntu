/* system headers */
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <algorithm>
#include <future>
#include <mutex>
#include <condition_variable>
#include <ctime>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* private headers */
#include <utils/redis.h>
#include <utils/threadLocal.h>
#include <ds/ds.h>

/* sonenet */
#include <sonenet/sonenet.h>
#include <sonenet/service.h>

/* extern headers */
#include <http_parser/http_parser.h>
#include <json11/json11.hpp>

using namespace json11;
using namespace sone::utils;

class Test
{
public:
	Test() = default;

	operator int() { return 1; }

	void X(int i) 
	{
		std::lock_guard<std::mutex> lg(_mtx);
		std::cout << "hello " << i << std::endl; 
	}

	void XX() 
	{ 
		std::lock_guard<std::mutex> lg(_mtx);
		std::cout << "world" << std::endl; 
	}

	int XXX(int i) 
	{ 
		std::lock_guard<std::mutex> lg(_mtx);
		return i + 10;
	}

private:
	std::mutex _mtx;
};

template <typename RandomIter> int Parallel_Sum(const RandomIter& beg, const RandomIter& end)
{
	int sum = 0;

	if(end - beg < 1000)
	{
		for(auto iter = beg; iter != end; ++iter)
		{
			sum += *iter;
		}
	}
	else
	{
		RandomIter mid = beg + (end - beg) / 2;
		std::future<int> res = std::async(std::launch::async, Parallel_Sum<RandomIter>, mid, end);
		
		for(auto iter = beg; iter != mid; ++iter)
		{
			sum += *iter;
		}

		sum += res.get();
	}

	return sum;
}

void test() {
    uint32_t ping1 = sone::Sonenet::GetInstance()->NewService("ping");
    uint32_t ping2 = sone::Sonenet::GetInstance()->NewService("ping");
    uint32_t pong = sone::Sonenet::GetInstance()->NewService("pong");

	auto msg1 = sone::Sonenet::GetInstance()->MakeMessage(ping1, "hi", 2);
	auto msg2 = sone::Sonenet::GetInstance()->MakeMessage(ping2, "hello", 5);

	sone::Sonenet::GetInstance()->Send(pong, msg1);
	sone::Sonenet::GetInstance()->Send(pong, msg2);
}

int main(void)
{
/* 	clock_t start = ::clock();
	std::vector<int> lst(10000, 1);
	int res = Parallel_Sum(lst.begin(), lst.end());
	clock_t end = ::clock();
	std::cout << "sum: " << res << ", cost: " << (end - start) << "ticks" << std::endl;

	Test t;
	int num = 10;
	std::async(&Test::X, &t, num);
	auto a2 = std::async(std::launch::deferred, &Test::XX, &t);
	auto a3 = std::async(std::launch::async, &Test::XXX, &t, num);
	a2.wait();
	std::cout << "XXX(), num = " << a3.get() << std::endl; */

/* 	sone::Sonenet::GetInstance()->Start();
	sleep(3);
	test();
	sone::Sonenet::GetInstance()->Wait(); */

	ThreadLocal<int> tl1;
	std::thread t1([&tl1]()->void{ while(1) { *(tl1.Value()) = 2; std::cout << "t1: " << *(tl1.Value()) << std::endl; sleep(1); } });
	std::thread t2([&tl1]()->void{ while(1) { *(tl1.Value()) = 3; std::cout << "t2: " << *(tl1.Value()) << std::endl; sleep(1); } });

	t1.join();
	t2.join();
    return 0;
}