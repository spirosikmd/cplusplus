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
    
    size_t first_index;
    size_t third_index;
    size_t north = coordinates.find('n');
    size_t south = coordinates.find('s');
    if (north != string::npos)
    {
        if (south != string::npos)
        {
            if (north < south)
            {
                first_index = north;
                third_index = south;
            }
            else
            {
                first_index = south;
                third_index = north;
            }
        }
        else
        {
            first_index = north;
            third_index = coordinates.rfind('n');
        }
    }
    else
    {
        first_index = south;
        third_index = coordinates.rfind('s');
    }
    
    size_t second_index;
    size_t fourth_index;
    size_t east = coordinates.find('e');
    size_t west = coordinates.find('w');
    if (east != string::npos)
    {
        if (west != string::npos)
        {
            if (east < west)
            {
                second_index = east;
                fourth_index = west;
            }
            else
            {
                second_index = west;
                fourth_index = east;
            }
        }
        else
        {
            second_index = east;
            fourth_index = coordinates.rfind('e');
        }
    }
    else
    {
        second_index = west;
        fourth_index = coordinates.rfind('w');
    }
    
    string lat1;
    lat1 = coordinates.substr(0, first_index - 1);
    string long1;
    long1 = coordinates.substr(first_index + 2,
                                    second_index - (first_index + 3));
    string lat2;
    lat2 = coordinates.substr(second_index + 2,
                                    third_index - (second_index + 3));
    string long2;
    long2 = coordinates.substr(third_index + 2,
                                    fourth_index - (third_index + 3));
                                        
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