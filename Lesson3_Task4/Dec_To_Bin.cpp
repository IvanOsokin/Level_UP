#include <stdio.h>
#include <limits.h>
#include "Dec_To_Bin.h"

void decimalToBinary(int signedDecimalNum)
{
    unsigned int unsignedDecimalNum = signedDecimalNum;

    for(int i = sizeof(unsignedDecimalNum) * CHAR_BIT - 1; i >= 0; --i)
    {
        printf("%c", (unsignedDecimalNum & (1 << i)) ? '1' : '0');
    }
}
