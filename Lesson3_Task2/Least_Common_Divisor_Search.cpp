#include <stdio.h>
#include <math.h>
#include "Least_Common_Divisor_Search.h"

int getNumber()
{
    int tempNumber;
    do
    {
        printf("Enter a number (must be greater than 0): ");
        if(scanf("%d", &tempNumber) == 0 || tempNumber < 1)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(tempNumber < 1);

    return tempNumber;
}

int leastCommonDivisorSearch(int firstNum, int secondNum, int thirdNum)
{
    int LCD = 1;        //Наименьший общий делитель
    int minInt = (fmin(fmin(firstNum, secondNum), thirdNum));
    for(int i = 2; i <= minInt; ++i)
    {
        if(firstNum % i == 0 && secondNum % i == 0 && thirdNum % i == 0)
        {
            LCD = i;
            break;
        }
    }

    return LCD;
}
