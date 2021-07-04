#include "gtest/gtest.h"
#include "Exchange_Digits.h"

TEST(ExchangeDigitsTestCase, Test_1)
{
    EXPECT_EQ(exchangeDigits(0), 0);
}

TEST(ExchangeDigitsTestCase, Test_2)
{
    EXPECT_EQ(exchangeDigits(1), 1);
}

TEST(ExchangeDigitsTestCase, Test_3)
{
    EXPECT_EQ(exchangeDigits(12), 21);
}

TEST(ExchangeDigitsTestCase, Test_4)
{
    EXPECT_EQ(exchangeDigits(12345), 52341);
}

TEST(ExchangeDigitsTestCase, Test_5)
{
    EXPECT_EQ(exchangeDigits(-1234), -4231);
}
