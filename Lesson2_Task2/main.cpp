#include <stdio.h>
#include <math.h>

int main()
{
    double radius = 0;
    double squareSide = 0;
    double triangleSide = 0;
    bool isNumber = false;
    double circleSquare = 0;
    double squareSquare = 0;
    double triangleSquare = 0;
    double halfPerimeter = 0;
    double maxSquare = 0;

    while(true)
    {
        printf("Enter a value of the radius: ");
        isNumber = scanf("%lf", &radius);
        if (isNumber != 0 && radius >= 0)
        {
            break;
        }
        else
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            while(getchar() != '\n');
        }
    }

    while(true)
    {
        printf("Enter a value of the side of square: ");
        isNumber = scanf("%lf", &squareSide);
        if (isNumber != 0 && radius >= 0)
        {
            break;
        }
        else
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            while(getchar() != '\n');
        }
    }

    while(true)
    {
        printf("Enter a value of the side of the equilateral triangle: ");
        isNumber = scanf("%lf", &triangleSide);
        if (isNumber != 0 && radius >= 0)
        {
            break;
        }
        else
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            while(getchar() != '\n');
        }
    }

    circleSquare = M_PI * pow(radius, 2);
    squareSquare = squareSide * squareSide;
    halfPerimeter = 1.5 * triangleSide;
    triangleSquare = sqrt(halfPerimeter * pow((halfPerimeter - triangleSide), 3));

    printf("circle = %lf\n", circleSquare);
    printf("square = %lf\n", squareSquare);
    printf("triangle = %lf\n", triangleSquare);

    maxSquare = circleSquare > squareSquare ? circleSquare : squareSquare;
    maxSquare = maxSquare > triangleSquare ? maxSquare : triangleSquare;

    printf("The greatest square is %lf", maxSquare);

    return 0;
}
