// Copyright 2018 Generalov Aleksandr

#include <gtest/gtest.h>

#include <string>

#include "include/Cone.h"
#include "include/Cube.h"
#include "include/Cylinder.h"
#include "include/Sphere.h"

TEST(AreaOfGeometricShapes, Get_Radius_From_Cone) {
    // Arrange
    double radius = 2.5;
    double l = 5.3;
    Cone cone(radius, l);

    // Act & Assert
    EXPECT_EQ(radius, cone.getRad());
}

TEST(AreaOfGeometricShapes, Get_L_From_Cone) {
    // Arrange
    double radius = 7.1;
    double l = 15.9;
    Cone cone(radius, l);

    // Act & Assert
    EXPECT_EQ(l, cone.getL());
}

TEST(AreaOfGeometricShapes, Set_Radius_And_L_From_Cone) {
    // Arrange
    Cone cone;
    double radius = 3.8;
    double l = 7.4;

    // Act
    cone.setRad(radius);
    cone.setL(l);

    // Assert
    EXPECT_EQ(radius, cone.getRad());
    EXPECT_EQ(l, cone.getL());
}

TEST(AreaOfGeometricShapes, Comparison_Operator) {
    // Arrange
    double radius = 7.9;
    double l = 15.2;
    Cone cone1(3.1, 6.5);
    Cone cone2(radius, l);

    // Act
    cone1 = cone2;

    // Assert
    EXPECT_EQ(cone1.getRad(), cone2.getRad());
    EXPECT_EQ(cone1.getL(), cone2.getL());
}

TEST(AreaOfGeometricShapes, Negative_Rad_Cone) {
    // Arrange
    double radius = -7.1;
    double l = 15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cone cone(radius, l));
}

TEST(AreaOfGeometricShapes, Negative_L_Cone) {
    // Arrange
    double radius = 7.1;
    double l = -15.9;

    // Act & Assert
    ASSERT_ANY_THROW(Cone cone(radius, l));
}

TEST(AreaOfGeometricShapes, Area_Calculation_Cone) {
    // Arrange
    double res = 0;
    Cone cone(2.1, 4.5);

    // Act
    res = cone.areaCone();

    // Assert
    EXPECT_NEAR(res, 43.5425, 0.0001);
}

TEST(AreaOfGeometricShapes, Copy_Cone) {
    // Arrange
    Cone cone1(2.1, 4.5);

    // Act
    Cone cone2(cone1);

    // Assert
    EXPECT_EQ(cone1.getRad(), cone2.getRad());
    EXPECT_EQ(cone1.getL(), cone2.getL());
}

TEST(AreaOfGeometricShapes, Equal_Test_Cone) {
    // Arrange
    double radius = 7.1;
    double l = 15.9;
    Cone cone1(radius, l);
    Cone cone2(cone1);

    // Act & Assert
    EXPECT_TRUE(cone1 == cone2);
}
TEST(AreaOfGeometricShapes, Not_Equal_Test_Cone) {
    // Arrange
    double radius = 7.1;
    double l = 15.9;
    Cone cone1(2.1, 4.5);
    Cone cone2(radius, l);

    // Act & Assert
    EXPECT_TRUE(cone1 != cone2);
}
