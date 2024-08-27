#include <TXLib.h>
#include <math.h>
#include <stdio.h>

#include "OutputSolution.h"
#include "InputCoeffs.h"
#include "SolveSquare.h"
#include "AllTest.h"
#include "CompareOnZero.h"

int main()
{
    int choose = NAN;
    printf("Для решения уравнения 1\nДля проверки 2\n");
    scanf("%d", &choose);
    while (true)
    {
        if (choose == 1)
        {
            Coeffs coeffs;
            Roots solution;

            InputCoeffs(&coeffs);
            SolveSquare(coeffs, &solution);
            OutputSolution(solution);

            return 0;
        }
        else if (choose == 2)
        {
            AllTest ();
            return 0;
        }
        else
        {
            txSetConsoleAttr(FOREGROUND_RED | BACKGROUND_BLACK);
            printf("Неверный ввод\n");
            txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_BLACK);

            if (!isdigit(choose))
            {
                getchar();
            }

            txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_BLACK);
            scanf("%d", &choose);
        }
    }
}
