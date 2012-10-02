#include <iostream>
#include <string>

using namespace std;

int function1()
{
    return 1;
}

string function2()
{
    return "some text";
}

int main()
{
    int someValue = 1;
    someValue += function1();
    cout << someValue << '\n';
    
    function2() = "something else";
}