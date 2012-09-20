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
    
    double coordinate = degrees +
                        (static_cast<double>(minutes) / 60) +
                        (static_cast<double>(seconds) / 3600);
    
    coordinate = hemisphere == 'N' || hemisphere == 'E' ? coordinate : 
                                                          -coordinate;
    
    cout << coordinate << '\n';
}