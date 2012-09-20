#include <iostream>
#include <string>

using namespace std;

int main()
{
    string pathString = getenv("PATH"); // retrieve the value of the
                                        // env variable PATH
    cout << "Current PATH: " << pathString << '\n';
    
    cout << "What to remove? ";
    string substring;
    cin >> substring; // read the string to be removed
    
    size_t opos = pathString.find(substring);
    size_t on = substring.length(); // get the number of charactes of
                                    // the substring
    pathString.erase(opos, on); // erase the substring of the current
                                // path string starting at the position
                                // of the first occurrence
    cout << "New PATH: " << pathString << '\n';
}