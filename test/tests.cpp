// Copyright 2021 GHA Test Team
#include <gtest/gtest.h>
#include "textgen.h"

TEST(task1, test1)
{
    vector<string> words{"Don't", "stop", "me", "now!"};
    Markov Gen(words, 3, 100);
    string output = Gen.TextGen();
    if (output[0] = 'D')
        ASSERT_STREQ("Don't stop me now! ", output.c_str());
    else
        ASSERT_STREQ("stop me now! ", output.c_str());
}

TEST(task2, test1)
{
    vector<string> words{"Hello", "world"};
    Markov Gen(words, 2, 100);
    ASSERT_STREQ("Hello world ", Gen.TextGen().c_str());
}

TEST(task3, test1)
{
    map<deque<string>, vector<string>> dict;
    dict[{"Enjoy", "your"}].push_back("flight");
    dict[{"your", "flight"}].push_back("<Last_Prefix>");
    Markov Gen(dict, 100);
    string output = Gen.TextGen();
    if (output[0] == 'E')
        ASSERT_STREQ("Enjoy your flight ", output.c_str());
    else
        ASSERT_EQ('y', output[0]);
}

TEST(task4, test1)
{
    map<deque<string>, vector<string>> dict;
    dict[{"Enjoy", "your"}].push_back("life");
    dict[{"Enjoy", "your"}].push_back("moment");
    dict[{"your", "life"}].push_back("<Last_Prefix>");
    dict[{"your", "moment"}].push_back("<Last_Prefix>");

    Markov Gen(dict, 100);
    string output = Gen.TextGen();
    if (output[0] == 'y')
        ASSERT_EQ('y', output[0]);
    else if (output[output[output.length() - 2]] == 'e')
        ASSERT_STREQ("Enjoy your life ", output.c_str());
    else
        ASSERT_STREQ("Enjoy your moment ", output.c_str());
}

TEST(task5, test1)
{
    vector<string> words{"Do", "you", "want", "to", "be", "yourself,", "when", "you", "are,", "not", "it."};
    Markov Gen(words, 2, 100);
    string output = Gen.TextGen();
    if (output[output.length() - 2] == '.')
        ASSERT_EQ('.', output[output.length() - 2]);
    else
        ASSERT_LE(100, output.size());
}