//Дано натуральное число N.
//Составить программу для определения количества цифр в этом числе.

#include <stdio.h>
#include "Count_Digits.h"

int main()
{
    int N = getNumber();
    printf("\nAn amount of digits in the number is %d", countDigits(N));

    return 0;
}
