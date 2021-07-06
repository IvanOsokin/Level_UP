#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

void initializingArray(int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 31;
    }
}

void printArray(int array[], int size)
{
    for(int i = 0; i < size; ++i)
    {
        printf("%d ", array[i]);
    }
}

int* uniqueInArrayA(int arrayA[], int arrayB[], int sizeA, int sizeB, int* cntUnique)
{
    int* pUniqueElem = new int[sizeA];
    bool isUnique;
    for(int i = 0; i < sizeA; ++i)
    {
        isUnique = true;
        for(int j = 0; j < sizeB; ++j)
        {
            if(arrayA[i] == arrayB[j])
            {
                isUnique = false;
                break;
            }
        }
        if(isUnique)
        {
            ++(*cntUnique);
            *(pUniqueElem + *cntUnique) = i;
        }
    }

    return pUniqueElem;
}
