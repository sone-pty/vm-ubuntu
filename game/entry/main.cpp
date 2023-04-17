#include <base/asyncLogger.h>
#include <base/logging.h>
#include <base/timezone.h>
#include <base/eventLoop.h>
#include <extern/json11/json11.hpp>

#include "entry_server.h"

#include <unistd.h>
#include <fstream>

using namespace sone;
using namespace sone::utils;

off_t kRollSize = 500 * 1000 * 1000;
AsyncLogging *g_asyncLog = NULL;

void asyncOutput(const char *msg, int len)
{
	g_asyncLog->append(msg, len);
}

struct ServerConfig
{
	std::string ip;
	unsigned short port;
	unsigned short reusePort;
	unsigned short threadNums;

	bool ReadConfig()
	{
		std::ifstream file("Entry.json");
		if (!file.is_open())
		{
			LOG_ERROR << "read config file failed";
			return false;
		}

		std::string json_str((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
		std::string err;
		auto json = json11::Json::parse(json_str, err);

		if(err.empty() && json.is_object())
		{
			const std::map<std::string, json11::Json> & items = json.object_items();
			std::map<std::string, json11::Json>::const_iterator iter;

			if((iter = items.find("ip")) != items.end() && iter->second.is_string())
			{
				ip = iter->second.string_value();
			}

			if((iter = items.find("port")) != items.end() && iter->second.is_number())
			{
				port = iter->second.int_value();
			}

			if((iter = items.find("reusePort")) != items.end() && iter->second.is_number())
			{
				reusePort = iter->second.int_value();
			}

			if((iter = items.find("threadNums")) != items.end() && iter->second.is_number())
			{
				threadNums = iter->second.int_value();
			}
		}
		else
		{
			LOG_ERROR << "parse config json failed";
			return false;
		}

		LOG_INFO << "Read Config succ; IP: " << ip
				 << ", port: " << port
				 << ", reusePort: " << reusePort
				 << ", threadNums: " << threadNums;
		return true;
	}
};

ServerConfig g_config;

int main(int argc, char *argv[])
{
	pid_t pid = fork();

    if (pid < 0) 
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    } 
    else if (pid > 0) 
    {
        // 父进程退出
        exit(EXIT_SUCCESS);
    }

    // 子进程调用setsid()函数
    if (setsid() < 0) 
    {
        perror("setsid error");
        exit(EXIT_FAILURE);
    }

	// 日志线程
	Logger::setOutput(asyncOutput);
	Logger::setTimeZone(TimeZone::China());
	char name[256] = {'\0'};
	strncpy(name, argv[0], sizeof name - 1);
	AsyncLogging log(::basename(name), kRollSize);
	g_asyncLog = &log;
	log.start();
	LOG_INFO << "LOGGER STARTED";

	// 事件循环
	g_config.ReadConfig();
	EventLoop mainLoop;
	entry::EntryServer server(&mainLoop, g_config.ip, g_config.port, g_config.reusePort);
	server.setThreadNum(g_config.threadNums);
	server.start();
	mainLoop.loop();

	return 0;
}