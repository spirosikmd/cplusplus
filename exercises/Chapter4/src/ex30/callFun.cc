#include "profiling.h"

size_t callFun(string const &prog)
{
    size_t ntimes = 0;
    for (size_t counter = 0; counter != 10000000; ++counter)
        ntimes += fun(prog);
    return ntimes;
}