#include "distances.h"

int main(int argc, char *argv[])
{
    while (true)
    {
        cout << "? ";       // prompt
    
        char sep;
        
        cin >> sep;         // look for `q'
        if (sep != 'q')
            cin.unget();
        else
        {
            cout << "bye\n";
            usage(argv[0]); // show usage and exit
        }
        
                            // get the latitudes and longitudes
        double lat1 = getCoordinatePart();
        double long1 = getCoordinatePart();
        double lat2 = getCoordinatePart();
        double long2 = getCoordinatePart();
        
                            // differences smaller than 1" are ignored
        double const minimumDifference = 1 / 3600.0;
        
        double latitudeDifference = computeDifference(lat1, lat2);
        double longitudeDifference = computeDifference(long1, long2);
        
        bool equalLatitudes = 
                        latitudeDifference < minimumDifference;
        bool equalLongitudes =
                        longitudeDifference < minimumDifference;
        
                            // if both lat. and long. differ: error
        if (not equalLatitudes && not equalLongitudes)
        {
            cout << "err: either latitudes or "
                    "longitudes must be equal\n";
            continue;
        }
        
        if (equalLongitudes)
        {
            cout << getDistance(latitudeDifference);
            continue;
        }
        
                            // equal latitudes, with correction of 
                            // distance along parallels
        correct(longitudeDifference, lat1);
        
        cout << getDistance(longitudeDifference);
    }
}