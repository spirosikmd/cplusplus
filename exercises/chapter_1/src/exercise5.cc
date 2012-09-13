#include <iostream>

using namespace std;

enum Day
{
    First, Second,Third,Fourth,Fifth,Sixth,Seventh,Eighth
};

enum Month
{
    January=1, February, March, April, May, June, July,
    August, September, October, November, December
};

void showDate(int daynr, Month month, int year)
{
    cout << month << endl;
}

int main()
{    
    showDate(2, September, 2012);
}

