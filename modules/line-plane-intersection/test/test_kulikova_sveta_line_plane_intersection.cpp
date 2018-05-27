// Copyright 2018 Kulikova Svetlana

#include <gtest/gtest.h>

#include "include/line_plane_intersection.h"

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, Intersect1) {
    // Arrange
    Dot Line1 = { 0, 9, -11 };
    Dot Line2 = { 1, 12, -14 };
    Dot Plane1 = { 0, 0, 3 };
    Dot Plane2 = { 0, 1, 1 };
    Dot Plane3 = { -3, 0, 0 };
    Dot EQ = { -2, 3, -5 };
    Dot res;
    double epsilon = 1e-6;
    LinePlaneIntersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_NEAR(EQ.x, res.x, epsilon);
    EXPECT_NEAR(EQ.y, res.y, epsilon);
    EXPECT_NEAR(EQ.z, res.z, epsilon);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, Intersect2) {
    // Arrange
    Dot Line1 = { 0, 3, -4 };
    Dot Line2 = { -3, 0, 3.5 };
    Dot Plane1 = { 0, 1, 7 };
    Dot Plane2 = { -1, 5, 4 };
    Dot Plane3 = { -2, 3, 1 };
    Dot EQ = { -2, 1, 1 };
    Dot res;
    double epsilon = 1e-6;
    LinePlaneIntersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_NEAR(EQ.x, res.x, epsilon);
    EXPECT_NEAR(EQ.y, res.y, epsilon);
    EXPECT_NEAR(EQ.z, res.z, epsilon);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, NotIntersect) {
    // Arrange
    Dot Line1 = { 0, -2, 1 };
    Dot Line2 = { 1, 0, 1 };
    Dot Plane1 = { 0, 1, 0 };
    Dot Plane2 = { -0.5, 0, 0 };
    Dot Plane3 = { 1, 0, 1 };
    Dot res;
    LinePlaneIntersection F;

    // Act
    res = F.PlaneIntersectLine(Plane1, Plane2, Plane3, Line1, Line2);

    // Assert
    EXPECT_TRUE(F.GetNotIntersectPlaneLine());
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectLine) {
    // Arrange
    Dot Line1 = { 0, 0, 0 };
    Dot Line2 = { 0, 0, 0 };
    Dot Plane1 = { 0, 1, 0 };
    Dot Plane2 = { -0.5, 0, 0 };
    Dot Plane3 = { 1, 0, 1 };
    LinePlaneIntersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneA) {
    // Arrange
    Dot Line1 = { 0, 0, 0 };
    Dot Line2 = { 0, 1, 0 };
    Dot Plane1 = { 0, 0, 0 };
    Dot Plane2 = { 0, 0, 0 };
    Dot Plane3 = { 0, 1, 0 };
    LinePlaneIntersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneB) {
    // Arrange
    Dot Line1 = { 0, 0, 0 };
    Dot Line2 = { 0, 1, 0 };
    Dot Plane1 = { 0, 0, 0 };
    Dot Plane2 = { 0, 1, 0 };
    Dot Plane3 = { 0, 0, 0 };
    LinePlaneIntersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, IncorrectPlaneC) {
    // Arrange
    Dot Line1 = { 0, 0, 0 };
    Dot Line2 = { 0, 1, 0 };
    Dot Plane1 = { 0, 1, 0 };
    Dot Plane2 = { 0, 0, 0 };
    Dot Plane3 = { 0, 0, 0 };
    Dot res;
    LinePlaneIntersection F;

    // Act & Assert
    EXPECT_ANY_THROW(F.PlaneIntersectLine(Plane1,
        Plane2, Plane3, Line1, Line2));
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, VariableDeclaration) {
    // Act & Assert
    ASSERT_NO_THROW(Dot A);
}

TEST(Kulikova_Sveta_LinePlaneIntersection_Test, CopyConstractor) {
    // Arrange
    Dot A = { 0, 0, 0 };

    // Act & Assert
    ASSERT_NO_THROW(Dot B(A));
}
