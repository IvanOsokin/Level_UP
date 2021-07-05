//Вычислить сумму ряда с точностью 10^-5, где 0.05<x<1

#include <stdio.h>
#include "Series_Calculating.h"

int main()
{
    double x = 0.1;
    do
    {
        printf("x = %f\tresult = %f\n", x, seriesCalculating(x));
        x += 0.05;
    }while(x < 1);

    return 0;
}
