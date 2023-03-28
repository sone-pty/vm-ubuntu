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
#include <base/threadLocal.h>
#include <base/threadPool.h>
#include <base/eventLoop.h>
#include <base/blockqueue.h>
#include <base/asyncLogger.h>
#include <base/logging.h>

/* sonenet */
#include <sonenet/sonenet.h>
#include <sonenet/service.h>

/* extern headers */
#include <http_parser/http_parser.h>
#include <json11/json11.hpp>

using namespace json11;
using namespace sone::utils;

off_t kRollSize = 500 * 1000 * 1000;
AsyncLogging *g_asyncLog = NULL;

void asyncOutput(const char *msg, int len)
{
	g_asyncLog->append(msg, len);
}

int main(int argc, char *argv[])
{
	// 日志线程
	char name[256] = {'\0'};
	strncpy(name, argv[0], sizeof name - 1);
	AsyncLogging log(::basename(name), kRollSize);
	log.start();
	g_asyncLog = &log;
	Logger::setOutput(asyncOutput);
	// 事件循环线程
	return 0;
}