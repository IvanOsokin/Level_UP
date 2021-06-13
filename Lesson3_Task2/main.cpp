/*
 *
 * Найти наименьший общий делитель трех натуральных чисел
 * (1 будет считаться наименьшим общим делителем только в том случае,
 * когда других общих делителей у заданных чисел нет).
 *
 */

#include <stdio.h>
#include <math.h>

int getNumber(void);

int main()
{
    int firstNumber = getNumber();
    int secondNumber = getNumber();
    int thirdNumber = getNumber();

    int LCD = 1;        //Наименьший общий делитель

    for(int i = 2; i <= (fmin(fmin(firstNumber, secondNumber), thirdNumber)); ++i)
    {
        if(firstNumber % i == 0 && secondNumber % i == 0 && thirdNumber % i == 0)
        {
            LCD = i;
            break;
        }
    }

    printf("\nThe least common divisor of three numbers is %d", LCD);

    return 0;
}

int getNumber(void)
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
