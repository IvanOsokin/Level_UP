/*
 *
 * Написать программу, определяющую, площадь какой фигуры больше:
 * круга радиуса R, равностороннего треугольника с длиной стороны а
 * или квадрата со стороной d. (используя ?:).
 *
 */

#include <stdio.h>
#include <math.h>

int main()
{
    double radius = -1;
    do
    {
        printf("Enter a value of the radius: ");
        if(scanf("%lf", &radius) == 0 || radius < 0)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(radius < 0);

    double squareSide = -1;
    do
    {
        printf("Enter a value of the side of the square: ");
        if(scanf("%lf", &squareSide) == 0 || squareSide < 0)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(squareSide < 0);

    double triangleSide = -1;
    do
    {
        printf("Enter a value of the side of the triangle: ");
        if(scanf("%lf", &triangleSide) == 0 || triangleSide < 0)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(triangleSide < 0);

    double circleSquare = 0;
    circleSquare = M_PI * pow(radius, 2);
    printf("\nThe area of the circle = %f\n", circleSquare);

    double squareSquare = 0;
    squareSquare = squareSide * squareSide;
    printf("The area of the square = %f\n", squareSquare);

    double halfPerimeter = 0;
    halfPerimeter = 1.5 * triangleSide;
    double triangleSquare = 0;
    triangleSquare = sqrt(halfPerimeter * pow((halfPerimeter - triangleSide), 3));
    printf("The area of the triangle = %f\n", triangleSquare);

    printf("\nThe greatest square is %f", fmax(fmax(circleSquare, squareSquare), triangleSquare));

    return 0;
}
