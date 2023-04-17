#include "logfile.h"
#include "fileutils.h"
#include "processInfo.h"

#include <assert.h>
#include <stdio.h>
#include <time.h>

using namespace sone::utils;
using namespace sone;

LogFile::LogFile(const std::string &basename,
                 off_t rollSize,
                 const TimeZone& tz,
                 bool threadSafe,
                 int flushInterval,
                 int checkEveryN)
    : basename_(basename),
      rollSize_(rollSize),
      timezone_(tz),
      threadSafe_(threadSafe),
      flushInterval_(flushInterval),
      checkEveryN_(checkEveryN),
      count_(0),
      startOfPeriod_(0),
      lastRoll_(0),
      lastFlush_(0)
{
    assert(basename.find('/') == std::string::npos);
    if(threadSafe)
    {
        pthread_mutex_init(&mutex_, NULL);
    }
    rollFile();
}

LogFile::~LogFile()
{
    if(threadSafe_)
    {
        pthread_mutex_destroy(&mutex_);
    }
}

void LogFile::append(const char *logline, int len)
{
    if (threadSafe_)
    {
        pthread_mutex_lock(&mutex_);
        append_unlocked(logline, len);
        pthread_mutex_unlock(&mutex_);
    }
    else
    {
        append_unlocked(logline, len);
    }
}

void LogFile::flush()
{
    if (threadSafe_)
    {
        pthread_mutex_lock(&mutex_);
        file_->flush();
        pthread_mutex_unlock(&mutex_);
    }
    else
    {
        file_->flush();
    }
}

void LogFile::append_unlocked(const char *logline, int len)
{
    file_->append(logline, len);

    if (file_->writtenBytes() > rollSize_)
    {
        rollFile();
    }
    else
    {
        ++count_;
        if (count_ >= checkEveryN_)
        {
            count_ = 0;
            time_t now = ::time(NULL);
            time_t thisPeriod_ = now / kRollPerSeconds_ * kRollPerSeconds_;
            if (thisPeriod_ != startOfPeriod_)
            {
                rollFile();
            }
            else if (now - lastFlush_ > flushInterval_)
            {
                lastFlush_ = now;
                file_->flush();
            }
        }
    }
}

bool LogFile::rollFile()
{
    time_t now = 0;
    std::string filename = getLogFileName(basename_, &now);
    time_t start = now / kRollPerSeconds_ * kRollPerSeconds_;

    if (now > lastRoll_)
    {
        lastRoll_ = now;
        lastFlush_ = now;
        startOfPeriod_ = start;
        file_.reset(new FileUtil::AppendFile(filename));
        return true;
    }
    return false;
}

std::string LogFile::getLogFileName(const std::string &basename, time_t *now)
{
    std::string filename;
    filename.reserve(basename.size() + 64);
    filename = basename;

    char timebuf[32];
    //struct tm tm;
    *now = time(NULL);

    // 转换时区
    struct DateTime dt;
    if (timezone_.valid())
    {
        dt = timezone_.toLocalTime(*now);
    }

    snprintf(timebuf, sizeof(timebuf), ".%4d%02d%02d-%02d:%02d:%02d.", dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.second);

    //gmtime_r(now, &tm);
    //strftime(timebuf, sizeof timebuf, ".%Y%m%d-%H%M%S.", &tm);
    filename += timebuf;

    filename += ProcessInfo::hostname();

    char pidbuf[32];
    snprintf(pidbuf, sizeof pidbuf, ".%d", ProcessInfo::pid());
    filename += pidbuf;

    filename += ".log";

    return filename;
}