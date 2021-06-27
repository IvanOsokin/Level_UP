/*
 *
 * Вычислить сумму ряда с точностью 10^-5, где 0.05<x<1
 *
 */

#include <stdio.h>
#include <math.h>

int doubleFactorial(int n);

int main()
{
    const double eps = 10e-5;
    double x = 0.1;
    do
    {
        double result = 0;
        double step = x;
        for(int n = 1; step > eps; ++n)
        {
            result += step;
            step = doubleFactorial(2 * n - 1) * pow(x, (2 * n) + 1) / (doubleFactorial(2 * n) * (2 * n + 1));
        }
        printf("x = %f\tresult = %f\n", x, result);
        x += 0.05;
    }while(x < 1);

    return 0;
}

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
