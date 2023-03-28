#pragma once

#include "timestamp.h"

#include <vector>
#include <sys/types.h>

namespace sone
{
    namespace ProcessInfo
    {
        pid_t pid();
        std::string pidString();
        uid_t uid();
        std::string username();
        uid_t euid();
        utils::Timestamp startTime();
        int clockTicksPerSecond();
        int pageSize();
        bool isDebugBuild(); // constexpr

        std::string hostname();
        std::string procname();

        /// read /proc/self/status
        std::string procStatus();

        /// read /proc/self/stat
        std::string procStat();

        /// read /proc/self/task/tid/stat
        std::string threadStat();

        /// readlink /proc/self/exe
        std::string exePath();

        int openedFiles();
        int maxOpenFiles();

        struct CpuTime
        {
            double userSeconds;
            double systemSeconds;

            CpuTime() : userSeconds(0.0), systemSeconds(0.0) {}

            double total() const { return userSeconds + systemSeconds; }
        };
        CpuTime cpuTime();

        int numThreads();
        std::vector<pid_t> threads();
    } // namespace ProcessInfo

}