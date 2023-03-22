#pragma once

#include <stdint.h>
#include <string>

namespace sone
{
    namespace CurrentThread
    {
        // internal
        extern __thread int t_cachedTid;
        void cacheTid();

        inline int tid()
        {
            /*
                if (__builtin_expect (x > 0, 1)) {
                    // 分支1
                } else {
                    // 分支2
                }
                这段代码表示，如果x > 0的概率很高（即分支1的期望概率为1），则执行分支1，否则执行分支2。
                在生成代码时，编译器会根据这个信息来优化生成的代码，比如将分支1的代码放到跳转目标地址的前面，从而提高程序的性能。
                需要注意的是，__builtin_expect并不会改变程序的行为，而只是用于告诉编译器分支的执行概率。
                因此，在使用这个函数时，需要保证分支的期望概率和实际概率尽可能接近，否则会导致性能下降。
            */
            if (__builtin_expect(t_cachedTid == 0, 0))
            {
                cacheTid();
            }
            return t_cachedTid;
        }

        bool isMainThread();
        
        void sleepUsec(int64_t usec); // for testing

        std::string stackTrace(bool demangle);
    } // namespace CurrentThread
}