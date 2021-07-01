/*
 *
 * Найти наименьший общий делитель трех натуральных чисел
 * (1 будет считаться наименьшим общим делителем только в том случае,
 * когда других общих делителей у заданных чисел нет).
 *
 */

#include <stdio.h>
#include "Least_Common_Divisor_Search.h"

int main()
{
    int firstNumber = getNumber();
    int secondNumber = getNumber();
    int thirdNumber = getNumber();

    int LCD = leastCommonDivisorSearch(firstNumber, secondNumber, thirdNumber);
    printf("\nThe least common divisor of the three numbers is %d", LCD);

    return 0;
}
