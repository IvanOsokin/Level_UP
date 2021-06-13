/*
 *
 * Дано натуральное число N. Составить программу для определения количества цифр в этом числе.
 *
 */


#include <stdio.h>

int main()
{
    int N;
    do
    {
        printf("Enter a number (must be greater than 0): ");
        if(scanf("%d", &N) == 0 || N < 1)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(N < 1);

    int numberOfDigits = 0;
    do
    {
        ++numberOfDigits;
    }while(N /= 10);

    printf("\nAn amount of digits in the number is %d", numberOfDigits);

    return 0;
}
