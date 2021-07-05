//Поменять местами максимальный и последний отрицательный элементы массива M(40).

#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

int main()
{
    constexpr int size = 40;
    int* pArray = new int[size];
    initializingArray(pArray, size);
    int* tempPtr = replacementLastNegAndMax(pArray, size);
    if(tempPtr != pArray)
    {
        printf("A new array:\n");
        for(int i = 0; i < size; ++i)
        {
            printf("%d ", *(pArray + i));
        }
        printf("\n");
    }
    else
    {
        printf("There are no negative elements!");
    }

    delete[] tempPtr;
    tempPtr = nullptr;
    if(pArray)
    {
        delete[] pArray;
        pArray = nullptr;
    }
    return 0;
}
