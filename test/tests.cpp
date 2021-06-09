#include <gtest/gtest.h>
#include "textgen.h"

TEST(Test1, point1)
{
    vector<string> words{ "Hello", "World" };
    GenMarkov Gen(words, 2, 1000);
    string output = Gen.GenText();
    if (output[0] = 'H')
        ASSERT_STREQ("Hello World ", output.c_str());
    else
        ASSERT_STREQ("World ", output.c_str());
}

TEST(Test2, point2)
{
    vector<string> words{ "Hello", "World" };
    GenMarkov Gen(words, 2, 1000);
    ASSERT_STREQ("Hello World ", Gen.GenText().c_str());
}

TEST(Test3, point3)
{
    map<deque<string>, vector<string>> str;
    str[{ "Hello", "World" }].push_back("!");
    str[{"World", "!"}].push_back("<Last_Prefix>");
    GenMarkov Gen(str, 1000);
    string output = Gen.GenText();
    if (output[0] == 'H')
        ASSERT_STREQ("Hello World ! ", output.c_str());
    else
        ASSERT_EQ('W', output[0]);
}

TEST(Test4, point4)
{
    map<deque<string>, vector<string>> str;
    str[{ "Hello", "World" }].push_back("!");
    str[{ "Hello", "World" }].push_back("?");
    str[{"World", "!"}].push_back("<Last_Prefix>");
    str[{"World", "?"}].push_back("<Last_Prefix>");

    GenMarkov Gen(str, 1000);
    string output = Gen.GenText();
    if (output[0] == 'W')
        ASSERT_EQ('W', output[0]);
    else if (output[output[output.length() - 2]] == 'H')
        ASSERT_STREQ("Hello World ! ", output.c_str());
    else
        ASSERT_STREQ("Hello World ? ", output.c_str());
}

TEST(Test5, point5)
{
    vector<string> words{ "Hello", "again", "my", "friend", "hello", "again." };
    GenMarkov Gen(words, 2, 100);
    string output = Gen.GenText();
    if (output[output.length() - 2] == '.')
        ASSERT_EQ('.', output[output.length() - 2]);
    else
        ASSERT_LE(100, output.size());
}