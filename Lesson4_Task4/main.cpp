//Вычислить сумму элементов матрицы, лежащих слева от побочной диагонали.

#include <stdio.h>
#include "Matrix.h"

int main()
{
    constexpr int size = 5;

    printf("An initial matrix:\n");
    int** matrix = initializingMatrix(size);
    printMatrix(matrix, size);

    printf("\nSum is %d", sum(matrix, size));

    for(int i = 0; i < size; ++i)
    {
        delete[] *(matrix + i);
    }
    delete[] matrix;
    matrix = nullptr;

    return 0;
}
