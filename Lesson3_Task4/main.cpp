/*
 *
 * Перевести число из десятичной системы счисления в двоичную.
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    //Считать десятичное число с клавиатуры
    int decimalNum;
    int isValidRead = 0;
    while(isValidRead == 0)
    {
        printf("Enter any integer number: ");
        if(!(isValidRead = scanf("%d", &decimalNum)))
        {
            printf("The enter is incorrect!!!\nTry to enter again!!!\n\n");
            fflush(stdin);
        }
    }

    //Инвертированное двоичное число (начинается с 1, чтобы не потерять значащие нули в начале)
    int tempBinaryNum = 1;
    int countDigits = 0;
    int tempDecimalNum = abs(decimalNum);
    do
    {
        ++countDigits;
        tempBinaryNum = tempBinaryNum * 10 + tempDecimalNum % 2;
    }while(tempDecimalNum /= 2);

    //Двоичная форма записи исходного числа
    int binaryNum = tempBinaryNum  == 10 ? 0 : 1;
    for (int i = 1; i < countDigits; ++i)
    {
        tempBinaryNum /= 10;
        binaryNum *= 10;
        binaryNum += tempBinaryNum % 10;
    }
    if(decimalNum < 0)
    {
       binaryNum *= (-1);
    }

    printf("\n%d - from decimal to binary is %d", decimalNum, binaryNum);

    return 0;
}
