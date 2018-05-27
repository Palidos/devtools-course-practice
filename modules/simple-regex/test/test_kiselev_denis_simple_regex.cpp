// Copyright 2018 Kiselev Denis

#include <gtest/gtest.h>

#include "include/simple_regex.h"

TEST(Kiselev_Denis_SimpleRegexTest, Can_Create_SimpleRegex) {
    // Arrange
    const char* regex = "Hel\\wo, wor\\w\\w!";

    // Act
    SimpleRegex myRegex(regex);

    // Assert
    EXPECT_EQ(regex, myRegex.getRegex());
}

TEST(Kiselev_Denis_SimpleRegexTest, Can_Get_Regex) {
    // Arrange
    const char* regex = "Hel\\wo, lab\\d!";

    // Act
    SimpleRegex myRegex(regex);

    // Assert
    EXPECT_EQ(regex, myRegex.getRegex());
}

TEST(Kiselev_Denis_SimpleRegexTest, Can_Set_Regex) {
    // Arrange
    const char* regex   = "\\d\\d-\\d\\d";
    const char* regex1  = "\\d\\d\\d\\d";

    // Act
    SimpleRegex myRegex(regex);
    EXPECT_EQ(regex, myRegex.getRegex());
    myRegex.setRegex(regex1);

    // Assert
    EXPECT_EQ(regex1, myRegex.getRegex());
}

TEST(Kiselev_Denis_SimpleRegexTest, IsMatch_Is_True_When_Match_Exist) {
    // Arrange
    const char* regex   = "\\wy \\Day\\W\\d";
    const char* str     = "Today May 2";

    // Act
    SimpleRegex myRegex(regex);

    // Assert
    EXPECT_EQ(true, myRegex.isMatch(str));
}

TEST(Kiselev_Denis_SimpleRegexTest, IsMatch_Is_False_When_Match_Dont_Exist) {
    // Arrange
    const char* regex   = "May\\w\\d";
    const char* regex1  = "Ma\\d";
    const char* regex2  = "M\\\\ay";
    const char* str     = "Today May 2";

    // Act
    SimpleRegex myRegex(regex);
    EXPECT_NE(true, myRegex.isMatch(str));
    myRegex.setRegex(regex1);
    EXPECT_NE(true, myRegex.isMatch(str));
    myRegex.setRegex(regex2);

    // Assert
    EXPECT_NE(true, myRegex.isMatch(str));
}

TEST(Kiselev_Denis_SimpleRegexTest, Exception_When_Invalid_Metasymbol) {
    // Arrange
    const char* regex   = "\\\\WinRa\\r";
    const char* str     = "C:\\Program Files\\WinRar";

    // Act
    SimpleRegex myRegex(regex);

    // Assert
    ASSERT_ANY_THROW(myRegex.isMatch(str));
}

TEST(Kiselev_Denis_SimpleRegexTest, Can_Get_Match) {
    // Arrange
    const char* regex   = "Ma\\w \\d";
    const char* str     = "Today May 2";
    const char* match   = "May 2";
    char buffer[10];

    // Act
    SimpleRegex myRegex(regex);
    if (myRegex.isMatch(str)) {
        myRegex.getMatch(buffer, 10);
    }

    // Assert
    EXPECT_EQ(0, strcmp(buffer, match));
}

TEST(Kiselev_Denis_SimpleRegexTest, Empty_Match_When_IsMatch_Is_False) {
    // Arrange
    const char* regex = "Ma\\W \\d";
    const char* str = "Today May 2";
    const char* match = "";
    char buffer[10];

    // Act
    SimpleRegex myRegex(regex);
    if (!myRegex.isMatch(str)) {
        myRegex.getMatch(buffer, 10);
    }

    // Assert
    EXPECT_EQ(0, strcmp(buffer, match));
}

TEST(Kiselev_Denis_SimpleRegexTest, GetMatch_Exception_With_Small_Buffer) {
    // Arrange
    const char* regex = "Ma\\w \\d";
    const char* str = "Today May 2";
    char buffer[3];

    // Act
    SimpleRegex myRegex(regex);
    myRegex.isMatch(str);

    // Assert
    ASSERT_ANY_THROW(myRegex.getMatch(buffer, 3));
}

TEST(Kiselev_Denis_SimpleRegexTest, Can_Get_Index_Of_Match) {
    // Arrange
    const char* regex = "Ma\\w \\d";
    const char* str = "Today May 2";
    int index = 0;

    // Act
    SimpleRegex myRegex(regex);
    if (myRegex.isMatch(str)) {
        index = myRegex.getMatchIndex();
    }

    // Assert
    EXPECT_EQ(6, index);
}

TEST(Kiselev_Denis_SimpleRegexTest, Can_Get_Negative_Index_Of_Match) {
    // Arrange
    const char* regex = "Ma\\w \\D";
    const char* str = "Today May 2";
    int index = 0;

    // Act
    SimpleRegex myRegex(regex);
    if (!myRegex.isMatch(str)) {
        index = myRegex.getMatchIndex();
    }

    // Assert
    EXPECT_EQ(-1, index);
}
