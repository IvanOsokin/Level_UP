#include "gtest/gtest.h"
#include "Matrix.h"

TEST(ReplacementRowColTestCase, Test_1)
{
    constexpr int size = 4;

    int initArray[size][size] = {{0, 0, 0, 0},
                                 {1, 1, 1, 1},
                                 {2, 2, 2, 2},
                                 {3, 3, 3, 3}};\
    int** pInitArray = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        *(pInitArray + i) = new int[size];
        for(int j = 0; j < size; ++j)
        {
            *(*(pInitArray + i) + j) = initArray[i][j];
        }
    }

    int resultArray[size][size] = {{0, 1, 2, 3},
                                   {0, 1, 1, 1},
                                   {0, 2, 2, 2},
                                   {0, 3, 3, 3}};
    int** pResultArray = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        *(pResultArray + i) = new int[size];
        for(int j = 0; j < size; ++j)
        {
            *(*(pResultArray + i) + j) = resultArray[i][j];
        }
    }

    constexpr int value = 0;

    int** pGottenArray = replaceRowAndColumn(pInitArray, size, value);

    EXPECT_EQ(memcmp(pGottenArray, pResultArray, sizeof(initArray)), 0);

    for(int i = 0; i < size; ++i)
    {
        delete[] *(pGottenArray + i);
        *(pGottenArray + i) = nullptr;
        delete[] *(pResultArray + i);
        *(pResultArray + i) = nullptr;
        *(pInitArray + i) = nullptr;
    }
    delete[] pGottenArray;
    pGottenArray = nullptr;
    delete[] pResultArray;
    pResultArray = nullptr;
    pInitArray = nullptr;
}
