#include "system.hpp"
#include <unistd.h>

namespace System
{
    bool isSuperUser()
    {
        return getuid() == 0;
    }
}
