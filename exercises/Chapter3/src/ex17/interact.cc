#include <iostream>
using namespace std;

enum Command
{
    QUIT='q',
    NUMBERS='n',
    MULTIPLY='*',
    INFORMATION='i'
};

int main()
{
    cout << "? ";
    
    while (true)
    {
        char ch;
        if (!cin.get(ch))
            break;
        
        switch (static_cast<int>(ch))
        {
            case Command::QUIT:
                return 0;
            case Command::NUMBERS:
            case Command::MULTIPLY:
            {
                cin >> ws;               // remove white space chars
                string restChars;
                getline(cin, restChars); // read chars after command
                cout << restChars << '\n';
                cout << "? ";
                break;
            }
            case Command::INFORMATION:
            {
                cout << "i\n";
                break;
            }
            case '\n':
            {
                cout << "? ";
                break;
            }
            case ' ':
                break;
            default:
            {
                cout << "ignoring " << ch << '\n';
                break;
            }
        }
    }
}