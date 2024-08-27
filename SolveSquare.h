#ifndef SOLVESQUARE_
#define SOLVESQUARE_

#include "KolvoResh.h"
#include "Coeffs.h"
#include "Roots.h"
#include "Compare.h"
#include "CompareOnZero.h"

void LineSolution (Coeffs coeffs, Roots* solution);
void SquareSolution (Coeffs coeffs, Roots* solution);
void SolveSquare(Coeffs coeffs, Roots* solution);

#endif
