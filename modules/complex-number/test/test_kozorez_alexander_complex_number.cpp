// Copyright 2018 Kozorez Alexander

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Kozorez_Alex_ComplexNumberTest, Plus_Zero_Is_Equal) {
        // Arrange
        double re1 = 666.0;
        double im1 = 22.0;
        // Act
        ComplexNumber z(re1, im1);
        ComplexNumber z1(0.0, 0.0);
        ComplexNumber sum = z + z1;
        // Assert
        EXPECT_EQ(z, sum);
}

TEST(Kozorez_Alex_ComplexNumberTest, Multi_By_Zero_Is_Zero) {
        // Arrange
        ComplexNumber z(666.0, 22.0);
        ComplexNumber z1(0.0, 0.0);
        // Act
        ComplexNumber multi = z * z1;
        // Assert
        EXPECT_EQ(z1, multi);
}

TEST(Kozorez_Alex_ComplexNumberTest, Sum_Commutication) {
        // Arrange
        ComplexNumber z1(66.0, 22.0);
        ComplexNumber z(-66.0, -22.0);
        // Act
        ComplexNumber sum1 = z1 + z;
        ComplexNumber sum2 = z + z1;
        // Assert
        EXPECT_EQ(sum1, sum2);
}

TEST(Kozorez_Alex_ComplexNumberTest, Sum_Of_Equal_By_Abs_Is_Zero) {
        // Arrange
        ComplexNumber z1(-666.0, -22.0);
        ComplexNumber z(666.0, 22.0);
        ComplexNumber zero(0.0, 0.0);
        // Act
        ComplexNumber sum = z + z1;
        // Assert
        EXPECT_EQ(sum, zero);
}

TEST(Kozorez_Alex_ComplexNumberTest, Multiply_Commutication) {
        // Arrange
        ComplexNumber z1(66.0, 22.0);
        ComplexNumber z(-66.0, -22.0);;
        // Act
        ComplexNumber multi1 = z1 * z;
        ComplexNumber multi2 = z * z1;
        // Assert
        EXPECT_EQ(multi1, multi2);
}
