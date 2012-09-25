#include <iostream>
using namespace std;

enum Commands
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
            case Commands::QUIT:
                return 0;
            case Commands::NUMBERS:
            case Commands::MULTIPLY:
            {
                cin >> ws;
                string restChars;
                getline(cin, restChars);
                cout << restChars << '\n';
                cout << "? ";
                break;
            }
            case Commands::INFORMATION:
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