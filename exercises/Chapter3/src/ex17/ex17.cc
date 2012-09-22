#include <iostream>
using namespace std;

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
            case 'q':
                return 0;
            case '*':
            {
                string restChars;
                cin >> ws;
                getline(cin, restChars);
                cout << restChars << '\n';
                cout << "? ";
            }
            break;
            case 'n':
            {
                string restChars;
                cin >> ws;
                getline(cin, restChars);
                cout << restChars << '\n';
                cout << "? ";
            }
            break;
            case 'i':
                cout << "i\n";
            break;
            case '\n':
                cout << "? ";
            break;
            case ' ':
            break;
            default:
                cout << "ignoring " << ch << '\n';
            break;
        }
    }
}