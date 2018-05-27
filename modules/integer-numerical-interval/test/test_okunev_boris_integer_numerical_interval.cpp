// Copyright 2018 Okunev Boris

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "include/integer_numerical_interval.h"

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Create_Empty_Interval) {
    // Assert
    EXPECT_NO_THROW(IntegerNumericalInterval());
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Create_Interval) {
    // Assert
    EXPECT_NO_THROW(IntegerNumericalInterval(1, 5, true, true));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Create_Interval_From_String) {
    // Arrange
    std::string interval = "[11,15]";

    // Assert
    EXPECT_NO_THROW(IntegerNumericalInterval ni(interval));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Not_Create_Interval_From_String_Comma) {
    // Arrange
    std::string interval = "[11|15]";

    // Assert
    EXPECT_ANY_THROW(IntegerNumericalInterval ni(interval));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Not_Create_Interval_From_String_leftBorder) {
    // Arrange
    std::string interval = ":11,15]";

    // Assert
    EXPECT_ANY_THROW(IntegerNumericalInterval ni(interval));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Not_Create_Interval_From_String_rightBorder) {
    // Arrange
    std::string interval = "[11,15:";

    // Assert
    EXPECT_ANY_THROW(IntegerNumericalInterval ni(interval));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_not_Create_Wrong_Interval_Position) {
    // Assert
    EXPECT_ANY_THROW(IntegerNumericalInterval(7, 5, true, true));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_not_Create_Wrong_Interval_Point) {
    // Assert
    EXPECT_ANY_THROW(IntegerNumericalInterval(5, 5, false, false));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_not_Create_Wrong_Interval_Empty) {
    // Assert
    EXPECT_ANY_THROW(IntegerNumericalInterval(4, 5, false, false));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_not_Create_Wrong_Interval_From_String) {
    // Arrange
    std::string interval = "[15,11]";

    // Assert
    EXPECT_ANY_THROW(IntegerNumericalInterval test(interval));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Two_Same_Intervals_Are_Equal) {
    // Arrange
    int left = 1;
    int right = 5;
    bool isLeft = true;
    bool isRight = false;
    IntegerNumericalInterval ni(left, right, isLeft, isRight);
    IntegerNumericalInterval ni1(left, right, isLeft, isRight);

    // Assert
    EXPECT_TRUE(ni == ni1);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Two_Differents_Intervals_Not_Equal) {
    // Arrange
    int left = 1;
    int right = 5;
    bool isLeft = true;
    bool isRight = true;

    IntegerNumericalInterval ni(left, right, isLeft, isRight);
    IntegerNumericalInterval ni1(left, right + 1, isLeft, isRight);

    // Assert
    EXPECT_TRUE(ni != ni1);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Copy_Of_Intervals_Equal) {
    // Arrange
    IntegerNumericalInterval ni(1, 5, true, true);

    // Act
    IntegerNumericalInterval ni1(ni);

    // Assert
    EXPECT_EQ(ni, ni1);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Convert_Interval_To_String) {
    // Arrange
    std::string interval = "[11,18)";
    std::string str;

    IntegerNumericalInterval ni(interval);

    // Act
    str = std::string(ni);

    // Assert
    EXPECT_EQ(interval, str);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Get_End_Points) {
    // Arrange
    IntegerNumericalInterval ni("[1,2]");
    vector<int> endPointsR = { 1, 2 };

    // Act
    vector<int> endPoints = ni.getEndPoints();

    // Assert
    EXPECT_EQ(endPoints, endPointsR);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Get_End_Points_Point) {
    // Arrange
    IntegerNumericalInterval ni("[1,1]");
    vector<int> endPointsR = { 1, 1 };

    // Act
    vector<int> endPoints = ni.getEndPoints();

    // Assert
    EXPECT_EQ(endPoints, endPointsR);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Get_End_Points_Open_Interval) {
    // Arrange
    IntegerNumericalInterval ni("(1,6)");
    vector<int> endPointsR = { 2, 5 };

    // Act
    vector<int> endPoints = ni.getEndPoints();

    // Assert
    EXPECT_EQ(endPoints, endPointsR);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Get_End_Points_Open_Interval_With_One_Point) {
    // Arrange
    IntegerNumericalInterval ni("(1,3)");
    vector<int> endPointsR = { 2, 2 };

    // Act
    vector<int> endPoints = ni.getEndPoints();

    // Assert
    EXPECT_EQ(endPoints, endPointsR);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Get_All_Points_Interval) {
    // Arrange
    IntegerNumericalInterval ni("[1,3]");
    vector<int> allPointsR = { 1, 2, 3 };

    // Act
    vector<int> allPoints = ni.getAllPoints();

    // Assert
    EXPECT_EQ(allPointsR, allPoints);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Get_All_Points_Negative) {
    // Arrange
    IntegerNumericalInterval ni("(-4, -1]");
    vector<int> allPointsR = { -3, -2, -1 };

    // Act
    vector<int> allPoints = ni.getAllPoints();

    // Assert
    EXPECT_EQ(allPointsR, allPoints);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Get_All_Points_Interval_Point) {
    // Arrange
    IntegerNumericalInterval ni("[1,1]");
    vector<int> allPointsR = { 1 };

    // Act
    vector<int> allPoints = ni.getAllPoints();

    // Assert
    EXPECT_EQ(allPointsR, allPoints);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Get_All_Points_Open_Interval) {
    // Arrange
    IntegerNumericalInterval ni("(1,5)");
    vector<int> allPointsR = { 2, 3, 4 };

    // Act
    vector<int> allPoints = ni.getAllPoints();

    // Assert
    EXPECT_EQ(allPointsR, allPoints);
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Check_Points_Contain) {
    // Arrange
    IntegerNumericalInterval ni("[2,6)");
    vector<int> points = { 2, 4 };

    // Assert
    EXPECT_TRUE(ni.isContainPoints(points));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Check_Points_Not_Contain) {
    // Arrange
    IntegerNumericalInterval ni("[2,6)");
    vector<int> points = { -1, 1, 6, 10 };

    // Assert
    EXPECT_FALSE(ni.isContainPoints(points));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Check_Range_Contain) {
    // Arrange
    IntegerNumericalInterval ni("[2,10)");
    IntegerNumericalInterval ni1("[3,5]");

    // Assert
    EXPECT_TRUE(ni.isContainsRange(ni1));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Can_Check_Range_Not_Contain) {
    // Arrange
    IntegerNumericalInterval ni("[2,6)");
    IntegerNumericalInterval ni1("[7,10)");

    // Assert
    EXPECT_FALSE(ni.isContainsRange(ni1));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Can_Check_Equal_Range_Contain) {
    // Arrange
    IntegerNumericalInterval ni("[3,5]");
    IntegerNumericalInterval ni1("[3,5]");

    // Assert
    EXPECT_TRUE(ni.isContainsRange(ni1));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Two_Intervals_Has_Not_Overlaps) {
    // Arrange
    IntegerNumericalInterval ni("[2,5)");
    IntegerNumericalInterval ni1("[7,10)");

    // Assert
    EXPECT_FALSE(ni.isHaveOverlapsRange(ni1));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest, Two_Intervals_Has_Overlaps) {
    // Arrange
    IntegerNumericalInterval ni("[2,5)");
    IntegerNumericalInterval ni1("[3,10)");

    // Assert
    EXPECT_TRUE(ni.isHaveOverlapsRange(ni1));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Two_Intervals_Has_Overlaps_Left_Contains_Right) {
    // Arrange
    IntegerNumericalInterval ni("[2,10)");
    IntegerNumericalInterval ni1("[3,5)");

    // Assert
    EXPECT_TRUE(ni.isHaveOverlapsRange(ni1));
}

TEST(Okunev_Boris_IntegerNumericalIntervalTest,
    Two_Intervals_Has_Overlaps_Right_Contains_Left) {
    // Arrange
    IntegerNumericalInterval ni("[3,5)");
    IntegerNumericalInterval ni1("[2,10)");

    // Assert
    EXPECT_TRUE(ni.isHaveOverlapsRange(ni1));
}
