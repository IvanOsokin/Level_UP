#include "gtest/gtest.h"
#include "Arrays.h"

TEST(RetrievingUniqueElementsTestCase, Test_1)
{
    constexpr int sizeA = 10;
    constexpr int sizeB = 5;
    int cnt = -1;
    int arrayA[sizeA] = {-5, 4, 0, 10, -2, 5, 7, -2, -10, 9};
    int arrayB[sizeB] = {-7, 8, 2, 1, -3};

    int expectedArray[5] = {0, 1, 2, 3, 4};
    int* gottenArray = uniqueInArrayA(arrayA, arrayB, sizeA, sizeB, &cnt);
    EXPECT_EQ(memcmp(gottenArray, expectedArray, sizeof(expectedArray)), 0);
}

TEST(RetrievingUniqueElementsTestCase, Test_2)
{
    constexpr int sizeA = 10;
    constexpr int sizeB = 5;
    int cnt = -1;
    int arrayA[sizeA] = {-5, 4, 0, 10, -2, 5, 7, -2, -10, 9};
    int arrayB[sizeB] = {-5, 4, 0, 10, -2};

    int expectedArray[0];
    int* gottenArray = uniqueInArrayA(arrayA, arrayB, sizeA, sizeB, &cnt);
    EXPECT_EQ(memcmp(gottenArray, expectedArray, sizeof(expectedArray)), 0);
}

TEST(RetrievingUniqueElementsTestCase, Test_3)
{
    constexpr int sizeA = 10;
    constexpr int sizeB = 5;
    int cnt = -1;
    int arrayA[sizeA] = {-5, 4, 0, 10, -2, 5, 7, -2, -10, 9};
    int arrayB[sizeB] = {-6, 4, 0, 10, -3};

    int expectedArray[2] = {0, 4};
    int* gottenArray = uniqueInArrayA(arrayA, arrayB, sizeA, sizeB, &cnt);
    EXPECT_EQ(memcmp(gottenArray, expectedArray, sizeof(expectedArray)), 0);
}
