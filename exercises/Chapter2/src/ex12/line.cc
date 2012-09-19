#include <iostream>

using namespace std;

int main() 
{
    string str;
    getline(cin, str);
    cout << (cin.eof() ? "complete line" : "incomplete line") << "\n";
}