// Copyright 2018 Osyagin Maksim

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Osyagin_Maksim_ComplexNumberTest, Can_Add_Two_Numbers) {
    // Arrange
    double re1 = 1.0;
    double im1 = 3.0;

    double re2 = 4.0;
    double im2 = 7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_NO_THROW(z1 + z2);
}

TEST(Osyagin_Maksim_ComplexNumberTest, Assert_If_Can_Not_Divide_By_Zero) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 0.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}

TEST(Osyagin_Maksim_ComplexNumberTest, Can_Create_Negative_Real_Nomber) {
    // Arrange
    double re = -50.0;
    double im = 1.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
}

TEST(Osyagin_Maksim_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    double re1 = 10.0;
    double im1 = 10.0;

    double re2 = 0.0;
    double im2 = 0.0;

    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Act
    ComplexNumber res = z1 * z2;

    // Assert
    EXPECT_EQ(z2, res);
}

TEST(Osyagin_Maksim_ComplexNumberTest, Can_Create_With_Zero_In_Imaginary) {
    // Arrange
    double re = 10.0;
    double im = 0.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}
