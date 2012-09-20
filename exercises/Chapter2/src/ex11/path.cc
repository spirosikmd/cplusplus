#include <iostream>
#include <string>

using namespace std;

enum Errors
{
    SUBSTRING_NOT_FOUND = -1
};

int main()
{
    string pathString = getenv("PATH"); // Retrieve the value of the
                                        // env variable `PATH'.
    cout << "Current PATH: " << pathString << '\n';
    
    cout << "What to remove? ";
    string substring;
    cin >> substring; // Read the string to be removed.
    
    int opos = pathString.find(substring);
    // Check if `find' returned SUBSTRING_NOT_FOUND error.
    // If the substring is not found, then by assigning the length of
    // the `pathString' to the `opos' we ensure that no runtime error
    // will be produced.
    opos = opos == SUBSTRING_NOT_FOUND ? pathString.length() : opos;
    
    size_t on = substring.length(); // Get the number of charactes of
                                    // the `substring'.
    pathString.erase(opos, on); // Erase the `substring' of the current
                                // `pathString' starting at the position
                                // of the first occurrence.
    cout << "New PATH: " << pathString << '\n';
}