#pragma once

#include <stdint.h>
#include <string.h>

namespace sone
{
    namespace define
    {
        using uint8_t = unsigned char;
        using uint16_t = unsigned short;
        using uint32_t = unsigned int;
        using uint64_t = unsigned long;

        template <typename To, typename From>
        inline To implicit_cast(From const &f)
        {
            return f;
        }

        inline void memZero(void *p, size_t n)
        {
            memset(p, 0, n);
        }
    }
}