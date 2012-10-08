#include "profiling.h"

size_t callFun2(string const &prog)
{
    size_t ntimes = 0;
    for (size_t counter = 0; counter != 10000000; ++counter)
        ntimes += fun2(prog);
    return ntimes;
}