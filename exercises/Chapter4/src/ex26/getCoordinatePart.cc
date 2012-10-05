#include "distances.h"

double getCoordinatePart()
{
    size_t deg;             // the elements of a degree specification
    size_t min;
    size_t sec;
    char sep;
    char hem;
                            // get the elemements of a coordinate
    cin >> deg >> sep >> min >> sep >> sec >> hem;
                            
                            // compute the abs. part of the coord
    double coordPart = computeCoordinatePart(deg, min, sec);
    
                            // correct for `w' and `s' hemispheres
    correct(coordPart, hem);
    
    return coordPart;
}