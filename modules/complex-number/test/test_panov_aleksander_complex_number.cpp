// Copyright 2018 Panov Aleksander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Panov_Aleksander_ComplexNumberTest, Can_Create_Copy) {
    // Arrange
    double re = -1.0;
    double im = 1.0;
    ComplexNumber z(re, im);

    // Act
    ComplexNumber copy_z(z);

    // Assert
    EXPECT_EQ(copy_z, z);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Multiplication_Real) {
    // Arrange
    double re1 = 3.0, re2 = 4.0;
    ComplexNumber a(re1, 0.0), b(re2, 0.0), correct_res(re1*re2, 0.0);

    // Act
    ComplexNumber res = a*b;

    // Assert
    EXPECT_EQ(res, correct_res);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Multiplication_Imaginary) {
    // Arrange
    double im1 = 3.0, im2 = 4.0;
    ComplexNumber a(0.0, im1), b(0.0, im2), correct_res(-im1 * im2, 0.0);

    // Act
    ComplexNumber res = a*b;

    // Assert
    EXPECT_EQ(res, correct_res);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Division_Real) {
    // Arrange
    double re1 = 12.0, re2 = 3.0;
    ComplexNumber a(re1, 0.0), b(re2, 0.0), correct_res(re1 / re2, 0.0);

    // Act
    ComplexNumber res = a / b;

    // Assert
    EXPECT_EQ(res, correct_res);
}

TEST(Panov_Aleksander_ComplexNumberTest, Can_Division_Imaginary) {
    // Arrange
    ComplexNumber z1(0.0, 4.0), z2(0.0, 2.0), correct_res(2.0, 0.0);

    // Act
    ComplexNumber res  = z1 / z2;

    // Assert
    EXPECT_EQ(res, correct_res);
}
