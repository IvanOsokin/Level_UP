#include "gtest/gtest.h"
#include "Matrix.h"

TEST(SumTestCase, Test_1)
{
    constexpr int size = 4;

    int initArray[size][size] = {{0, 8, 8, 0},
                                 {1, 3, 1, 1},
                                 {2, 2, 2, 2},
                                 {3, 3, 3, 3}};
    int** pInitArray = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        *(pInitArray + i) = new int[size];
        *(pInitArray + i) = &(initArray[i][0]);
    }

    EXPECT_EQ(22, sum(pInitArray, size));

    pInitArray = nullptr;
}

TEST(SumTestCase, Test_2)
{
    constexpr int size = 4;

    int initArray[size][size] = {{0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0}};
    int** pInitArray = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        *(pInitArray + i) = new int[size];
        *(pInitArray + i) = &(initArray[i][0]);
    }

    EXPECT_EQ(0, sum(pInitArray, size));

    pInitArray = nullptr;
}
