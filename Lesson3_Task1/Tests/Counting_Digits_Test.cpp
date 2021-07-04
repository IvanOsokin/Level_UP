#include "gtest/gtest.h"
#include "Count_Digits.h"


TEST(GetCountTestCase, Test_1)
{
    EXPECT_EQ(countDigits(1), 1);
}

TEST(GetCountTestCase, Test_2)
{
    EXPECT_EQ(countDigits(12), 2);
}

TEST(GetCountTestCase, Test_3)
{
    EXPECT_EQ(countDigits(12345), 5);
}

TEST(GetCountTestCase, Test_4)
{
    EXPECT_EQ(countDigits(0), 1);
}

TEST(GetCountTestCase, Test_5)
{
    EXPECT_EQ(countDigits(-345), 3);
}
