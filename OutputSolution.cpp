#include <TXLib.h>

#include "OutputSolution.h"

void OutputSolution (struct Roots solution)
{
    switch (solution.nRoots)
    {
        case NO_ROOTS:
            txSetConsoleAttr(FOREGROUND_RED | BACKGROUND_BLACK);
            printf("Нет решений\n");
            txSetConsoleAttr(FOREGROUND_WHITE| BACKGROUND_BLACK);
            break;

        case ONE_ROOTS:
            txSetConsoleAttr(FOREGROUND_GREEN | BACKGROUND_BLACK);
            printf("x = %lg", solution.x1);
            txSetConsoleAttr(FOREGROUND_WHITE| BACKGROUND_BLACK);
            break;

        case TWO_ROOTS:
            txSetConsoleAttr(FOREGROUND_GREEN | BACKGROUND_BLACK);
            printf("x1 = %lg\nx2 = %lg", solution.x1, solution.x2);
            txSetConsoleAttr(FOREGROUND_WHITE| BACKGROUND_BLACK);
            break;

        case INF_ROOTS:
            txSetConsoleAttr(FOREGROUND_DARKYELLOW | BACKGROUND_BLACK);
            printf("Любое число");
            txSetConsoleAttr(FOREGROUND_WHITE| BACKGROUND_BLACK);
            break;

        default:
            txSetConsoleAttr(FOREGROUND_RED | BACKGROUND_BLACK);
            printf("error %d", solution.nRoots);
            txSetConsoleAttr(FOREGROUND_WHITE| BACKGROUND_BLACK);
            break;
    }
}
