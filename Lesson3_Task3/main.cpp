/*
 *
 * Поменять местами цифры старшего и младшего разрядов
 * данного натурального числа (например, из числа 3879 получится 9873).
 *
 */


#include <stdio.h>
#include <math.h>

int main()
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

    int i = 0;
    int tempNum = number;
    while(tempNum /= 10)
    {
        ++i;
    }

    const int firstNum = number / pow(10, i);
    const int middleNum = (number / 10 - firstNum * pow(10, i - 1)) * 10;
    const int lastNum = number % 10;

    number = lastNum * pow(10, i) + middleNum + firstNum;
    printf("\nA new number is: %d", number);

    return 0;
}
