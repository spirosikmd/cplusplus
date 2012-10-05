#include "distances.h"

void correct(double &coordPart, char hem)
{
                            // correct for `w' and `s' hemispheres
    if (hem == 'w' || hem == 's')
        coordPart = -coordPart;
}