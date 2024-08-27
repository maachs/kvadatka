#include <TXLib.h>

#include "CompareOnZero.h"

int CompareOnZero (double compare)
{
    if (fabs(compare) < EPS)
    {
        return EQUAL_TO_ZERO;
    }
    else if (compare > EPS)
    {
        return GREATER_THAN_ZERO;
    }
    // (compare < -EPS)
    return LOWER_THAN_ZERO;
}
