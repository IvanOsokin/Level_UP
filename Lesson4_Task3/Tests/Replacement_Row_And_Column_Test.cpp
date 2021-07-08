#include "gtest/gtest.h"
#include "Matrix.h"

TEST(ReplacementRowColTestCase, Test_1)
{
    constexpr int size = 4;

    int initArray[size][size] = {{0, 0, 0, 0},
                                 {1, 1, 1, 1},
                                 {2, 2, 2, 2},
                                 {3, 3, 3, 3}};
    int** pInitArray = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        *(pInitArray + i) = new int[size];
        *(pInitArray + i) = &(initArray[i][0]);
    }

    int resultArray[size][size] = {{0, 1, 2, 3},
                                   {0, 1, 1, 1},
                                   {0, 2, 2, 2},
                                   {0, 3, 3, 3}};
    int** pResultArray = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        *(pResultArray + i) = new int[size];
        *(pResultArray + i) = &(resultArray[i][0]);
    }

    constexpr int value = 0;

    int** pGottenArray = replaceRowAndColumn(pInitArray, size, value);
    int check;
    for(int i = 0; i < size; ++i)
    {
        check = memcmp(*(pGottenArray + i), *(pResultArray + i), sizeof(int) * size);
        if(check)
        {
            break;
        }
    }
    EXPECT_EQ(check, 0);
    for(int i = 0; i < size; ++i)
    {
        *(pGottenArray + i) = nullptr;
        *(pResultArray + i) = nullptr;
        *(pInitArray + i) = nullptr;
    }
    pGottenArray = nullptr;
    pResultArray = nullptr;
    pInitArray = nullptr;
}
