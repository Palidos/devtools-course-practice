// Copyright 2018 Kuznetsov Konstantin

#include <gtest/gtest.h>

#include <cmath>
#include <vector>

#include "include/probability_distribution.h"

TEST(ProbabilityDistributionTest, Can_Create_DescretePD) {
    // Arrange & Assert
    EXPECT_NO_THROW(DescretePD dpd);
}

TEST(ProbabilityDistributionTest, Can_Create_DescretePD_Using_PMF) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    // both vectors define probability mass function
    DescretePD dpd;

    // Act & Assert
    EXPECT_NO_THROW(dpd.setData(values, probabilities));
}

TEST(ProbabilityDistributionTest, Throws_When_Vectors_Do_Not_Match) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0 };  // size = 2
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };  // size = 3
    DescretePD dpd;

    // Act & Assert
    EXPECT_ANY_THROW(dpd.setData(values, probabilities));
}

TEST(ProbabilityDistributionTest,
     Throws_When_Sum_Of_Probabilities_Is_Incorrect) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.4, 0.3 };  // sum != 1
    DescretePD dpd;

    // Act & Assert
    EXPECT_ANY_THROW(dpd.setData(values, probabilities));
}

TEST(ProbabilityDistributionTest, Throws_When_Some_Probabilities_Are_Negative) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0, 7.0, 9.0 };
    std::vector<double> probabilities = { 0.2, 0.4, 0.3, -0.1, 0.1 };
    DescretePD dpd;

    // Act & Assert
    EXPECT_ANY_THROW(dpd.setData(values, probabilities));
}

TEST(ProbabilityDistributionTest, Can_Check_If_There_Is_No_Data) {
    // Arrange
    DescretePD dpd;

    // Act & Assert
    EXPECT_FALSE(dpd.hasData());
}

TEST(ProbabilityDistributionTest, Can_Check_If_There_Is_Data) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_TRUE(dpd.hasData());
}

TEST(ProbabilityDistributionTest, Throws_If_There_Is_No_Data_Test_1) {
    // Arrange
    DescretePD dpd;
    std::vector<double> values;

    // Act & Assert
    EXPECT_ANY_THROW(values = dpd.getValues());
}

TEST(ProbabilityDistributionTest, Can_Get_Values) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(1.0, dpd.getValues()[0]);
    EXPECT_EQ(3.0, dpd.getValues()[1]);
    EXPECT_EQ(5.0, dpd.getValues()[2]);
}

TEST(ProbabilityDistributionTest, Throws_If_There_Is_No_Data_Test_2) {
    // Arrange
    DescretePD dpd;
    std::vector<double> probabilities;

    // Act & Assert
    EXPECT_ANY_THROW(probabilities = dpd.getProbabilities());
}

TEST(ProbabilityDistributionTest, Can_Get_Probabilities) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(0.2, dpd.getProbabilities()[0]);
    EXPECT_EQ(0.5, dpd.getProbabilities()[1]);
    EXPECT_EQ(0.3, dpd.getProbabilities()[2]);
}

TEST(ProbabilityDistributionTest, Throws_If_There_Is_No_Data_Test_3) {
    // Arrange
    DescretePD dpd;

    // Act & Assert
    EXPECT_ANY_THROW(dpd.expectedValue());
}

TEST(ProbabilityDistributionTest, Can_Get_Expected_Value) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    double expectedValue = 3.2;
    DescretePD dpd;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(expectedValue, dpd.expectedValue());
}

TEST(ProbabilityDistributionTest, Throws_If_There_Is_No_Data_Test_4) {
    // Arrange
    DescretePD dpd;

    // Act & Assert
    EXPECT_ANY_THROW(dpd.variance());
}

TEST(ProbabilityDistributionTest, Can_Get_Variance) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    double variance = 1.96;
    DescretePD dpd;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(variance, dpd.variance());
}

TEST(ProbabilityDistributionTest, Throws_If_There_Is_No_Data_Test_5) {
    // Arrange
    DescretePD dpd;
    unsigned char k = 1;

    // Act & Assert
    EXPECT_ANY_THROW(dpd.rawMoment(k));
}

TEST(ProbabilityDistributionTest, Can_Get_Zeroth_Row_Moment) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;
    double rawMoment = 1.0;  // zeroth row moment equals 1
    unsigned char k = 0;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(rawMoment, dpd.rawMoment(k));
}

TEST(ProbabilityDistributionTest, Can_Get_First_Row_Moment) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;
    double rawMoment = 0.0;
    unsigned char k = 1;

    // Act
    dpd.setData(values, probabilities);
    rawMoment = dpd.expectedValue();  // first row moment is the mean

    // Assert
    EXPECT_EQ(rawMoment, dpd.rawMoment(k));
}

TEST(ProbabilityDistributionTest, Can_Get_Second_Row_Moment) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;
    double rawMoment = 12.2;
    unsigned char k = 2;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(rawMoment, dpd.rawMoment(k));
}

TEST(ProbabilityDistributionTest, Throws_If_There_Is_No_Data_Test_6) {
    // Arrange
    DescretePD dpd;
    unsigned char k = 1;

    // Act & Assert
    EXPECT_ANY_THROW(dpd.centralMoment(k));
}

TEST(ProbabilityDistributionTest, Can_Get_Zeroth_Central_Moment) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;
    double centralMoment = 1.0;  // zeroth central moment equals 1
    unsigned char k = 0;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(centralMoment, dpd.centralMoment(k));
}

TEST(ProbabilityDistributionTest, Can_Get_First_Central_Moment) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;
    double centralMoment = 0.0;  // first central moment equals 0
    unsigned char k = 1;

    // Act
    dpd.setData(values, probabilities);

    // Assert
    EXPECT_EQ(centralMoment, dpd.centralMoment(k));
}

TEST(ProbabilityDistributionTest, Can_Get_Second_Central_Moment) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;
    double centralMoment = 0.0;
    unsigned char k = 2;

    // Act
    dpd.setData(values, probabilities);
    centralMoment = dpd.variance();  // second central moment is the variance

    // Assert
    EXPECT_EQ(centralMoment, dpd.centralMoment(k));
}

TEST(ProbabilityDistributionTest, Can_Get_Third_Central_Moment) {
    // Arrange
    std::vector<double> values = { 1.0, 3.0, 5.0 };
    std::vector<double> probabilities = { 0.2, 0.5, 0.3 };
    DescretePD dpd;
    double centralMoment = 0.0;
    unsigned char k = 3;
    double eps = 1.0e-6;

    // Act
    dpd.setData(values, probabilities);
    // central moment can be calculated through row moments
    centralMoment = dpd.rawMoment(3) - 3.0 * dpd.rawMoment(1)
        * dpd.rawMoment(2) + 2.0 * pow(dpd.rawMoment(1), 3);

    // Assert
    EXPECT_NEAR(centralMoment, dpd.centralMoment(k), eps);
}
