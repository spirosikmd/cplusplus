#include <iostream>
#include <string>

using namespace std;

int main()
{
    string path_string = getenv("PATH"); // retrieve the value of the
                                         // env variable PATH
    cout << "Current PATH: " << path_string << "\n"
            "What to remove? ";
    string string_to_remove;
    cin >> string_to_remove; // read the string to be removed
    size_t opos = path_string.find(string_to_remove);
    size_t length = string_to_remove.length();
    path_string.erase(opos, length);
    cout << "New PATH: " << path_string << '\n';
}