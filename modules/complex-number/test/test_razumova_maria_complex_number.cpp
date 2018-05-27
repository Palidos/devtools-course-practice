// Copyright 2018 Razumova Maria

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Razumova_Maria_ComplexNumberTest, Order_of_sum_is_not_important ) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 1.0;
    double im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 + z2, z2 + z1);
}

TEST(Razumova_Maria_ComplexNumberTest, Number_divided_by_1_stays_same ) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 1.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 / z2, z1);
}

TEST(Razumova_Maria_ComplexNumberTest, Number_multiplied_by_1_stays_same ) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 1.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_EQ(z1 * z2, z1);
}

TEST(Razumova_Maria_ComplexNumberTest, Order_of_division_is_important ) {
    // Arrange
    double re1 = 1.0;
    double im1 = 2.0;

    double re2 = 1.0;
    double im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_NE(z1 /z2, z2 / z1);
}

TEST(Razumova_Maria_ComplexNumberTest, i_multiplied_by_i_equal_minus_1 ) {
    // Arrange
    double re1 = 0.0;
    double im1 = 1.0;

    double minus1Re = -1.0;
    double minus1Im = 0.0;

    // Act
    ComplexNumber i(re1, im1);
    ComplexNumber minus1(minus1Re, minus1Im);


    // Assert
    EXPECT_EQ(i * i, minus1);
}

