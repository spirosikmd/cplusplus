#include "distances.h"

string getDistance(double difference)
{
    double distanceNM = 60 * difference;
    double distanceKM = 1.852 * 60 * difference;
    
    return "distance: " + distanceNM +
            " NM. (" + distanceKM +
            " km.)\n";
}