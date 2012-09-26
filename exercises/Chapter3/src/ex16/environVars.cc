#include <iostream>
#include <string>
using namespace std;

extern char **environ;

int main()
{
    size_t i = 0;
    while (true)
    {
        if (not environ[i])
            break;
        
        string variable = environ[i];
        variable.replace(variable.find('='), 1, "' has value `");
        cout << "Variable `" << variable << "'.\n";
        ++i;
    }
}