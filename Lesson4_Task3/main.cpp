//Дана матрица размером 7х7. Поменять местами k-й столбец с k-ой строкой.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    constexpr int size = 7;

    printf("An initial matrix:\n");
    int matr[size][size];
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            matr[i][j] = rand() % 101;
            printf("%3d ", matr[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter a number for replacement: ");
    int k;
    scanf("%d", &k);

    int temp;
    for(int i = 0; i < size; ++i)
    {
        temp = matr[i][k];
        matr[i][k] = matr[k][i];
        matr[k][i] = temp;
    }

    printf("\nA new matrix:\n");
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            printf("%3d ", matr[i][j]);
        }
        printf("\n");
    }

    return 0;
}
