/*
 *
 * Вычислить значение у по формуле
 *
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double x;

    do
    {
        printf("Enter the value of x (x must be greater than 0): ");

        if(const bool isValidRead = scanf("%lf", &x) == 0 || x <= 0)
        {
            printf("The value is not allowed!!!\nTry one more time!!!\n\n");
            fflush(stdin);
        }
    }while(x <= 0);

    double y;
    y = ((2 * cos(x - M_PI / 6) + sqrt(2)) * exp(3 * x)) / (0.5 * log(x) + pow(sin(pow(x, 2)), 2));

    printf("\ny = %f", y);

    return 0;
}
