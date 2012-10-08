#include "distances.h"

void showDistance(double difference)
{
    double distanceNM = 60 * difference;
    double distanceKM = 1.852 * 60 * difference;
    
    cout << "distance: " << distanceNM <<
            " NM. (" << distanceKM <<
            " km.)\n";
}