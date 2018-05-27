// Copyright 2018 Kovshov Andrey

#include <gtest/gtest.h>

#include <limits>

#include "include/complex_number.h"

TEST(Kovshov_Andrey_ComplexNumberTest, Cant_Divide_Zero) {
    // Arrange
    ComplexNumber z1(1, 2);
    ComplexNumber z2(0, 0);
    // Act Assert
    EXPECT_ANY_THROW({ z1 / z2; });
}

TEST(Kovshov_Andrey_ComplexNumberTest, imaginary_i_pow_3) {
    // Arrange
    ComplexNumber i(0.0, 1.0);
    // Act
    ComplexNumber i_pow_3 = i * i * i;
    // Assert
    EXPECT_TRUE((i_pow_3.getRe() == 0.0) && (i_pow_3.getIm() == -1.0));
}

TEST(Kovshov_Andrey_ComplexNumberTest,
     Conjugate_Complex_Numbers_Multiply) {
    // Arrange
    double re = 6.0, im = 4.22;
    // Act
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, -im);
    ComplexNumber z(re * re + im * im, 0.0);
    // Assert
    EXPECT_EQ(z, z1 * z2);
}

TEST(Kovshov_Andrey_ComplexNumberTest,
     Number_Is_Equal_To_Itself_Different_By_Double_Min) {
    // Arrange
    double min = std::numeric_limits<double>::min();
    double re = -50.4;
    double im = 378.9;
    // Act
    ComplexNumber z1(min, min);
    ComplexNumber z2(re, im);
    ComplexNumber expected = z2 - z1;
    // Assert
    EXPECT_DOUBLE_EQ(re, expected.getRe());
    EXPECT_DOUBLE_EQ(im, expected.getIm());
}

TEST(Kovshov_Andrey_ComplexNumberTest,
     Can_Multiply_By_Zero) {
    // Arrange
    ComplexNumber z1(0.0, 0.0);
    ComplexNumber z2(1.0, 7.0);
    // Act
    ComplexNumber z = z1 * z2;
    // Assert
    EXPECT_DOUBLE_EQ(0.0, z.getRe());
    EXPECT_DOUBLE_EQ(0.0, z.getIm());
}
