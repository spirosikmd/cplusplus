#include "distances.h"

void checkFirstToken()
{
    char token;
    cin >> token;
    
    if (token != 'q')
        cin.unget();
    else
    {
        cout << "bye\n";
        exit(1);
    }
}