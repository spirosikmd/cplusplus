#include "distances.h"

double computeCoordinatePart(size_t deg, size_t min, size_t sec)
{
                            // compute the abs. part of the coord
    return deg + min / 60.0 + sec / 3600.0;
}