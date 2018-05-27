// Copyright 2018 Lvova Alina
#include <gtest/gtest.h>
#include <string>
#include "include/numerical_integration.h"

double equalFunction(double x) {
    return (x * x * x / 3 + x * x / 2 + 2 * x);
}

TEST(Lvova_Alina_NumericalIntegrationTest, CorrectDivisionsInConstructor) {
    // Arrange
    int  N = 100;

    // Act & Assert
    ASSERT_NO_THROW(Integral I(3.04, 9.45, N));
}

TEST(Lvova_Alina_NumericalIntegrationTest, CorrectLimitsInConstructor) {
    // Arrange
    double A = 3.14, B = 65.654;

    // Act & Assert
    ASSERT_NO_THROW(Integral I(3.04, 9.45, 100));
}

TEST(Lvova_Alina_NumericalIntegrationTest, RiemannSumLeft) {
    // Arrange
    double A = -13.14, B = 65.654;
    int  N = 1000;
    double result, eq;
    Integral I(A, B, N);
    double epsilon = 1.8e2;

    // Act
    result = I.RiemannSumLeft();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest, TrapezoidalRule) {
    // Arrange
    double A = -13.14, B = 65.654;
    int  N = 1000;
    double result, eq;
    Integral I(A, B, N);
    double epsilon = 82e-3;

    // Act
    result = I.TrapezoidalRule();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest, SimpsonRule) {
    // Arrange
    double A = -153.26485, B = 35.365695;
    int N = 750;
    double result, eq;
    Integral I(A, B, N);
    double epsilon = 3.26e-8;

    // Act
    result = I.SimpsonRule();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest, Simpson3_8Rule) {
    // Arrange
    double A = -13.14, B = 65.654;
    int  N = 1000;
    double result, eq;
    Integral I(A, B, N);
    double epsilon = 2.65e-9;

    // Act
    result = I.Simpson3_8Rule();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest, BooleRule) {
    // Arrange
    double A = -13.14, B = 65.654;
    int  N = 1000;
    double result, eq;
    Integral I(A, B, N);
    double epsilon = 2.67e-9;

    // Act
    result = I.BooleRule();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest, NewtonCotes5) {
    // Arrange
    double A = -13.14, B = 65.654;
    int  N = 1000;
    double result, eq;
    Integral I(A, B, N);
    double epsilon = 2.65e-9;

    // Act
    result = I.NewtonCotes5();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest,
     SetCorrectLowerLimitAndCorrectDivisions) {
    // Arrange
    double A = -153.26485, B = 0;
    int N = 750;
    double result, eq;
    Integral I;
    double epsilon = 3.5e-9;

    // Act
    I.setLower(A);
    I.setDivisions(N);
    result = I.GaussianQuadrature();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest,
     SetIncorrectLowerLimitAndCorrectDivisions) {
    // Arrange
    double A = -15.12, B = 10;
    int N = 750;
    Integral I(A, B, N);
    double newLower = -15.12;

    // Act & Assert
    try {
        I.setLower(newLower);
    }
    catch (std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("the lower limits are the same"));
    }
}

TEST(Lvova_Alina_NumericalIntegrationTest,
     SetCorrectUpperLimitAndCorrectDivisions) {
    // Arrange
    double A = 0, B = 35.365695;
    int N = 750;
    double result, eq;
    Integral I;
    double epsilon = 3.5e-9;

    // Act
    I.setUpper(B);
    I.setDivisions(N);
    result = I.GaussianQuadrature();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}

TEST(Lvova_Alina_NumericalIntegrationTest,
     SetIncorrectUpperLimitAndCorrectDivisions) {
    // Arrange
    double A = -115.25, B = 10.10;
    int N = 750;
    Integral I(A, B, N);
    double newUpper = 10.10;

    // Act & Assert
    try {
        I.setUpper(newUpper);
    }
    catch (std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("the upper limits are the same"));
    }
}

TEST(Lvova_Alina_NumericalIntegrationTest, SetIncorrectDivisions) {
    // Arrange
    Integral I;
    int newDiv = -1;

    // Act & Assert
    try {
        I.setDivisions(newDiv);
    }
    catch (std::out_of_range const & err) {
        EXPECT_EQ(err.what(), std::string("divisions must be greater than 1"));
    }
}

TEST(Lvova_Alina_NumericalIntegrationTest, NullResult) {
    // Arrange
    double A = 35.36, B = 35.36;
    int N = 750;
    Integral I(A, B, N);

    // Act & Assert
    EXPECT_EQ(I.BooleRule(), .0);
    EXPECT_EQ(I.GaussianQuadrature(), .0);
    EXPECT_EQ(I.NewtonCotes5(), .0);
    EXPECT_EQ(I.RiemannSumLeft(), .0);
    EXPECT_EQ(I.Simpson3_8Rule(), .0);
    EXPECT_EQ(I.SimpsonRule(), .0);
    EXPECT_EQ(I.TrapezoidalRule(), .0);
}

TEST(Lvova_Alina_NumericalIntegrationTest, SetReverseLimits) {
    // Arrange
    double  A = 5.0, B = 2.0;
    int  N = 1000;
    double result, eq;
    Integral I(A, B, N);
    double epsilon = 2.67e-9;

    // Act
    result = I.GaussianQuadrature();
    eq = equalFunction(B) - equalFunction(A);

    // Assert
    EXPECT_NEAR(eq, result, epsilon);
}
