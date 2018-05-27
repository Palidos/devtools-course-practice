// Copyright 2018 Panov Aleksander

#include <gtest/gtest.h>
#include "include/two_lines.h"

TEST(Panov_Aleksander_LinesTest, Can_Create_Default_Points) {
    // Arrange
    double x = 0, y = 0;

    // Act
    Point point;

    // Assert
    EXPECT_DOUBLE_EQ(point.x, x);
    EXPECT_DOUBLE_EQ(point.y, y);
}

TEST(Panov_Aleksander_LinesTest, Can_Create_Points) {
    // Arrange
    double x = 1, y = -1;

    // Act
    Point point1(x, y), point2(x, y);

    // Assert
    EXPECT_DOUBLE_EQ(point1.x, point2.x);
    EXPECT_DOUBLE_EQ(point1.y, point2.y);
}

TEST(Panov_Aleksander_LinesTest, Can_Compare_Point1) {
    // Arrange
    Point point1(1, -1), point2(1, -1);

    // Assert
    EXPECT_TRUE(point1 == point2);
}

TEST(Panov_Aleksander_LinesTest, Can_Compare_Line_Point2) {
    // Arrange
    Point point1(1, -1), point2(1.1, -1);

    // Assert
    EXPECT_TRUE(point1 != point2);
}

TEST(Panov_Aleksander_LinesTest, Point_Equality_Operator_Works) {
    // Arrange
    double x = 1, y = -1;
    Point point1(x, y), point2;

    // Act
    point2 = point1;

    // Assert
    EXPECT_DOUBLE_EQ(point1.x, point2.x);
    EXPECT_DOUBLE_EQ(point1.y, point2.y);
}

TEST(Panov_Aleksander_LinesTest, Can_Create_Default_Line_Segment) {
    // Arrange
    Point point(0, 0);

    // Act
    LineSegment line;

    // Assert
    EXPECT_EQ(line.getPoint1(), point);
    EXPECT_EQ(line.getPoint2(), point);
}

TEST(Panov_Aleksander_LinesTest, Can_Create_Line_Segment) {
    // Arrange
    Point point1(1, -1), point2(-1, 1);

    // Act
    LineSegment line(point1, point2);

    // Assert
    EXPECT_EQ(line.getPoint1(), point1);
    EXPECT_EQ(line.getPoint2(), point2);
}

TEST(Panov_Aleksander_LinesTest, Can_Copy_Line_Segment) {
    // Arrange
    Point point1(1, -1), point2(-1, 1);
    LineSegment line1(point1, point2);

    // Act
    LineSegment line2(line1);

    // Assert
    EXPECT_EQ(line1.getPoint1(), line2.getPoint1());
    EXPECT_EQ(line1.getPoint2(), line2.getPoint2());
}

TEST(Panov_Aleksander_LinesTest, Can_Compare_Line_Segments1) {
    // Arrange
    Point point1(1, -1), point2(-1, 1);
    LineSegment line1(point1, point2);
    LineSegment line2(point2, point1);

    // Assert
    EXPECT_TRUE(line1 == line2);
}

TEST(Panov_Aleksander_LinesTest, Can_Compare_Line_Segments2) {
    // Arrange
    Point point1(1, -1), point2(1.01, -1);
    LineSegment line1(point1, point1);
    LineSegment line2(point1, point2);

    // Assert
    EXPECT_TRUE(line1 != line2);
}

TEST(Panov_Aleksander_LinesTest, Line_Segment_Equality_Operator_Works) {
    // Arrange
    Point point1(1, -1), point2(-1, 1);
    LineSegment line1(point1, point2), line2;

    // Act
    line2 = line1;

    // Assert
    EXPECT_EQ(line1, line2);
}

TEST(Panov_Aleksander_LinesTest, Different_Points_Not_Intersect) {
    // Arrange
    Point startLine1(0, 0), endLine1(0, 0);
    Point startLine2(1, 1), endLine2(1, 1);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_FALSE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Equal_Points_Intersect) {
    // Arrange
    Point startLine1(0, 0), endLine1(0, 0);
    Point startLine2(0, 0), endLine2(0, 0);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Simle_Intersect1) {
    // Arrange
    Point startLine1(0, 0), endLine1(1, 1);
    Point startLine2(0, 1), endLine2(1, 0);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Simle_Intersect2) {
    // Arrange
    Point startLine1(0, 0), endLine1(-1, -1);
    Point startLine2(0, -1), endLine2(-1, 0);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Parallel_Lines) {
    // Arrange
    Point startLine1(0, 0), endLine1(0, 1);
    Point startLine2(0.1, 0), endLine2(0.1, 1);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_FALSE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Coverage) {
    Point startLine1(0, -1), endLine1(0, 1);
    Point startLine2(0, 0.01), endLine2(0, 0.02);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Tangent_Lines) {
    // Arrange
    Point startLine1(0, 0), endLine1(1000, 1000);
    Point startLine2(0, 1000), endLine2(500, 500);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_TRUE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Not_Tangent_Lines1) {
    // Arrange
    Point startLine1(0, 0), endLine1(1000, 1000);
    Point startLine2(0, 1000), endLine2(499.5, 500);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_FALSE(isIntersect);
}

TEST(Panov_Aleksander_LinesTest, Can_Detect_Not_Tangent_Lines2) {
    // Arrange
    Point startLine1, endLine1(101, 0.1);
    Point startLine2(-100, 0.1), endLine2(100, 0.1);
    LineSegment line1(startLine1, endLine1), line2(startLine2, endLine2);

    // Act
    bool isIntersect = line1.intersect(line2);

    // Assert
    EXPECT_FALSE(isIntersect);
}
