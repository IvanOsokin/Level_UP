#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

void initializingMatrix(int** matrix, int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            *(*(matrix + i) + j) = rand() % 101;
        }
    }
}

void printMatrix(int** matrix, int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            printf("%3d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int** replaceRowAndColumn(int** matrix, int size, int value)
{
    int temp;
    for(int i = 0; i < size; ++i)
    {
        temp = *(*(matrix + i) + value);
        *(*(matrix + i) + value) = *(*(matrix + value) + i);
        *(*(matrix + value) + i) = temp;
    }

    return matrix;
}
