// Copyright 2018 Gracheva Elena

#include <gtest/gtest.h>
#include "include/vector_3d.h"

TEST(Gracheva_Elena_TestVector3d, can_create_not_zero_vector) {
    // Arrange
    double component0 = 1, component1 = 2, component2 = 3;

    // Act
    Vector3d vector(component0, component1, component2);

    // Assert
    EXPECT_DOUBLE_EQ(component0, vector.x);
    EXPECT_DOUBLE_EQ(component1, vector.y);
    EXPECT_DOUBLE_EQ(component2, vector.z);
}

TEST(Gracheva_Elena_TestVector3d, can_create_zero_vector) {
    // Arrange
    Vector3d expectedResult(0, 0, 0);

    // Act
    Vector3d result;

    // Assert
    EXPECT_EQ(expectedResult, result);
}

TEST(Gracheva_Elena_TestVector3d, can_compare_equals_vector) {
    // Arrange
    Vector3d vector1(1, 2, 3), vector2(1, 2, 3);

    // Act, Assert
    EXPECT_TRUE(vector1 == vector2);
}

TEST(Gracheva_Elena_TestVector3d, can_compare_not_equals_vector) {
    // Arrange
    Vector3d vector1(1, 2, 3), vector2(1, 2, 4);

    // Act, Assert
    EXPECT_TRUE(vector1 != vector2);
}
