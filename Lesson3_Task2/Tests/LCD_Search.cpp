#include "gtest/gtest.h"
#include "Least_Common_Divisor_Search.h"

TEST(LeastCommonDivisorSearch, Test_1)
{
    int LCD = leastCommonDivisorSearch(6, 9, 36);
    EXPECT_EQ(LCD, 3);
}

TEST(LeastCommonDivisorSearch, Test_2)
{
    int LCD = leastCommonDivisorSearch(85, 17, 119);
    EXPECT_EQ(LCD, 17);
}

TEST(LeastCommonDivisorSearch, Test_3)
{
    int LCD = leastCommonDivisorSearch(19, 17, 8);
    EXPECT_EQ(LCD, 1);
}
