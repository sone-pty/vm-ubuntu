#pragma once

#include "noncopyable.h"
#include <pthread.h>

namespace sone
{

namespace utils
{

template <typename T> class ThreadLocal : noncopyable
{
public:
    ThreadLocal()
    {
        pthread_key_create(&key_, &ThreadLocal<T>::finalize);
    }

    ~ThreadLocal() { pthread_key_delete(key_); }

    T* Value()
    {
        T* val = static_cast<T*>(pthread_getspecific(key_));

        if(!val)
        {
            val = new T();
            pthread_setspecific(key_, val);
        }

        return val;
    }

private:
    static void finalize(void* data)
    {
        T* ptr = static_cast<T*>(data);
        delete ptr;
    }

private:
    pthread_key_t key_;
};

}

}
