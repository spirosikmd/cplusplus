#include "distances.h"

double computeDifference(double coordPart1, double coordPart2)
{
    double difference = fabs(coordPart1 - coordPart2);
    if (difference > 180)       // make sure max. diff is 180 deg.
        difference = 360 - difference;
    
    return difference;
}