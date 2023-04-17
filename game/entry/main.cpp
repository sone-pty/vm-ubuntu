#include <base/asyncLogger.h>
#include <base/logging.h>
#include <base/timezone.h>

#include <unistd.h>

using namespace sone::utils;

off_t kRollSize = 500 * 1000 * 1000;
AsyncLogging *g_asyncLog = NULL;

void asyncOutput(const char *msg, int len)
{
	g_asyncLog->append(msg, len);
}

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
	// 事件循环线程
	sleep(1);
	return 0;
}