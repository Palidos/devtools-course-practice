// Copyright 2018 Gusev Alexandr

#include <gtest/gtest.h>
#include <string>
#include "include/Vigner_code.h"

TEST(Gusev_Alexandr_VignerCodeTest, Can_Get_Symbol) {
    // Arrange
    Vigner_code vigner;
    char sym = 'e';
    int res;
    int ans = 4;
    // Act
    res = vigner.Keycode(sym);
    // Assert
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VignerCodeTest, Can_Encode_Symbol) {
    // Arrange
    Vigner_code vigner;
    std::string Text = "abcABC";
    std::string Key = "abc";
    std::string res;
    std::string ans = "bdfBDF";
    // Act
    res = vigner.Encode(Text, Key);
    // Assert
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VignerCodeTest, Can_Decode_Symbol) {
    // Arrange
    Vigner_code vigner;
    std::string Text = "bdfBDF";
    std::string Key = "abc";
    std::string res;
    std::string ans = "abcABC";
    // Act
    res = vigner.Decode(Text, Key);
    // Assert
    EXPECT_EQ(res, ans);
}
TEST(Gusev_Alexandr_VignerCodeTest, Encode_and_Decode_Symbol) {
    // Arrange
    Vigner_code vigner;
    std::string Text = "ajffAZBtC";
    std::string Key = "abcZs";
    std::string res, res2;
    // Act
    res = vigner.Encode(Text, Key);
    res2 = vigner.Decode(res, Key);
    // Assert
    EXPECT_EQ(res2, Text);
}
