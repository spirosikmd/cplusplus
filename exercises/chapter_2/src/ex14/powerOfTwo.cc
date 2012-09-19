#include <iostream>
int main() {
    
    for (int x=0;x<10000;x++) {
        
        std::cout <<  ( ((x != 0) && ((x & (x - 1)) == 0) ? std::string(x) :  "")); 
    }

}