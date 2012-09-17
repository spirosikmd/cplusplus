#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Please provide a number between 32 and 255: ";
    size_t value;
    cin >> value; // read the value
    cout << "unsigned value: " << value <<
            ", as character: `" << static_cast<char>(value) << "\'\n";
    
    char ch = value;
    cout << "unsigned value: " << static_cast<size_t>(ch) <<
            ", as character: `" << ch << "\'\n";
}