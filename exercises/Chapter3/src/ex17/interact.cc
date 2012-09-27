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
            
            case 'n':
            case '*':
            {
                cin >> ws;          // remove leading white space
                string restChars;
                                    // read chars after command
                getline(cin, restChars); 
                                    // get the index of the last char
                                    // other than space or tab
                size_t idx = restChars.find_last_not_of(" \t");
                                    // remove trailing white spaces
                cout << restChars.substr(0, idx + 1) << '\n';
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
            case '\t':
            break;
            
            default:
                cout << "ignoring " << ch << '\n';
            break;
        }
    }
}