#include <TXLib.h>

#include "InputCoeffs.h"

void InputCoeffs(Coeffs* coeffs)
{
    assert (coeffs);

    while (true)
    {
        txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_BLACK);
        printf("Введите коффиценты:\n");

        if (scanf("%lg %lg %lg", &coeffs->a, &coeffs->b, &coeffs->c) != 3)
        {
            while (getchar() != '\n') {};
            txSetConsoleAttr(FOREGROUND_WHITE | BACKGROUND_BLACK);
            printf("Неверные коэффиценты\n");
            continue;
        }
        if ( CheckCoeffs (*coeffs) == 1)
        {
            continue;
        }
        break;
    }
}

int CheckCoeffs (Coeffs coeffs)
{
    if (!isfinite(coeffs.a) || !isfinite(coeffs.b) || !isfinite(coeffs.c))
    {
        return 1;
    }

    return 0;
}

