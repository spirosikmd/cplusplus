#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    string argument("ok");
    
    if (argv[1] && argument == argv[1])
    {
        size_t numOfLines = 0;
        
        string line;
        while (getline(cin, line))
            ++numOfLines;
            
        cout << "Number of lines read: " << numOfLines << '\n';
    }
    else
    {
        size_t numOfLines = 0;
        
        while (not cin.eof())
        {
            string line;
            getline(cin, line);
            ++numOfLines;
        }
        
        cout << "Number of lines read: " << numOfLines << '\n';
    }
}