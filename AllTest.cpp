#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <TXLib.h>

#include "AllTest.h"

void AllTest ()
{
    const int AmountOfTest = 12;
    Roots solution = {};
    ExpectedSol expected [AmountOfTest] = {{{0,   0,   0},      NAN,      NAN, INF_ROOTS},
                                           {{0,   0,   1},      NAN,      NAN, 0},
                                           {{0,   1,   0},        0,      NAN, 1},
                                           {{1,   0,   0},        0,      NAN, 1},
                                           {{0,   1,   1},       -1,      NAN, 1},
                                           {{1,   0,   1},      NAN,      NAN, 0},
                                           {{1,   1,   0},       -1,        0, 2},
                                           {{1,   1, -12},       -4,        3, 2},
                                           {{1,   1,0.25},     -0.5,      NAN, 1},
                                           {{4,  -3,   2},      NAN,      NAN, 0},
                                           {{2,   6,  -3}, -3.43649, 0.436492, 2},
                                           {{2,   6,  -3}, 0.436492, -3.43649, 2}};

    for (int TestNumber = 0; TestNumber < AmountOfTest; TestNumber++)
    {
        if (expected[TestNumber].x1_expected > expected[TestNumber].x2_expected)
        {
            Swap(&expected[TestNumber].x1_expected, &expected[TestNumber].x2_expected);
        }
        txSetConsoleAttr(FOREGROUND_WHITE| BACKGROUND_BLACK);
        printf("Starts test %d\n", TestNumber + 1);
        Test (TestNumber, &solution, expected + TestNumber);
    }
}

void Swap (double *value1, double *value2)
{
    assert(value1);
    assert(value2);

    double temp = *value2;

    *value2 = *value1;
    *value1 = temp;
}

void Test (int TestNumber, Roots* solution, ExpectedSol* expected )
{
    SolveSquare (expected->coeffs, solution);

    double delta_x1 = 0, delta_x2 = 0;

    if (NAN_OR_INF(solution->x1) == 0)
    {
        if(NAN_OR_INF(expected->x1_expected) == 0)
        {
            delta_x1 = 0;
        }
    }
    else
    {
        delta_x1 = fabs(solution->x1 - expected->x1_expected);
    }

    if (NAN_OR_INF(solution->x2) == 0)
    {
        if(NAN_OR_INF(expected->x2_expected) == 0)
        {
            delta_x2 = 0;
        }
    }
    else
    {
        delta_x2 = fabs(solution->x2 - expected->x2_expected);
    }
      if ((*solution).nRoots != (*expected).nRoots_expected || CompareOnZero(delta_x1) != EQUAL_TO_ZERO || CompareOnZero(delta_x2) != EQUAL_TO_ZERO)
    {
        txSetConsoleAttr(FOREGROUND_RED | BACKGROUND_BLACK);
        printf("\nError: Test %d\n  a = %lg b = %lg c = %lg\n  x1 = %lg x2 = %lg nRoots = %d\n"
               "Expected:\n  x1 = %lg x2 = %lg nRoots = %d\n",
               TestNumber + 1, expected->coeffs.a, expected->coeffs.b, expected->coeffs.c, (*solution).x1, (*solution).x2, (*solution).nRoots,
               (*expected).x1_expected, (*expected).x2_expected, (*expected).nRoots_expected);
    }
    else
    {
        txSetConsoleAttr(FOREGROUND_GREEN | BACKGROUND_BLACK);
        printf ("Test %d Completed Succesfull\n",TestNumber + 1);
        txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_BLACK);
    }
}

bool NAN_OR_INF (double check)
{
    if (!isfinite(check))
    {
        return 0;    // NAN or INF
    }
    else
    {
        return 1;
    }
}
