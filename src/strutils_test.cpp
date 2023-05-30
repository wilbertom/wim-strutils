#include <gtest/gtest.h>
#include <strutils.hpp>

using namespace wim::strutils;

TEST(join, ASimpleStringWithASingleCharacterSeparator) {
    std::vector<std::string> str {"Hello", "world"};

    std::string result = join(str, " ");

    EXPECT_EQ(result, "Hello world");
}

TEST(join, WithAMultiCharacterSeparator) {
    std::vector<std::string> str {"Hello", "world"};

    std::string result = join(str, "||");

    EXPECT_EQ(result, "Hello||world");
}


TEST(join, JoiningAnEmptyVectorIsTheEmptyString) {
    std::vector<std::string> str {};

    std::string result = join(str, ",");

    EXPECT_EQ(result, "");
}


TEST(split, SplittingASimpleString) {
    std::string s = "Hello world";
    std::vector<std::string> expected = {"Hello", "world"};

    std::vector<std::string> result = split(s);

    EXPECT_EQ(result, expected);
}

TEST(split, SplittingAStringThatEndsWithTheSeparator) {
    std::string s = "Hello world ";
    std::vector<std::string> expected = {"Hello", "world"};

    std::vector<std::string> result = split(s);

    EXPECT_EQ(result, expected);
}

TEST(split, SplittingAStringWithConsecutiveInstancesOfTheSeparator) {
    std::string s = "  Hello   world  ";
    std::vector<std::string> expected = {"Hello", "world"};

    std::vector<std::string> result = split(s);

    EXPECT_EQ(result, expected);
}


TEST(split, SplittingWithADifferentSeparator) {
    std::string s = ",,,Hello, world,";
    std::vector<std::string> expected = {"Hello", " world"};

    std::vector<std::string> result = split(s, ',');

    EXPECT_EQ(result, expected);
}


TEST(tail, TailOfAString) {
    std::string s = "hello world";
    std::string expected = "ello world";

    std::string result = tail(s);

    EXPECT_EQ(result, expected);
}


TEST(tail, TailOfASingleCharacterString) {
    std::string s = "a";
    std::string expected = "";

    std::string result = tail(s);

    EXPECT_EQ(result, expected);
}

TEST(tail, TailOfAnEmptyString) {
    std::string s = "";
    std::string expected = "";

    std::string result = tail(s);

    EXPECT_EQ(result, expected);
}
