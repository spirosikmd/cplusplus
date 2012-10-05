#include "distances.h"

void correct(double &difference, double coordPart)
{
                            // correction of distance along parallels
    difference *= cos(M_PI / 180 * coordPart);
}