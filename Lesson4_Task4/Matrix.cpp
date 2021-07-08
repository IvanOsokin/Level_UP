#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int** initializingMatrix(int size)
{
    int** matrix = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        *(matrix + i) = new int[size];
        for(int j = 0; j < size; ++j)
        {
            *(*(matrix + i) + j) = rand() % 10;
        }
    }

    return matrix;
}

void printMatrix(int** matrix, int size)
{
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            printf("%3d", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

int sum(int** matrix, int size)
{
    int result = 0;
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(i + j < size - 1)
            {
                result += *(*(matrix + i) + j);
            }
        }
    }
    return result;
}
