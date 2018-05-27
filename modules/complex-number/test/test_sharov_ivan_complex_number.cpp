// Copyright 2018 Sharov Ivan

#include <gtest/gtest.h>

#include "include/complex_number.h"


TEST(Sharov_Ivan_ComplexNumberTest, Multi_Complex_Number) {
    // Arrange
    double ReZ1 = 7.0;
    double ImZ1 = 5.0;
    double ReZ2 = 7.0;
    double ImZ2 = -5.0;
    double ReRes = 74.0;
    double ImRes = 0.0;
    ComplexNumber Z1(ReZ1, ImZ1);
    ComplexNumber Z2(ReZ2, ImZ2);
    ComplexNumber Mult(ReRes, ImRes);

    // Act & assert
    EXPECT_EQ(Mult, Z1 * Z2);
}

TEST(Sharov_Ivan_ComplexNumberTest, Division_by_its_equal_to_one) {
    // Arrange
    ComplexNumber Z1(7.0, 5.0);
    ComplexNumber Z2(1.0, 0.0);
    // Act
    ComplexNumber Res = Z1 / Z1;
    // Assert
    EXPECT_EQ(Res, Z2);
}

TEST(Sharov_Ivan_ComplexNumberTest, Sum_Complex_and_Conjugate_Two_Real_Part) {
    // Arrange
    ComplexNumber Z1(7.0, 5.0);
    ComplexNumber Z2(7.0, -5.0);
    // Act
    ComplexNumber Res = Z1 + Z2;
    ComplexNumber Expected_Res(14.0, 0.0);
    // Assert
    EXPECT_EQ(Res, Expected_Res);
}

TEST(Sharov_Ivan_ComplexNumberTest, Copy_is_equal_orig) {
    // Arrange
    ComplexNumber Z1(7.0, 5.0);
    // Act
    ComplexNumber Z2(Z1);
    // Assert
    EXPECT_TRUE(Z2.getRe() == Z1.getRe());
    EXPECT_TRUE(Z2.getIm() == Z1.getIm());
}


TEST(Sharov_Ivan_ComplexNumberTest, Difference_with_itself_is_zero) {
    // Arrange
    ComplexNumber Z(7.0, 5.0);
    ComplexNumber Z2;
    ComplexNumber Res(0, 0);
    // Act
    Z2 = Z - Z;
    // Assert
    EXPECT_EQ(Res, Z2);
}
