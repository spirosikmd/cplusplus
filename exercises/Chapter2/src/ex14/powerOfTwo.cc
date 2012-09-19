#include <iostream>

using namespace std;

int main() {

    int x = 1;
    
    bool powerOfTwo =  x != 0 && (x & (x - 1)) == 0;

    cout << (powerOfTwo ? "The value is an exact power of two" : "The value is not an exact power of two" );


}