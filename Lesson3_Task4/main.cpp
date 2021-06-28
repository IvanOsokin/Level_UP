//Перевести число из десятичной системы счисления в двоичную.

#include <stdio.h>
#include <limits.h>

int main()
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

    unsigned int unsignedDecimalNum = signedDecimalNum;

    for(int i = sizeof(unsignedDecimalNum) * CHAR_BIT - 1; i >= 0; --i)
    {
        if(unsignedDecimalNum & (1 << i))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    return 0;
}
