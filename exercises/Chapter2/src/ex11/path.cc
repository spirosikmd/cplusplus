#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Retrieve the value of the env variable `PATH'.
    string pathString = getenv("PATH");
    cout << "Current PATH: " << pathString << "\n"
            "What to remove? ";
            
    string substring;
    cin >> substring; // Read the string to be removed.
    
    // Find the index of the first occurence of `substring' in
    // `pathString'. It returns string::npos if the `substring'
    // is not contained in `pathString'.
    size_t opos = pathString.find(substring);
    
    // Check if `find' returned string::npos. If the substring is not 
    // found, then by assigning the length of the `pathString' to the 
    // `opos' we ensure that no runtime error will occur.
    opos = opos == string::npos ? pathString.length() : opos;
    
    // Get the number of charactes of the `substring'.
    size_t on = substring.length();
    
    // Erase the `substring' of the current `pathString' starting at
    // the position of the first occurrence.
    pathString.erase(opos, on); 
    
    cout << "New PATH: " << pathString << '\n';
}