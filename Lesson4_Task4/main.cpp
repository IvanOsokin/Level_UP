//Вычислить сумму элементов матрицы, лежащих слева от побочной диагонали.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    constexpr int size = 5;

    printf("An initial matrix:\n");
    int matrix[size][size];
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            matrix[i][j] = rand() % 10;
            printf("%3d", matrix[i][j]);
        }
        printf("\n");
    }

    int sum = 0;
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            if(i + j < size - 1)
            {
                sum += matrix[i][j];
            }
        }
    }

    printf("\nSum is %d", sum);
    return 0;
}
