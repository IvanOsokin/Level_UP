//Поменять местами цифры старшего и младшего разрядов
//данного натурального числа (например, из числа 3879 получится 9873).


#include <stdio.h>
#include <math.h>
#include "Exchange_Digits.h"

int main()
{
    int number = getInteger();
    printf("\nA new number is: %d", exchangeDigits(number));

    return 0;
}
