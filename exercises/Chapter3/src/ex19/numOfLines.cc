#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    string ok("ok");
                                // if argument exists and if it is 
                                // `ok' then execute right way
    if (argv[1] && argv[1] == ok)
    {
        size_t numOfLines = 0;
        string line;
                                // read next line and incr if line is
                                // terminated with enter
        while (getline(cin, line))  
            ++numOfLines;
            
        cout << "Number of lines read: " << numOfLines << '\n';
    }
    else
    {
        size_t numOfLines = 0;
        
        while (not cin.eof())   // check if line terminated with enter
        {
            string line;
            getline(cin, line); // read the next line
            ++numOfLines;
        }
        
        cout << "Number of lines read: " << numOfLines << '\n';
    }
}