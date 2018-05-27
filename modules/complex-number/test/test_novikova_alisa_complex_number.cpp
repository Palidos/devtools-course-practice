// Copyright 2018 Novikova Alisa

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Novikova_Alisa_ComplexNumberTest, Can_Create_Not_Zero) {
        // Arrange
        double re = 3.14;
        double im = 15.9;
        // Act
        ComplexNumber z(re, im);
        // Assert
        EXPECT_EQ(re, z.getRe());
        EXPECT_EQ(im, z.getIm());
}
TEST(Novikova_Alisa_ComplexNumberTest, Can_Division_Equal_Complex_Numbers) {
        // Arrange
        ComplexNumber z1(23.0, 78.0);
        ComplexNumber z2(23.0, 78.0);
        // Act
        ComplexNumber z = z1 / z2;
        // Assert
        ComplexNumber expected_z(1.0, 0.0);
        EXPECT_EQ(expected_z, z);
}
TEST(Novikova_Alisa_ComplexNumberTest, Equal_Sums_With_Not_Equal_Numbers) {
        // Arrange
        ComplexNumber z1(23.4, 15.1);
        ComplexNumber z2(18.7, 9.8);
        // Act
        ComplexNumber sum1 = z1 + z2;
        ComplexNumber sum2 = z2 + z1;
        // Assert
        EXPECT_TRUE(sum1 == sum2);
}
TEST(Novikova_Alisa_ComplexNumberTest, Can_Difference_Complex_Number_And_Zero) {
        // Arrange
        ComplexNumber z1(-9.0, 13.0);
        ComplexNumber z2(0.0, 0.0);
        // Act
        ComplexNumber dif = z2 - z1;
        // Assert
        ComplexNumber expected_z(9.0, -13.0);
        EXPECT_EQ(expected_z, dif);
}
TEST(Novikova_Alisa_ComplexNumberTest, Comparison_Not_Equal_Multi_Of_Numbers) {
        // Arrange
        ComplexNumber z1(23.4, 15.1);
        ComplexNumber z2(18.7, 9.8);
        ComplexNumber z3(23.0, 78.0);
        // Act
        ComplexNumber mult1 = z1 * z2;
        ComplexNumber mult2 = z2 * z3;
        // Assert
        EXPECT_TRUE(mult1 != mult2);
}
