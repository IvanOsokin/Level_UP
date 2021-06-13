/*
 *
 * Найти наименьший общий делитель трех натуральных чисел
 * (1 будет считаться наименьшим общим делителем только в том случае,
 * когда других общих делителей у заданных чисел нет).
 *
 */


#include <stdio.h>
#include <math.h>

int main()
{
    int firstNumber;
    do
    {
        printf("Enter the first number (must be greater than 0): ");
        if(scanf("%d", &firstNumber) == 0 || firstNumber < 1)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(firstNumber < 1);

    int secondNumber;
    do
    {
        printf("Enter the second (must be greater than 0): ");
        if(scanf("%d", &secondNumber) == 0 || secondNumber < 1)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(secondNumber < 1);

    int thirdNumber;
    do
    {
        printf("Enter the third (must be greater than 0): ");
        if(scanf("%d", &thirdNumber) == 0 || thirdNumber < 1)
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }while(thirdNumber < 1);

    int LCD = 1;        //Наименьший общий делитель

    for(int i = 2; i <= (fmin(fmin(firstNumber, secondNumber), thirdNumber)); ++i)
    {
        if(firstNumber % i == 0 && secondNumber % i == 0 && thirdNumber % i == 0)
        {
            LCD = i;
            break;
        }
    }

    printf("\nThe least common divisor is %d", LCD);

    return 0;
}
