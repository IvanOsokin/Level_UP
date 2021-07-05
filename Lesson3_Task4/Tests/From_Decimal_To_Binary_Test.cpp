#include "gtest/gtest.h"
#include "Dec_To_Bin.h"

TEST(DecimalToBinaryTestCase, Test_1)
{
    EXPECT_STREQ("00000000000000000000000000000000", decimalToBinary(0));
}

TEST(DecimalToBinaryTestCase, Test_2)
{
    EXPECT_STREQ("00000000000000000000000000000011", decimalToBinary(3));
}

TEST(DecimalToBinaryTestCase, Test_3)
{
    EXPECT_STREQ("00000000000000000000000000100000", decimalToBinary(32));
}

TEST(DecimalToBinaryTestCase, Test_4)
{
    EXPECT_STREQ("00000000000000000000010101000010", decimalToBinary(1346));
}
