// Copyright 2017 Korniakov Kirill

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Aksenov_Nikita_ComplexNumberTest,
    can_not_divide_by_zero) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 0.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_ANY_THROW(z1 / z2);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    two_reverse_numbers_are_not_equal) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 7.0;
    double im2 = 3.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);

    // Assert
    EXPECT_NE(z1, z2);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    the_same_result_after_multiplication_by_certain_number) {
    // Arrange
    double re1 = 3.0;
    double im1 = 7.0;
    double re2 = 1.0;
    double im2 = 0.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber z3 = z1 * z2;

    // Assert
    EXPECT_EQ(z1, z3);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    check_the_associativity_of_addition) {
    // Arrange
    ComplexNumber z1(3.3, 3.3);
    ComplexNumber z2(7.7, 7.7);
    ComplexNumber z3(3.7, 3.7);

    // Act
    ComplexNumber sum1 = (z1 + z2) + z3;
    ComplexNumber sum2 = (z2 + z3) + z1;

    // Assert
    EXPECT_EQ(sum1, sum2);
}

TEST(Aksenov_Nikita_ComplexNumberTest,
    can_subtract_two_negative_numbers) {
    // Arrange
    double re1 = -3.0;
    double im1 = -7.0;
    double re2 = -3.0;
    double im2 = -7.0;

    // Act
    ComplexNumber z1(re1, im1);
    ComplexNumber z2(re2, im2);
    ComplexNumber result = z1 - z2;

    // Assert
    ComplexNumber expected_result(0.0, 0.0);
    EXPECT_EQ(expected_result, result);
}
