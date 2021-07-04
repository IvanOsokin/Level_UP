#include <stdio.h>
#include <math.h>
#include "Exchange_Digits.h"

int getInteger()
{
    int number;
    do
    {
        printf("Enter a number (must be greater than 0): ");
        if(scanf("%d", &number) == 0 || number < 1)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(number < 1);

    return number;
}

int exchangeDigits(int num)
{
    int i = 0;
    int tempNum = num;
    while(tempNum /= 10)
    {
        ++i;
    }

    const int firstNum = num / pow(10, i);
    const int middleNum = (num / 10 - firstNum * pow(10, i - 1)) * 10;
    const int lastNum = num % 10;

    num = lastNum * pow(10, i) + middleNum + firstNum;

    return num;
}
