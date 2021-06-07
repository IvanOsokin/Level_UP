/*
 *
 * Вычислить следующие выражения
 *
 * a=5, c=5
 *
 * a=a+b-2
 * c=c+1, d=c-a+d
 * a=a*c, c=c-1
 * a=a/10, c=c/2, b=b-1, d=d*(c+b+a)
 *
 */

#include <stdio.h>

int main()
{
    float a = 5., c = 5., d;
    int b;

    printf("Enter a value of b = ");
    scanf("%d", &b);
    printf("Enter a value of d = ");
    scanf("%f", &d);

    printf("\na = %.0f\tb = %d\tc = %.0f\td = %.0f\n\n", a , b, c, d);

    a = a + b - 2;
    printf("\na = a + b - 2 = %.0f\n", a);

    c++;
    printf("c = c + 1 = %.0f\n", c);

    d = c - a + d;
    printf("d = c - a + d = %.0f\n", d);

    a *= c;
    printf("a = a * c = %.0f\n", a);

    c -= 1;
    printf("c = c - 1 = %.0f\n", c);

    a /= 10;
    printf("a = a / 10 = %.3f\n", a);

    c /= 2;
    printf("c = c / 2 = %.3f\n", c);

    b--;
    printf("b = b - 1 = %d\n", b);

    d = d * (c + b + a);
    printf("d = d * (c + b + a) = %.3f\n", d);

    return 0;
}
