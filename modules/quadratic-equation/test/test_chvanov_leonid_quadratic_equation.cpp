// Copyright 2018 Chvanov Leonid

#include <gtest/gtest.h>

#include <vector>

#include "include/quadratic_equation.h"

TEST(Chvanov_Leonid_QuadraticEquationTest,
     Can_Create_Quadratic_Equation) {
    // AAA
    ASSERT_NO_THROW(QuadraticEquation q(1, 1, 1));
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Throw_If_Quadratic_Coefficient_Is_Equal_Zero) {
    // AAA
    ASSERT_ANY_THROW(QuadraticEquation q(0, 1, 1));
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Can_Get_Roots) {
    // Arrange
    QuadraticEquation q(1, -2, -3);
    std::vector<double> roots;

    // Act and assert
    ASSERT_NO_THROW(roots = q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Can_Get_Roots_Multiple_Times) {
    // Arrange
    QuadraticEquation q(1, -2, -3);
    std::vector<double> roots;

    // Act
    q.getRoots();

    // Assert
    ASSERT_NO_THROW(q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Can_Get_Correct_Roots) {
    // Arrange
    QuadraticEquation q(1, -2, -3);
    std::vector<double> roots;

    // Act
    roots.push_back(-1);
    roots.push_back(3);

    // Assert
    EXPECT_EQ(roots, q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Returns_One_Root_If_Discriminant_Is_Equal_Zero) {
    // Arrange
    QuadraticEquation q(1, -2, 1);
    std::vector<double> roots;

    // Act
    roots.push_back(1);

    // Assert
    EXPECT_EQ(roots, q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Throws_If_There_Are_No_Real_Roots) {
    // Arrange
    QuadraticEquation q(1, -2, 2);

    // Act and assert
    ASSERT_ANY_THROW(q.getRoots());
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Can_Set_Corfficients) {
    // Arrange
    QuadraticEquation q(1, -2, 2);

    // Act and assert
    ASSERT_NO_THROW(q.setCoefficients(1, -2, 2));
}

TEST(Chvanov_Leonid_QuadraticEquationTest,
    Setting_Coefficients_Changes_Roots) {
    // Arrange
    QuadraticEquation q(1, -2, 1);
    std::vector<double> roots;

    // Act
    roots = q.getRoots();
    q.setCoefficients(1, -2, -3);

    // Assert
    EXPECT_NE(roots, q.getRoots());
}
