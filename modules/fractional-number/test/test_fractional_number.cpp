//
//  test_fractional_number.cpp
//  fractional_number
//
//  Created by Aleksei Khomenko.
//  Copyright © 2018 Aleksei Khomenko. All rights reserved.
//

#include <gtest/gtest.h>

#include <string>

#include "include/fractional_number.h"

TEST(FractionNumberTest, Can_Create_With_Chislitel_And_Znamenatel) {
    // Arrange
    int chislitel = 5;
    int znamenatel = 6;

    // Act
    FractionalNumber r(chislitel, znamenatel);

    // Assert
    EXPECT_EQ(chislitel, r.getNumerator());
    EXPECT_EQ(znamenatel, r.getDenominator());
}

TEST(FractionNumberTest, Can_Create_Via_Copying) {
    // Arrange
    FractionalNumber r(50, 60);

    // Act
    FractionalNumber expected_r = r;

    // Assert
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumberTest, Can_Create_Via_Assignment) {
    // Arrange
    FractionalNumber r(50, 60);
    FractionalNumber expected_r;

    // Act
    r = expected_r;

    // Assert
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumberTest, Can_Create_const) {
    // Arrange
    FractionalNumber r1(1, 2);
    FractionalNumber r2(1, 2);
    FractionalNumber res_r(1, 1);

    // Act
    FractionalNumber r = r1 + r2;

    // Assert
    EXPECT_EQ(r, res_r);
}

TEST(FractionNumberTest, Number_Is_Equal) {
    // Arrange
    FractionalNumber r1;
    FractionalNumber r2(0, 1);

    // Act & Assert
    EXPECT_TRUE(r1 == r2);
}

TEST(FractionNumberTest, Can_Add_Rational) {
    // Arrange
    FractionalNumber r1(1, 5), r2(12, 43);

    // Act
    FractionalNumber r = r1 + r2;

    // Assert
    FractionalNumber expected_r(103, 215);
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumberTest, Can_Difference_Rational) {
    // Arrange
    FractionalNumber r1(75, 165);
    FractionalNumber r2(87, 170);

    // Act
    FractionalNumber r = r1 - r2;

    // Assert
    FractionalNumber expected_r(-1605, 28050);
    EXPECT_EQ(expected_r, r);
}
TEST(FractionNumberTest, Can_Set_Chislitel) {
    // Arrange
    FractionalNumber r;
    int chislitel = 35;

    // Act
    r.setNumerator(chislitel);

    // Assert
    EXPECT_EQ(chislitel, r.getNumerator());
}

TEST(FractionNumberTest, Can_Set_Znamenatel) {
    // Arrange
    FractionalNumber r;
    int znamenatel = 26.0;

    // Act
    r.setDenominator(znamenatel);

    // Assert
    EXPECT_EQ(znamenatel, r.getDenominator());
}

TEST(FractionNumberTest, Can_Multiplication_Rational) {
    // Arrange
    FractionalNumber r1(15, 37);
    FractionalNumber r2(3, 17);

    // Act
    FractionalNumber r = r1 * r2;

    // Assert
    FractionalNumber expected_r(45, 629);
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumberTest, Can_Division_Rational) {
    // Arrange
    FractionalNumber r1(23, 54);
    FractionalNumber r2(-135, 23);

    // Act
    FractionalNumber r = r2 / r1;

    // Assert
    FractionalNumber expected_r(-7290, 529);
    EXPECT_EQ(expected_r, r);
}

TEST(FractionNumberTest, Do_Throw_When_Division_By_Zero) {
    // Arrange
    FractionalNumber r1(0, 6);
    FractionalNumber r2(12, 45);

    // Act & Assert
    EXPECT_THROW(r2 / r1, std::string);
}

TEST(FractionNumberTest, Number_Is_Equal_To_Itself) {
    // Arrange
    FractionalNumber r(50, 194);

    // Act & Assert
    EXPECT_TRUE(r == r);
}

TEST(FractionNumberTest, Equal_Numbers_Are_Equal) {
    // Arrange
    FractionalNumber r1(1, 8);
    FractionalNumber r2(1, 8);

    // Act & Assert
    EXPECT_EQ(r1, r2);
}

TEST(FractionNumberTest, Not_Equal_Numbers_Are_Not_Equal) {
    // Arrange
    FractionalNumber r1(1, 2);
    FractionalNumber r2(1, 4);

    // Act & Assert
    EXPECT_FALSE(r1 == r2);
}

TEST(FractionNumberTest, Do_Create_Throw) {
    // Arrange & Act & Assert
    EXPECT_THROW(FractionalNumber r1(1, 0), std::string);
}

TEST(FractionNumberTest, Different_Numbers_Not_Equal) {
    // Arrange
    FractionalNumber r1(1, 2);
    FractionalNumber r2(1, 4);

    // Act & Assert
    EXPECT_TRUE(r1 != r2);
}
