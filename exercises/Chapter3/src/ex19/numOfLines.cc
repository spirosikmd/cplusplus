#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    string argument("ok");
    
    if (argv[1] && argument == argv[1]) // if an argument exists and
                                        // if it is `ok' then we are
                                        // executing the right way
    {
        size_t numOfLines = 0;
        
        string line;
        while (getline(cin, line))      // read the next line and
                                        // increment only if line is
                                        // terminated with enter
            ++numOfLines;
            
        cout << "Number of lines read: " << numOfLines << '\n';
    }
    else
    {
        size_t numOfLines = 0;
        
        while (not cin.eof())           // check if line terminated
                                        // with enter
        {
            string line;
            getline(cin, line);         // read the next line
            ++numOfLines;
        }
        
        cout << "Number of lines read: " << numOfLines << '\n';
    }
}