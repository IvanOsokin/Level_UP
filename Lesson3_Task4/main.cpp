//Перевести число из десятичной системы счисления в двоичную.

#include <stdio.h>
#include "Get_Integer.h"
#include "Dec_To_Bin.h"

int main()
{
    int signedDecimalNum = getInteger();
    printf("Entered number in binary is ");
    decimalToBinary(signedDecimalNum);

    return 0;
}
