/*
 *
 * Вычислить значение у по формуле
 *
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double x = 1;
    double y;
    int isNum = 0;

    while(true)
    {
        printf("Enter the value of x (x must be greater than 0): ");

        isNum = scanf("%lf", &x);

        if (x > 0 && isNum == 1)
        {
            break;
        }
        else
        {
            printf("The value is not allowed!!!\nTry one more time!!!\n\n");
            while (getchar() != '\n');
        }

    }

    y = ((2 * cos(x - M_PI / 6) + sqrt(2)) * exp(3 * x)) / (0.5 * log(x) + pow(sin(pow(x, 2)), 2));

    printf("\ny = %lf", y);

    return 0;
}
