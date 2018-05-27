// Copyright 2018 Gracheva Elena

#include <gtest/gtest.h>
#include "include/operations_on_3d_vectors.h"
#include "include/vector_3d.h"

TEST(Gracheva_Elena_TestOperationsOn3dVectors, can_get_correct_norm) {
    // Arrange
    Vector3d vector(0, 3, -4);

    // Act
    double result = OperationsOn3dVectors::GetNorm(vector);

    // Assert
    EXPECT_DOUBLE_EQ(5, result);
}

TEST(Gracheva_Elena_TestOperationsOn3dVectors,
    can_get_correct_normalized_vector) {
    // Arrange
    Vector3d vector(0, 3, -4);
    Vector3d expectedResult(0, 3 / 5.0, -4 / 5.0);

    // Act
    Vector3d result = OperationsOn3dVectors::GetNormalizedVector(vector);

    // Assert
    EXPECT_TRUE(expectedResult == result);
}

TEST(Gracheva_Elena_TestOperationsOn3dVectors,
    can_get_correct_normalized_vector_if_vector_is_zero) {
    // Arrange
    Vector3d vector(0, 0, 0);
    Vector3d expectedResult(0, 0, 0);

    // Act
    Vector3d result = OperationsOn3dVectors::GetNormalizedVector(vector);

    // Assert
    EXPECT_TRUE(expectedResult == result);
}

TEST(Gracheva_Elena_TestOperationsOn3dVectors, can_get_correct_dot_product) {
    // Arrange
    Vector3d vector1(1, 2, 3), vector2(2, 3, -4);

    // Act
    double result = OperationsOn3dVectors::DotProduct(vector1, vector2);

    // Assert
    EXPECT_DOUBLE_EQ(-4, result);
}

TEST(Gracheva_Elena_TestOperationsOn3dVectors, can_get_correct_cross_product) {
    // Arrange
    Vector3d vector1(0, 1, 0), vector2(1, 0, 0);
    Vector3d expectedResult(0, 0, -1);

    // Act
    Vector3d result = OperationsOn3dVectors::CrossProduct(vector1, vector2);

    // Assert
    EXPECT_TRUE(expectedResult == result);
}
