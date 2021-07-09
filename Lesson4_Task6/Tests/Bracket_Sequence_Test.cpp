#include "gtest/gtest.h"
#include "Bracket_Sequence.h"

TEST(BracketSequenceTestCase, Test_1)
{
    char str[50] = "";
    EXPECT_TRUE(isCorrectBracketSequence(str));
}

TEST(BracketSequenceTestCase, Test_2)
{
    char str[50] = "dfgd234@#";
    EXPECT_TRUE(isCorrectBracketSequence(str));
}

TEST(BracketSequenceTestCase, Test_3)
{
    char str[50] = "()[()]{()([[{}]])()}";
    EXPECT_TRUE(isCorrectBracketSequence(str));
}

TEST(BracketSequenceTestCase, Test_4)
{
    char str[50] = "())()";
    EXPECT_TRUE(isCorrectBracketSequence(str));
}

TEST(BracketSequenceTestCase, Test_5)
{
    char str[50] = "([{}])[]";
    EXPECT_TRUE(isCorrectBracketSequence(str));
}
