//Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой.

#include <stdio.h>
#include <stdlib.h>
#include "Matrix.h"

int main()
{
    constexpr int size = 7;

    int** matrix = new int*[size];
    int** pMatrix = matrix;
    for(int i = 0; i < size; ++i)
    {
        *pMatrix = new int[size];
        ++pMatrix;
    }
    printf("An initial matrix:\n");

    initializingMatrix(matrix, size);
    printMatrix(matrix, size);

    printf("\nEnter a number for replacement: ");
    int value;
    scanf("%d", &value);

    printf("\nA new matrix:\n");
    pMatrix = replaceRowAndColumn(matrix, size, value);
    printMatrix(pMatrix, size);

    for(int i = 0; i < size; ++i)
    {
        delete[] *pMatrix;
        *pMatrix = nullptr;
        ++pMatrix;
    }
    matrix = nullptr;

    return 0;
}
