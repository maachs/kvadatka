#include <TXLib.h>
#include <math.h>
#include "SolveSquare.h"

void SolveSquare(Coeffs coeffs, Roots* solution)
{
    assert (solution );
    if (CompareOnZero(coeffs.a) == 0)
    {
          LineSolution (coeffs, solution);
    }
    else
    {
         SquareSolution (coeffs, solution);
    }
}

void LineSolution (Coeffs coeffs, Roots* solution)
{
    assert (solution);

        if (CompareOnZero(coeffs.b) == 0)
        {
            if (CompareOnZero(coeffs.c) == 0)
            {
                  solution->nRoots = INF_ROOTS;
            }
            else
            {
                solution->x1 = NAN;
                solution->x2 = NAN;
                solution->nRoots = NO_ROOTS;
            }
        }
        else
        {
            solution->x1 = -coeffs.c/coeffs.b;
            solution->x2 = NAN;
            solution->nRoots = ONE_ROOTS;
        }
}

void SquareSolution (Coeffs coeffs, Roots* solution)
{
    double d = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs. c;

    if (CompareOnZero(d) == GREATER_THAN_ZERO)
    {
        solution->x1 = (-(coeffs.b) - sqrt(d))/(2*coeffs.a);
        solution->x2 = (-(coeffs.b) + sqrt(d))/(2*coeffs.a);
        solution->nRoots = TWO_ROOTS;
    }
    else if (CompareOnZero(d) == EQUAL_TO_ZERO)
    {
        solution->x1 = (-coeffs.b)/(2*coeffs.a);
        solution->x2 = NAN;
        solution->nRoots = ONE_ROOTS;
    }
    else if (CompareOnZero(d) == LOWER_THAN_ZERO)
    {
        solution->nRoots = NO_ROOTS;
        solution->x1 = NAN;
        solution->x2 = NAN;
    }
}
