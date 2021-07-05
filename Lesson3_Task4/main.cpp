//Перевести число из десятичной системы счисления в двоичную.

#include <stdio.h>
#include "Get_Integer.h"
#include "Dec_To_Bin.h"

int main()
{
    int signedDecimalNum = getInteger();
    printf("Entered number in binary is ");
    char* pBinaryNum = decimalToBinary(signedDecimalNum);
    printf("%s", pBinaryNum);
    delete [] pBinaryNum;
    pBinaryNum = nullptr;

    return 0;
}
