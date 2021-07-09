#include <stdio.h>
#include <string.h>
#include "My_String.h"

char* getString()
{
    char* initString = new char[255];
    printf("Enter a string: ");
    gets(initString);
    return initString;
}

char* resultString(char* initString)
{
    char* resString = new char[strlen(initString) + 1];
    char* tempWord = new char[50];
    char* tempInitString = initString;
    char* tempRes = resString;
    int wordLength = 0;
    bool isBegin = true;
    while(*tempInitString != '\0')
    {
        if(*tempInitString == ' ')
        {
            ++tempInitString;
        }
        sscanf(tempInitString, "%s", tempWord);
        wordLength = strlen(tempWord);
        if(wordLength & 0x1)
        {
            tempInitString += wordLength;
        }
        else
        {
            if(isBegin)
            {
                strncpy(resString, tempWord, wordLength);
                resString += wordLength;
                tempInitString += wordLength;
                isBegin = false;
            }
            else
            {
                *resString = ' ';
                ++resString;
                strncpy(resString, tempWord, wordLength);
                resString += wordLength;
                tempInitString += wordLength;
            }
        }
        if(*tempInitString == ' ')
        {
            ++tempInitString;
        }
    }
    *resString = '\0';

    delete[] tempWord;
    tempWord = nullptr;
    tempInitString = nullptr;
    resString = nullptr;

    return tempRes;
}
