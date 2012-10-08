#include "profiling.h"

int main(int argc, char *argv[])
{
    size_t ntimes1 = callFun(argv[0]);
    size_t ntimes2 = callFun2(argv[0]);
            
    cout << ntimes1 << ' ' << ntimes2 << '\n';
}