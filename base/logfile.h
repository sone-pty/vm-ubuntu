#pragma once

#include "noncopyable.h"
#include "timezone.h"

#include <pthread.h>
#include <memory>
#include <string>

namespace sone
{
    namespace FileUtil
    {
        class AppendFile;
    }

    namespace utils
    {
        class LogFile : noncopyable
        {
        public:
            LogFile(const std::string &basename,
                    off_t rollSize,
                    const TimeZone& tz,
                    bool threadSafe = true,
                    int flushInterval = 3,
                    int checkEveryN = 1024);
            ~LogFile();

            void append(const char *logline, int len);
            void flush();
            bool rollFile();

        private:
            void append_unlocked(const char *logline, int len);

            std::string getLogFileName(const std::string &basename, time_t *now);

            const std::string basename_;
            const off_t rollSize_;
            const int flushInterval_;
            const int checkEveryN_;

            int count_;

            pthread_mutex_t mutex_;
            bool threadSafe_;
            time_t startOfPeriod_;
            time_t lastRoll_;
            time_t lastFlush_;
            std::unique_ptr<FileUtil::AppendFile> file_;
            TimeZone timezone_;

            const static int kRollPerSeconds_ = 60 * 60 * 24;
        };

    }

}