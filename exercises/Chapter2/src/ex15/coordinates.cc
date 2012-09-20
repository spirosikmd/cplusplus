#include <iostream>

using namespace std;

int main()
{
    cout << "Degrees: ";
    size_t degrees;
    cin >> degrees;
    cout << "Minutes: ";
    size_t minutes;
    cin >> minutes;
    cout << "Seconds: ";
    size_t seconds;
    cin >> seconds;
    cout << "Hemisphere: ";
    char hemisphere;
    cin >> hemisphere;
    
    double coordinate = 53.2106;
    
    coordinate = hemisphere == 'N' || hemisphere == 'E' ? coordinate : -coordinate;
    
    cout << coordinate << '\n';
}