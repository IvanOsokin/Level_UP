#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

void initializingArray(int array[], int size)
{
    printf("An initial array:\n");
    for(int i = 0; i < size; ++i)
    {
        array[i] = rand() % 201 - 100;
        printf("%d ", array[i]);
    }
    printf("\n");
}

void findMaxElem(int array[], int size, int* maxElem, int* index)
{
    for(int i = 0; i < size; ++i)
    {
        if(array[i] > *maxElem)
        {
            *maxElem = array[i];
            *index = i;
        }
    }
}

void replacementLastNegAndMax(int array[], int size, int* maxElem, int* index)
{
    bool isNegativeExisted = false;
    for(int i = size - 1; i >= 0 && !isNegativeExisted; --i)
    {
        if(array[i] < 0)
        {
            int temp = array[i];
            array[i] = *maxElem;
            array[*index] = temp;
            isNegativeExisted = true;
        }
    }

    if(isNegativeExisted)
    {
        printf("A new array:\n");
        for(int i = 0; i < size; ++i)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
    }
    else
    {
        printf("There are no negative elements!");
    }
}
