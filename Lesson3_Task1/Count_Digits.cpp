#include <stdio.h>
#include "Count_Digits.h"

int getNumber()
{
    int n;
    do
    {
        printf("Enter a number (must be greater than 0): ");
        if(scanf("%d", &n) == 0 || n < 1)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(n < 1);

    return n;
}

int countDigits(int N)
{
    int numberOfDigits = 0;
    do
    {
        ++numberOfDigits;
    }while(N /= 10);

    return numberOfDigits;
}
