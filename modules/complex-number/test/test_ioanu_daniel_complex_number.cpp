// Copyright 2017 Ioanu Daniel

#include <gtest/gtest.h>
#include <limits>

#include "include/complex_number.h"

TEST(Ioanu_Daniel_ComplexNumberTest, Can_Create_Maximum) {
    // Arrange
    double max = std::numeric_limits<double>::max();

    // Act
    ComplexNumber z(max, max);

    // Assert
    EXPECT_EQ(max, z.getRe());
    EXPECT_EQ(max, z.getIm());
}

TEST(Ioanu_Daniel_ComplexNumberTest, Can_Division_Imag) {
    // Arrange
    ComplexNumber z1(0.0, 20.0);
    ComplexNumber z2(0.0, 10.0);
    ComplexNumber answer(2.0, 0.0);

    // Act
    ComplexNumber res = z1 / z2;

    // Assert
    EXPECT_EQ(res, answer);
}

TEST(Ioanu_Daniel_ComplexNumberTest, Are_Numbers_Equal) {
    // Arrange
    ComplexNumber z1(12.0, 6.0);
    ComplexNumber z2(6.0, 0.0);
    ComplexNumber z3(9.0, -3.0);
    ComplexNumber z4(3.0, -3.0);

    // Act
    ComplexNumber res1 = z1 / z2;
    ComplexNumber res2 = z3 / z4;

    // Assert
    EXPECT_EQ(res1, res2);
}

TEST(Ioanu_Daniel_ComplexNumberTest, Numbers_Not_Equal) {
    // Arrange
    ComplexNumber z1(12.0, 3.0);
    ComplexNumber z2(3.0, 8.0);

    // Act & Assert
    EXPECT_FALSE(z1 == z2);
}

TEST(Ioanu_Daniel_ComplexNumberTest, Not_Dividable_By_Zero) {
    // Arrange
    double r = 23.01;
    double i = 42.02;
    ComplexNumber z1(r, i);
    ComplexNumber zero(0, 0);

    // Act & Assert
    EXPECT_ANY_THROW(z1 / zero);
}
