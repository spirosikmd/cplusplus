#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please provide a number between 32 and 255: ";
    size_t value;
    cin >> value; // read the value from the user
    string output = "unsigned value:  , as character: `\'\n";
    output.insert(34, 1, value);
    cout << output[16];
}