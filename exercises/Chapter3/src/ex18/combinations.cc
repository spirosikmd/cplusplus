#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
    for (size_t rowIdx = 0; rowIdx != pow(2, argc - 1); ++rowIdx)
    {
        cout << rowIdx + 1 << ':';
        size_t mask = 1;
        for (int argIdx = 1; argIdx != argc; ++argIdx)
        {
            string arg = argv[argIdx];
            
            // Ensure that at least `arg length' chars will be printed
            // This will produce the white space chars if the arg 
            // should not be shown.
            cout << ' ' << setw(arg.length());
            // Show the arg only if the the position that the mask
            // indicates is greater than 0.
            cout << ((rowIdx & mask) > 0 ? arg : "");
            
            // Shift mask to indicate the next position.
            mask <<= 1;
        }        
        cout << '\n';
    }
}