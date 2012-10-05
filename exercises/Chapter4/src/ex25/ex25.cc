#include <iostream>
#include <string>

using namespace std;

// void fun(int arg);
// void fun(char const *arg);

void function(int arg = 0);
void function(char *arg = '\0');

int main()
{
    // fun(static_cast<char*>(0));
    // fun("\0");
    function();
}

// void fun(int arg)
// {
//     cout << "called the int\n";
// }
// void fun(char const *arg)
// {
//     cout << "called the char\n";
// }

// void function(int arg)
// {
//     
// }
// 
// void function(char const *arg)
// {
//     
// }