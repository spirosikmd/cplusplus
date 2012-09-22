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
            case 'n':
            {
                cin >> ws;
                string restChars;
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