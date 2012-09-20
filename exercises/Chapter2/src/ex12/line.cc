#include <iostream>

using namespace std;

int main() 
{
    string str;
<<<<<<< HEAD
    cout << (getline(cin, str).eof() ? "complete line" : 
=======
    cout << (getline(cin, str).eof() ? "complete line" :
>>>>>>> line.cc format
                                       "incomplete line") << "\n";
}