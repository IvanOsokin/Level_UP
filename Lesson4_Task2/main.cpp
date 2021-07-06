//Определить местоположение элементов массива А (30), не встречающихся в массиве В (15).

#include <stdio.h>
#include <stdlib.h>
#include "Arrays.h"

int main()
{
    constexpr int sizeA = 30;
    constexpr int sizeB = 15;

    printf("Array A:\n");
    int arrayA[sizeA];
    initializingArray(arrayA, sizeA);
    printArray(arrayA, sizeA);

    printf("\n\nArray B:\n");
    int arrayB[sizeB];
    initializingArray(arrayB, sizeB);
    printArray(arrayB, sizeB);

    int cntUnique = -1;
    int* pUniqueElem = uniqueInArrayA(arrayA, arrayB, sizeA, sizeB, &cntUnique);

    printf("\n\nThe array of indexes of unique elements:\n");
    for(int i = 0; i <= cntUnique; ++i)
    {
        printf("%d ", *(pUniqueElem + i));
    }

    delete[] pUniqueElem;
    pUniqueElem = nullptr;

    return 0;
}
