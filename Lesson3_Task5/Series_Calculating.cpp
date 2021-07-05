#include <stdio.h>
#include <math.h>
#include "Series_Calculating.h"

int doubleFactorial(int n)
{
    if(n <= 1)
    {
        return 1;
    }

    int result;
    result = n * doubleFactorial(n - 2);

    return result;
}

double seriesCalculating(double x)
{
    const double eps = 10e-5;
    double result = 0;
    double step = x;
    for(int n = 1; step > eps; ++n)
    {
    result += step;
    step = doubleFactorial(2 * n - 1) * pow(x, (2 * n) + 1) / (doubleFactorial(2 * n) * (2 * n + 1));
    }

    return result;
}
