// Copyright 2018 Matyasov Mixail

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Matyasov_Mixail_ComplexNumberTest, can_plus_two_number) {
    // Arrange
    double re = 1.0;
    double im = 2.0;
    double resRe = 2.0;
    double resIm = 4.0;
    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re, im);
    ComplexNumber res(resRe, resIm);
    z = z + z1;

    // Assert
    EXPECT_TRUE(z == res);
}

TEST(Matyasov_Mixail_ComplexNumberTest, two_opposite_number_are_not_equal) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    double re1 = 2.0;
    double im1 = 1.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);

    // Assert
    EXPECT_TRUE(z != z1);
}

TEST(Matyasov_Mixail_ComplexNumberTest, sum_equal_difference) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re, im);
    ComplexNumber z2(re, im);
    z = z - z1;
    z = z + z1;

    // Assert
    EXPECT_EQ(z , z2);
}

TEST(Matyasov_Mixail_ComplexNumberTest, can_right_plus_negative_numbers) {
    // Arrange
    double re = -1.0;
    double im = -2.0;

    double re1 = -3.0;
    double im1 = -4.0;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re1, im1);
    ComplexNumber result(-4.0, -6.0);

    // Assert
    EXPECT_EQ(result, z + z1);
}

TEST(Matyasov_Mixail_ComplexNumberTest, numbers_not_equal_after_set_Re) {
    // Arrange
    double re = 1.0;
    double im = 2.0;

    double re1 = 5;

    // Act
    ComplexNumber z(re, im);
    ComplexNumber z1(re, im);
    z.setRe(re1);

    // Assert
    EXPECT_NE(z1, z);
}

TEST(Matyasov_Mixail_ComplexNumberTest, can_get_im) {
    // Arrange
    double re = 1.0;
    double im = 2.0;
    double im1 = 3.0;

    // Act
    ComplexNumber z(re, im);
    z.setIm(im1);

    // Assert
    EXPECT_EQ(im1, z.getIm());
}
