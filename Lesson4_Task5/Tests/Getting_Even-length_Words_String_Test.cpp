#include "gtest/gtest.h"
#include "My_String.h"

TEST(GetStringTestCase, Test_1)
{
    char initString[50] = "q ww eee rrrr ttttt";
    char resString[50] = "ww rrrr";

    EXPECT_EQ(strcmp(resultString(initString), resString), 0);
}

TEST(GetStringTestCase, Test_2)
{
    char initString[50] = " q ww eee rrrr ttttt";
    char resString[50] = "ww rrrr";

    EXPECT_EQ(strcmp(resultString(initString), resString), 0);
}

TEST(GetStringTestCase, Test_3)
{
    char initString[50] = "q eee ttttt";
    char resString[50] = "";

    EXPECT_EQ(strcmp(resultString(initString), resString), 0);
}

TEST(GetStringTestCase, Test_4)
{
    char initString[50] = "qq eeee tttttt ";
    char resString[50] = "qq eeee tttttt";

    EXPECT_EQ(strcmp(resultString(initString), resString), 0);
}

TEST(GetStringTestCase, Test_5)
{
    char initString[50] = "";
    char resString[50] = "";

    EXPECT_EQ(strcmp(resultString(initString), resString), 0);
}
