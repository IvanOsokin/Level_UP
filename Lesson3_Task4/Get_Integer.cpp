#include <stdio.h>
#include "Get_Integer.h"

int getInteger()
{
    int signedDecimalNum;
    bool isValidRead = false;
    while(!isValidRead)
    {
        printf("Enter any positive integer: ");
        isValidRead = scanf("%d", &signedDecimalNum);
        if(!isValidRead || signedDecimalNum < 0)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
            isValidRead = false;
        }
    }

    return signedDecimalNum;
}
