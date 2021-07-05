#include <stdio.h>
#include <limits.h>
#include "Dec_To_Bin.h"

char* decimalToBinary(int signedDecimalNum)
{
    const int size = sizeof(signedDecimalNum) * CHAR_BIT;

    char* pBinaryNum = new char[size];
    char* temp = pBinaryNum;

    unsigned int unsignedDecimalNum = signedDecimalNum;

    for(int i = size - 1; i >= 0; --i)
    {
        *temp = (unsignedDecimalNum & (1 << i)) ? '1' : '0';
        ++temp;
    }
    *temp = '\0';
    temp = nullptr;

    return pBinaryNum;
}
