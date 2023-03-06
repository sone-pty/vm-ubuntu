/* system headers */
#include <iostream>
#include <vector>
#include <string>
#include <thread>

#include <pthread.h>
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
    return 0;
}