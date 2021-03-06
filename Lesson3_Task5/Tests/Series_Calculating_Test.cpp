#include "gtest/gtest.h"
#include "Series_Calculating.h"

TEST(FactorialCalculatingTestCase, Test_1)
{
    EXPECT_EQ(doubleFactorial(0), 1);
}

TEST(FactorialCalculatingTestCase, Test_2)
{
    EXPECT_EQ(doubleFactorial(1), 1);
}

TEST(FactorialCalculatingTestCase, Test_3)
{
    EXPECT_EQ(doubleFactorial(8), 384);
}

TEST(FactorialCalculatingTestCase, Test_4)
{
    EXPECT_EQ(doubleFactorial(7), 105);
}

TEST(SeriesCalculatingTestCase, Test_1)
{
    EXPECT_NEAR(seriesCalculating(0.1), 0.100167, 0.00001);
}

TEST(SeriesCalculatingTestCase, Test_2)
{
    EXPECT_NEAR(seriesCalculating(0.15), 0.150562, 0.00001);
}

TEST(SeriesCalculatingTestCase, Test_3)
{
    EXPECT_NEAR(seriesCalculating(0.2), 0.201333, 0.00001);
}

