#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main()
{
    cout << "? ";
    
    char ch;
    if (!cin.get(ch) || ch == 'q')
        return 0;
    
    cin.unget();
    
    string coordinates;
    getline(cin, coordinates);
    
    size_t index1;
    size_t index3;
    size_t north = coordinates.find('n');
    size_t south = coordinates.find('s');
    if (north != string::npos)
    {
        if (south != string::npos)
        {
            if (north < south)
            {
                index1 = north;
                index3 = south;
            }
            else
            {
                index1 = south;
                index3 = north;
            }
        }
        else
        {
            index1 = north;
            index3 = coordinates.rfind('n');
        }
    }
    else
    {
        index1 = south;
        index3 = coordinates.rfind('s');
    }
    
    size_t index2;
    size_t index4;
    size_t east = coordinates.find('e');
    size_t west = coordinates.find('w');
    if (east != string::npos)
    {
        if (west != string::npos)
        {
            if (east < west)
            {
                index2 = east;
                index4 = west;
            }
            else
            {
                index2 = west;
                index4 = east;
            }
        }
        else
        {
            index2 = east;
            index4 = coordinates.rfind('e');
        }
    }
    else
    {
        index2 = west;
        index4 = coordinates.rfind('w');
    }
    
    string lat1;
    lat1 = coordinates.substr(0, index1 + 1);
    string long1;
    long1 = coordinates.substr(index1 + 2, index2 - (index1 + 1));
    string lat2;
    lat2 = coordinates.substr(index2 + 2, index3 - (index2 + 1));
    string long2;
    long2 = coordinates.substr(index3 + 2, index4 - (index3 + 1));
                                        
    cout << "lat1: " << lat1 << '\n';
    cout << "long1: " << long1 << '\n';
    cout << "lat2: " << lat2 << '\n';
    cout << "long2: " << long2 << '\n';
    
    if (lat1 != lat2 && long1 != long2)
    {
        cout << "The coordinates are not correctly specified.\n";
        return 0;
    }
    
    if (long1 == long2)
    {
        
    }
    else
    {
        size_t sep1 = long1.find(':');
        size_t sep2 = long1.rfind(':');
        string degrees;
        degrees = long1.substr(0, sep1);
        string minutes;
        minutes = long1.substr(sep1 + 1, sep2 - (sep1 + 1));
        string seconds;
        seconds = long1.substr(sep2 + 1, long1.length());
        
        double long1Double;
        long1Double = atof(degrees.c_str()) +
                        atof(minutes.c_str()) / 60 +
                        atof(seconds.c_str()) / 3600;
        
        long1Double = long1.at(long1.length() - 1) == 'w' ?
                        -long1Double : long1Double;
        
        sep1 = long2.find(':');
        sep2 = long2.rfind(':');
        degrees = long2.substr(0, sep1);
        minutes = long2.substr(sep1 + 1, sep2 - (sep1 + 1));
        seconds = long2.substr(sep2 + 1, long2.length());
        
        double long2Double;
        long2Double = atof(degrees.c_str()) +
                        atof(minutes.c_str()) / 60 +
                        atof(seconds.c_str()) / 3600;
        
        long2Double = long2.at(long2.length() - 1) == 'w' ?
                        -long2Double : long2Double;
        
        cout << "1st Value: " << long1Double << '\n';
        cout << "2nd Value: " << long2Double << '\n';
        
        double longDiff = fabs(fabs(long1Double) - fabs(long2Double));
        
        cout << longDiff << '\n';
                        
        sep1 = lat1.find(':');
        sep2 = lat1.rfind(':');
        degrees = lat1.substr(0, sep1);
        minutes = lat1.substr(sep1 + 1, sep2 - (sep1 + 1));
        seconds = lat1.substr(sep2 + 1, lat1.length());

        double lat1Double;
        lat1Double = atof(degrees.c_str()) +
                        atof(minutes.c_str()) / 60 +
                        atof(seconds.c_str()) / 3600;
                        
        double result = longDiff * cos(lat1Double);
        
        cout << "  distance: " << result * 60 << " NM "
                "("<< result * 60 * 1.852 <<")\n";
    }
}