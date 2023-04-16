#pragma once

namespace sone
{
    namespace libserver
    {
        class IDisposeable
        {
        public:
            virtual ~IDisposeable() = 0;
            virtual void Dispose() = 0;
        };
    }
}