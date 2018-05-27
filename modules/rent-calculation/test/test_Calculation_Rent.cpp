// Copyright 2018 Boris Ermachenko

#include <gtest/gtest.h>

#include "include/Calculation_Rent.h"

TEST(Calculation_Rent_Test, Can_Create_Object) {
    // Assert and Arrange and Act
    ASSERT_NO_THROW(Calculation_Rent rent_tmp);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_postnum_hard_rate) {
    // Arrange
    Calculation_Rent r(50, 2, 3);

    // Act
    double result = r.Rent_Accum_Year_postnum_hard_rate();

    // Assert
    EXPECT_EQ(250, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_postnum_easy_rate) {
    // Arrange
    Calculation_Rent r(150.4, 20, 10);

    // Act
    double result = r.Rent_Accum_Year_postnum_easy_rate();

    // Assert
    EXPECT_EQ(288768, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_prenum_hard_rate) {
    // Arrange
    Calculation_Rent r(10000, 5, 2);

    // Act
    double result = r.Rent_Accum_Year_prenum_hard_rate();

    // Assert
    EXPECT_EQ(3630000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_Year_prenum_easy_rate) {
    // Arrange
    Calculation_Rent r(120000, 10, 5);

    // Act
    double result = r.Rent_Accum_Year_prenum_easy_rate();

    // Assert
    EXPECT_EQ(34200000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_P_Period_postnum) {
    // Arrange
    Calculation_Rent r(100, 4, 1);

    // Act
    double result = r.Rent_Accum_P_Period_postnum(5, 2, 2);

    // Assert
    EXPECT_EQ(164000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Accum_P_Period_prenum) {
    // Arrange
    Calculation_Rent r(100, 4, 1);

    // Act
    double result = r.Rent_Accum_P_Period_prenum(5, 2, 2);

    // Assert
    EXPECT_EQ(492000, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_postnum_hard_rate) {
    // Arrange
    Calculation_Rent r(7861, 8, 4);

    // Act
    double result = r.Rent_Modern_Year_postnum_hard_rate();

    // Assert
    EXPECT_EQ(1965.24496896, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_postnum_easy_rate) {
    // Arrange
    Calculation_Rent r(10000, 2, 10);

    // Act
    double result = r.Rent_Modern_Year_postnum_easy_rate();

    // Assert
    EXPECT_EQ(1385.28, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_prenum_hard_rate) {
    // Arrange
    Calculation_Rent r(50, 200, 3);

    // Act
    double result = r.Rent_Modern_Year_prenum_hard_rate();

    // Assert
    EXPECT_EQ(66.6667, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_Year_prenum_easy_rate) {
    // Arrange
    Calculation_Rent r(50, 2, 30000);

    // Act
    double result = r.Rent_Modern_Year_prenum_easy_rate();

    // Assert
    EXPECT_EQ(50, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_P_Period_postnum) {
    // Arrange
    Calculation_Rent r(100, 4, 1);

    // Act
    double result = r.Rent_Modern_P_Period_postnum(5, 2, 2);

    // Assert
    EXPECT_EQ(24.9962, result);
}

TEST(Calc_Rent_Test, Can_Calc_Rent_Modern_P_Period_prenum) {
    // Arrange
    Calculation_Rent r(100, 4, 1);

    // Act
    double result = r.Rent_Modern_P_Period_prenum(5, 2, 2);

    // Assert
    EXPECT_EQ(74.9886, result);
}



TEST(Calc_Rent_Test, no_Calc_Rent_with_very_big_parametr1) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(200000000, 1, 6));
}

TEST(Calc_Rent_Test, no_Calc_Rent_with_very_big_parametr2) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(3, 200000000, 6));
}

TEST(Calc_Rent_Test, no_Calc_Rent_with_very_big_parametr3) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(20, 1, 200000000));
}

TEST(Calc_Rent_Test, no_Calc_Rent_with_null_parametr1) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(0, 1, 6));
}

TEST(Calc_Rent_Test, no_Calc_Rent_with_null_parametr2) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(0, 1, 6));
}


TEST(Calc_Rent_Test, no_Calc_Rent_with_null_parametr3) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(0, 1, 6));
}

TEST(Calc_Rent_Test, no_Calc_Rent_with_negative_parametr1) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(-1, 1, 6));
}


TEST(Calc_Rent_Test, no_Calc_Rent_with_negative_parametr2) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(1, -1, 6));
}


TEST(Calc_Rent_Test, no_Calc_Rent_with_negative_parametr3) {
    // Arrange and Act and Assert
    ASSERT_ANY_THROW(Calculation_Rent r(1, 1, -6));
}



TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_postnum_with_null_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_postnum(0, 1, 1));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_postnum_with_big_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_postnum(200000000, 2, 1));
}
TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_prenum_with_null_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_prenum(5, 0, 20000));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Accum_P_Period_prenum_with_big_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Accum_P_Period_prenum(5, 2, 20000000));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_postnum_with_null_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_postnum(0, 2, 2));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_postnum_with_big_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_postnum(300000000, 2, 2));
}
TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_prenum_with_null_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_prenum(0, 4, 5));
}

TEST(Calc_Rent_Test, no_Calc_Rent_Modern_P_Period_prenum_with_big_par) {
    // Arrange
    Calculation_Rent r;

    // Assert and Act
    ASSERT_ANY_THROW(r.Rent_Modern_P_Period_prenum(200000000, 2, 2));
}
