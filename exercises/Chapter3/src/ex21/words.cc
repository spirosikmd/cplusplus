#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        cout << "Provide max line length as arg. 1, "
                "and input text on stdin\n";
        return 1;
    }
}