#pragma once

#include "IDisposeable.h"

namespace sone
{
    namespace libserver
    {
        class ThreadObject : public IDisposeable
        {
        public:
            virtual void Init() = 0;
            virtual void Update() = 0;

            void Dispose() override;
        };
    }
}