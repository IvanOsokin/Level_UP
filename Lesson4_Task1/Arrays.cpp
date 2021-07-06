#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

void initializingArray(int* pArray, int size)
{
    printf("An initial array:\n");
    for(int i = 0; i < size; ++i)
    {
        *(pArray + i) = rand() % 201 - 100;
        printf("%d ", *(pArray + i));
    }
    printf("\n");
}

int* replacementLastNegAndMax(int* pArray, int size)
{
    int maxElem = INT_MIN;
    int index = 0;
    for(int i = 0; i < size; ++i)
    {
        if(*(pArray + i) > maxElem)
        {
            maxElem = *(pArray + i);
            index = i;
        }
    }

    bool isNegativeExisted = false;
    for(int i = size - 1; i >= 0 && !isNegativeExisted; --i)
    {
        if(*(pArray + i) < 0)
        {
            int temp = *(pArray + i);
            *(pArray + i) = maxElem;
            *(pArray + index) = temp;
            isNegativeExisted = true;
        }
    }

    if(isNegativeExisted)
    {
        int* newArray = new int[size];
        for(int i = 0; i < size; ++i)
        {
            *(newArray + i) = *(pArray + i);
        }
        return newArray;
    }
    else
    {
        return pArray;
    }
}
