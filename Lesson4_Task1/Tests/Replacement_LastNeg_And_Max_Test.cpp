#include "gtest/gtest.h"
#include "Arrays.h"

TEST(ReplacementTestCase, Test_1)
{
    constexpr int size = 10;
    int initArray[size] = {1, 34, 0, -23, 60, -234, 6, 51, -1, 31};
    int resultArray[size] = {1, 34, 0, -23, -1, -234, 6, 51, 60, 31};
    EXPECT_EQ(memcmp(replacementLastNegAndMax(initArray, size), resultArray, sizeof (initArray)), 0);
}

TEST(ReplacementTestCase, Test_2)
{
    constexpr int size = 10;
    int initArray[size] = {1, 34, 0, 23, 60, 234, 6, 51, 1, 31};
    int resultArray[size] = {1, 34, 0, 23, 60, 234, 6, 51, 1, 31};
    EXPECT_EQ(memcmp(replacementLastNegAndMax(initArray, size), resultArray, sizeof (initArray)), 0);
}

TEST(ReplacementTestCase, Test_3)
{
    constexpr int size = 10;
    int initArray[size] = {-1, -34, -5, -23, -60, -234, -6, -51, -72, -31};
    int resultArray[size] = {-31, -34, -5, -23, -60, -234, -6, -51, -72, -1};
    EXPECT_EQ(memcmp(replacementLastNegAndMax(initArray, size), resultArray, sizeof (initArray)), 0);
}
