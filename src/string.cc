#include "include/string.h"

mstd::t_size mstd::strlen(const char* str)
{
    t_size count = 0;
    while(*str)
        ++count;
    return count;
}