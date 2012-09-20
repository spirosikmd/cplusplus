#include <iostream>

using namespace std;

int main() 
{
    string str;
    cout << (getline(cin, str).eof() ? "complete line" :
                                       "incomplete line") << "\n";
}