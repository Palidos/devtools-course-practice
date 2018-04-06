// Copyright 2018 Bederdinov Daniil

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Bederdinov_Daniil_ComplexNumberTest, Can_Multiply_By_Zero) {
    // Arrange
    ComplexNumber z1(7.1488, 13.22);
    ComplexNumber z2(0, 0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(z2, z);
}

TEST(Bederdinov_Daniil_ComplexNumberTest,
    Can_Subtract_Complex_Nubmer_From_Itself) {
    // Arrange
    ComplexNumber z1(7.1483, 13.32);
    ComplexNumber z2(0, 0);

    // Act
    ComplexNumber z = z1 - z1;

    // Assert
    EXPECT_EQ(z2, z);
}

TEST(Bederdinov_Daniil_ComplexNumberTest,
    Multiplification_By_One_Changes_Nothing) {
    // Arrange
    ComplexNumber z1(7.1483, 13.32);
    ComplexNumber z2(1, 0);

    // Act
    ComplexNumber z = z1 * z2;

    // Assert
    EXPECT_EQ(z, z1);
}

TEST(Bederdinov_Daniil_ComplexNumberTest,
    Return_One_When_Divided_By_Itself) {
    // Arrange
    ComplexNumber z1(7.1483, 13.32);
    ComplexNumber z2(1, 0);

    // Act
    ComplexNumber z = z1 / z1;

    // Assert
    EXPECT_EQ(z2, z);
}

TEST(Bederdinov_Daniil_ComplexNumberTest, Can_Add_Zero) {
    // Arrange
    ComplexNumber z1(7.1483, 13.32);
    ComplexNumber z2(0, 0);

    // Act
    ComplexNumber z = z1 + z2;

    // Assert
    EXPECT_EQ(z1, z);
}
