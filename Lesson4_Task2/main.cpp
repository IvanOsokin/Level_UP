//Определить местоположение элементов массива А (30), не встречающихся в массиве В (15).

#include <stdio.h>
#include <stdlib.h>

int main()
{
    constexpr int sizeA = 30;
    constexpr int sizeB = 15;

    printf("Array A:\n");
    int arrayA[sizeA];
    for(int i = 0; i < sizeA; ++i)
    {
        arrayA[i] = rand() % 31;
        printf("%d ", arrayA[i]);
    }
    printf("\n\nArray B:\n");
    int arrayB[sizeB];
    for(int i = 0; i < sizeB; ++i)
    {
        arrayB[i] = rand() % 31;
        printf("%d ", arrayB[i]);
    }

    int arrayIndex[sizeA];
    int k = 0;
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
            arrayIndex[k++] = i;
        }
    }

    printf("\n\nThe array of indexes of unique elements:\n");
    for(int i = 0; i < k; ++i)
    {
        printf("%d ", arrayIndex[i]);
    }
    return 0;
}
