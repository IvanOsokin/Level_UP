#include "gtest/gtest.h"
#include "Count_Digits.h"
/*
TEST(GetIntegerTestCase, Test_1)
{
    int n = getNumber();
    EXPECT_EQ(n, -1);
}

TEST(GetIntegerTestCase, Test_2)
{
    int n = getNumber();
    EXPECT_EQ(n, 0);
}

TEST(GetIntegerTestCase, Test_3)
{
    int n = getNumber();
    EXPECT_EQ(n, 1);
}

TEST(GetIntegerTestCase, Test_4)
{
    int n = getNumber();
    EXPECT_EQ(n, 12345);
}
*/

TEST(GetCountTestCase, Test_1)
{
    //int n = countDigits(1);
    EXPECT_EQ(countDigits(1), 1);
}

TEST(GetCountTestCase, Test_2)
{
    EXPECT_EQ(countDigits(12), 2);
}

TEST(GetCountTestCase, Test_3)
{
    EXPECT_EQ(countDigits(12345), 4);
}
