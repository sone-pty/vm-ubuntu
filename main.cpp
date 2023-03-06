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
#include <utils/random.h>
#include <utils/redis.h>

#include <ds/ds.h>

/* extern headers */
#include <http_parser/http_parser.h>
#include <json11/json11.hpp>

using namespace json11;

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

int main(void)
{
    //http_parser parser;
    //http_parser_init(&parser, HTTP_REQUEST);

	/*
    Redis* r = new Redis();
	if(!r->connect("127.0.0.1", 6379))
	{
		printf("connect error!\n");
		return 0;
	}
	r->set("name", "Mayuyu");
	printf("Get the name is %s\n", r->get("name").c_str());
	delete r;
	*/

	/////////////////////// Parallel_Sum /////////////////////////////
	clock_t start = ::clock();
	std::vector<int> lst(100000000, 1);
	int res = Parallel_Sum(lst.begin(), lst.end());
	clock_t end = ::clock();
	std::cout << "sum: " << res << ", cost: " << (end - start) << "ticks" << std::endl;

	Test t;
	int num = 10;
	std::async(&Test::X, &t, num);
	auto a2 = std::async(std::launch::deferred, &Test::XX, &t);
	auto a3 = std::async(std::launch::async, &Test::XXX, &t, num);
	a2.wait();
	std::cout << "XXX(), num = " << a3.get() << std::endl;

    return 0;
}