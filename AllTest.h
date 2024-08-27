#ifndef ALLTEST_
#define ALLTEST_
#include "KolvoResh.h"
#include "Coeffs.h"
#include "Compare.h"
#include "CompareOnZero.h"
#include "SolveSquare.h"

struct ExpectedSol
{
    Coeffs coeffs;
    double x1_expected;
    double x2_expected;
    int nRoots_expected;
};

void AllTest ();
void Swap (double *value1, double *value2);
void Test (int TestNumber, Roots* solution, ExpectedSol* expected);
bool NAN_OR_INF (double check);

#endif
