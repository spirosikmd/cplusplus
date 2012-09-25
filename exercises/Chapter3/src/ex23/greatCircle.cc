#include <iostream>
#include <string>
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
    lat1 = coordinates.substr(0, index1 - 1);
    string long1;
    long1 = coordinates.substr(index1 + 2, index2 - (index1 + 3));
    string lat2;
    lat2 = coordinates.substr(index2 + 2, index3 - (index2 + 3));
    string long2;
    long2 = coordinates.substr(index3 + 2, index4 - (index3 + 3));
                                        
    cout << "lat1: " << lat1 << '\n';
    cout << "long1: " << long1 << '\n';
    cout << "lat2: " << lat2 << '\n';
    cout << "long2: " << long2 << '\n';
    
    if (lat1 != lat2 && long1 != long2)
    {
        cout << "The coordinates are not correctly specified.\n";
        return 0;
    }
}