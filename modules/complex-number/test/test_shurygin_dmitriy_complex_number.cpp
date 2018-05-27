// Copyright 2018 Shurygin Dmitriy

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Shurygin_Dmitriy_ComplexNumberTest, Can_Create_Zero) {
    // Arrange & Act
    double re = 0.0;
    double im = 0.0;
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(re, z.getRe());
    EXPECT_EQ(im, z.getIm());
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, dif_is_zero) {
    // Arrange
    ComplexNumber z1(1.0, 2.0);
    ComplexNumber z2(1.0, 2.0);

    // Act
    ComplexNumber z = z1 - z2;

    // Assert
    EXPECT_EQ(0, z.getRe());
    EXPECT_EQ(0, z.getIm());
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Can_Get_Im_and_Re) {
    // Arrange & Act
    double re = 3;
    double im = -1.23;
    ComplexNumber z(re, im);

    // Assert
    EXPECT_EQ(im, z.getIm());
    EXPECT_EQ(re, z.getRe());
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Can_Copy) {
    // Arrange & Act
    double re = 3;
    double im = -1.23;
    ComplexNumber z(re, im);
    ComplexNumber copy_z(z);

    // Arrange
    EXPECT_EQ(z, copy_z);
}

TEST(Shurygin_Dmitriy_ComplexNumberTest, Division_by_himself) {
    // Arrange
    double re = 3;
    double im = -1.23;

    ComplexNumber z(re, im);
    ComplexNumber z1(1.0, 0);

    // Act
    ComplexNumber res = z / z;

    // Assert
    EXPECT_EQ(res, z1);
}

TEST(Shurygin_Dmitiy_ComplexNumberTest, cant_divide_zero) {
    // Arrange & Act
    ComplexNumber z1(1.0, 1.0);
    ComplexNumber z2;

    // Assert
    ASSERT_ANY_THROW(z1 / z2);
}
