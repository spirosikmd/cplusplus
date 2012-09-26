#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{ 
    for (size_t rowIdx = 0; rowIdx != pow(2, argc - 1); ++rowIdx)
    {
        cout << rowIdx + 1 << ":";
        size_t shifter = 1;
        for (int argIdx = 1; argIdx != argc; ++argIdx)
        {
            string arg = argv[argIdx];
            cout << ' ' << setw(arg.length())
                        << ((rowIdx & shifter) > 0 ? arg : "");
            shifter <<= 1;
        }
        cout << '\n';
    }
}