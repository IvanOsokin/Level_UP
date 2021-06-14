/*
 *
 * Вычислить сумму ряда с точностью 10^-5, где 0.05<x<1
 *
 */

#include <stdio.h>
#include <math.h>

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
            step = (2 * n - 1) * pow(x, (2 * n) + 1) / (4 * pow(n, 2) + 2 * n);
        }
        printf("x = %f\tresult = %f\n", x, result);
        x += 0.05;
    }while(x < 1);

    return 0;
}
