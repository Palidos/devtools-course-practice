// Copyright 2018 Shurygin Dmitriy

#include <gtest/gtest.h>

#include "include/volume.h"

TEST(Shurygin_Dmitriy_Volume_Test, Get_R_From_Sphere) {
     // Arrange
    double _R = 3;
    Sphere sphere(_R);

    // Act & Assert
    EXPECT_EQ(_R, sphere.getRadius());
}

TEST(Shurygin_Dmitriy_Volume_Test, Get_L_From_Cube) {
    // Arrange
    double _L = 2.4;
    Cube cube(_L);

    // Act & Assert
    EXPECT_EQ(_L, cube.getL());
}

TEST(Shurygin_Dmitriy_Volume_Test, Get_R_From_Cylinder) {
    // Arrange
    double _R = 2.4;
    double _h = 1.23;
    Cylinder cylinder(_R, _h);

    // Act & Assert
    EXPECT_EQ(_R, cylinder.getRadius());
}

TEST(Shurygin_Dmitriy_Volume_Test, Get_H_From_Cylinder) {
    // Arrange
    double _R = 2.4;
    double _h = 1.23;
    Cylinder cylinder(_R, _h);

    // Act & Assert
    EXPECT_EQ(_h, cylinder.getHeight());
}

TEST(Shurygin_Dmitriy_Volume_Test, Set_R_From_Sphere) {
     // Arrange
    Sphere sphere;
    double _R = 7.4;

    // Act
    sphere.setRadius(_R);

    // Assert
    EXPECT_EQ(_R, sphere.getRadius());
}

TEST(Shurygin_Dmitriy_Volume_Test, Set_L_From_Cube) {
    // Arrange
    Cube cube;
    double _L = 7.4;

    // Act
    cube.setL(_L);

    // Assert
    EXPECT_EQ(_L, cube.getL());
}

TEST(Shurygin_Dmitriy_Volume_Test, Set_R_From_Cylinder) {
    // Arrange
    Cylinder cylinder;
    double _R = 7.4;

    // Act
    cylinder.setRadius(_R);

    // Assert
    EXPECT_EQ(_R, cylinder.getRadius());
}

TEST(Shurygin_Dmitriy_Volume_Test, Set_H_From_Cylinder) {
    // Arrange
    Cylinder cylinder;
    double _h = 7.4;

    // Act
    cylinder.setHeight(_h);

    // Assert
    EXPECT_EQ(_h, cylinder.getHeight());
}

TEST(Shurygin_Dmitriy_Volume_Test, Volume_Calculation_Cube) {
    // Arrange
    double res = 0;
    Cube cube(2.0);

    // Act
    res = cube.Volume();

    // Assert
    EXPECT_NEAR(res, 8.0, 0.0001);
}

TEST(Shurygin_Dmitriy_Volume_Test, Volume_Calculation_Sphere) {
    // Arrange
    double res = 0;
    Sphere sphere(1.0);

    // Act
    res = sphere.Volume();

    // Assert
    EXPECT_NEAR(res, 3.1415926, 0.0001);
}

TEST(Shurygin_Dmitriy_Volume_Test, Volume_Calculation_Cylinder) {
    // Arrange
    double res = 0;
    Cylinder cylinder(1.0, 1.0);

    // Act
    res = cylinder.Volume();

    // Assert
    EXPECT_NEAR(res, 3.1415926, 0.0001);
}

TEST(Shurygin_Dmitriy_Volume_Test, Can_Copy_Cube) {
    // Arrange
    Cube _cube(3.4);

    // Act
    Cube cube(_cube);

    // Assert
    EXPECT_EQ(_cube.getL(), cube.getL());
}

TEST(Shurygin_Dmitriy_Volume_Test, Can_Copy_Sphere) {
    // Arrange
    Sphere _sphere(3.4);

    // Act
    Sphere sphere(_sphere);

    // Assert
    EXPECT_EQ(_sphere.getRadius(), sphere.getRadius());
}

TEST(Shurygin_Dmitriy_Volume_Test, Can_Copy_Cylinder) {
    // Arrange
    Cylinder _cylinder(1.0, 2.0);

    // Act
    Cylinder cylinder(_cylinder);

    // Assert
    EXPECT_EQ(_cylinder.getRadius(), cylinder.getRadius());
    EXPECT_EQ(_cylinder.getHeight(), cylinder.getHeight());
}

TEST(Shurygin_Dmitriy_Volume_Test, Negative_Rad_Sphere) {
    // Arrange
    double _R = -1.0;

    // Act & Assert
    ASSERT_ANY_THROW(Sphere sphere(_R));
}

TEST(Shurygin_Dmitriy_Volume_Test, Negative_L_Cube) {
    // Arrange
    double _L = -1.0;

    // Act & Assert
    ASSERT_ANY_THROW(Cube Cube(_L));
}

TEST(Shurygin_Dmitriy_Volume_Test, Negative_Rad_Cylinder) {
    // Arrange
    double _R = -1.0;
    double _H = 0;

    // Act & Assert
    ASSERT_ANY_THROW(Cylinder cylinder(_R, _H));
}


