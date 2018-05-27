// Copyright 2017 Volkov Daniel

#include <gtest/gtest.h>
#include "include/deposit-calculator.h"

TEST(Volkov_Daniel_DepositTest, can_create_deposit) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(Deposit test);
}

TEST(Volkov_Daniel_DepositTest, exception_when_wrong_sum) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(-10000));
}

TEST(Volkov_Daniel_DepositTest, exception_when_wrong_percent) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(10000, -17));
}

TEST(Volkov_Daniel_DepositTest, exception_when_wrong_duration) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(10000, 10, -10));
}

TEST(Volkov_Daniel_DepositTest, exception_when_wrong_type_cap) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(10000, 8, 360, 10));
}

TEST(Volkov_Daniel_DepositTest, creating_deposit_with_full_parameters) {
    // Arrange & Act & Assert
    ASSERT_NO_THROW(Deposit test(234567, 15, 100, 2, false));
}

TEST(Volkov_Daniel_DepositTest, creating_deposit_with_full_parameters2) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(234567, -15, 100, 2, false));
}

TEST(Volkov_Daniel_DepositTest, creating_deposit_with_full_parameters3) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(-234567, 15, 100, 2, false));
}

TEST(Volkov_Daniel_DepositTest, creating_deposit_with_full_parameters4) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(234567, 15, -100, 2, false));
}

TEST(Volkov_Daniel_DepositTest, creating_deposit_with_full_parameters5) {
    // Arrange & Act & Assert
    ASSERT_ANY_THROW(Deposit test(234567, 15, 100, -2, false));
}

TEST(Volkov_Daniel_DepositTest, exception_when_wrong_num_of_days) {
    // Arrange
    Deposit test(10000, 8, 360, 1);

    // Act & Assert
    ASSERT_ANY_THROW(test.IncomeAfterTimes(-12, 10, 2));
}

TEST(Volkov_Daniel_DepositTest, exception_when_wrong_num_of_months) {
    // Arrange
    Deposit test(10000, 8, 360, 1);

    // Act & Assert
    ASSERT_ANY_THROW(test.IncomeAfterTimes(12, -10, 2));
}

TEST(Volkov_Daniel_DepositTest, exception_when_wrong_num_of_years) {
    // Arrange
    Deposit test(10000, 8, 360, 1);

    // Act & Assert
    ASSERT_ANY_THROW(test.IncomeAfterTimes(12, 10, -2));
}

TEST(Volkov_Daniel_DepositTest, equality_control_value) {
    // Arrange
    Deposit test(104000, 7.5, 90, 1);

    // Act & Assert
    EXPECT_EQ((int)test.getIncome(), 1962);
}

TEST(Volkov_Daniel_DepositTest, equality_control_value_type2) {
    // Arrange
    Deposit test(104000, 7.5, 3, 0);

    // Act & Assert
    EXPECT_EQ((int)test.getIncome(), 64);
}

TEST(Volkov_Daniel_DepositTest, equality_control_value_type3) {
    // Arrange
    Deposit test(104000, 10, 365, 2);

    // Act & Assert
    EXPECT_EQ((int)test.getIncome(), 10400);
}

TEST(Volkov_Daniel_DepositTest, equality_control_value2) {
    // Arrange
    Deposit test(104000, 7.5, 90, 1);

    // Act & Assert
    EXPECT_EQ((int)test.IncomeAfterTimes(50, 2, 1), 10027);
}

TEST(Volkov_Daniel_DepositTest, equality_control_value3) {
    // Arrange
    Deposit test(104000, 7.5, 90, 2);

    // Act & Assert
    EXPECT_NE((int)test.IncomeAfterTimes(50, 2, 1), 10027);
}

TEST(Volkov_Daniel_DepositTest, equality_control_value4) {
    // Arrange
    Deposit test(104000, 7.5, 90, 0);

    // Act & Assert
    EXPECT_NE((int)test.IncomeAfterTimes(50, 2, 1), 10027);
}

TEST(Volkov_Daniel_DepositTest, equality_profits_same_deposits) {
    // Arrange
    Deposit test(10000, 7.5, 90, 1), test2(10000, 7.5, 90, 1);

    // Act & Assert
    EXPECT_EQ(test.getIncome(), test2.getIncome());
}

TEST(Volkov_Daniel_DepositTest, not_equality_profits_dif_deposits) {
    // Arrange
    Deposit test(10000, 7.5, 90, 1), test2(10000, 7.5, 90, 2);

    // Act & Assert
    EXPECT_NE(test.getIncome(), test2.getIncome());
}

TEST(Volkov_Daniel_DepositTest, equality_profits_same_deposits2) {
    // Arrange
    Deposit test(10000, 7.5, 90, 1), test2(10000, 7.5, 90, 1);

    // Act & Assert
    EXPECT_EQ(test.IncomeAfterTimes(0, 0, 1), test2.IncomeAfterTimes(0, 0, 1));
}

TEST(Volkov_Daniel_DepositTest, equality_profits_deposit) {
    // Arrange
    Deposit test(10000, 7.5, 90, 1);

    // Act & Assert
    EXPECT_EQ(test.IncomeAfterTimes(90, 0, 0), test.getIncome());
}

TEST(Volkov_Daniel_DepositTest, equality_balance) {
    // Arrange
    Deposit test(104000, 7.5, 90, 1);

    // Act
    float balance = test.BalanceAfterTimes(90);
    // Assert
    EXPECT_EQ((int)balance, 105962);
}

TEST(Volkov_Daniel_DepositTest, equality_dif_balance_initial_amount_profit) {
    // Arrange
    Deposit test(104000, 7.5, 90, 1, false);

    // Act
    float balance = test.BalanceAfterTimes(90);
    float income = test.getIncome();
    // Assert
    EXPECT_EQ((int)balance-104000, (int)income);
}

TEST(Volkov_Daniel_DepositTest, equality_dif_balance_initial_amount_profit2) {
    // Arrange
    Deposit test(104000, 7.5, 90, 0, false);

    // Act
    float balance = test.BalanceAfterTimes(90);
    float income = test.getIncome();
    // Assert
    EXPECT_EQ((int)balance-104000, (int)income);
}

TEST(Volkov_Daniel_DepositTest, equality_dif_balance_initial_amount_profit3) {
    // Arrange
    Deposit test(104000, 7.5, 90, 2, false);

    // Act
    float balance = test.BalanceAfterTimes(90);
    float income = test.getIncome();
    // Assert
    EXPECT_EQ((int)balance-104000, (int)income);
}

TEST(Volkov_Daniel_DepositTest, equality_dif_balance_initial_amount_profit4) {
    // Arrange
    Deposit test(104000, 7.5, 90, 2, false);

    // Act
    float balance = test.BalanceAfterTimes(90);
    float income = test.IncomeAfterTimes(1, 1, 1);
    // Assert
    EXPECT_NE((int)balance-104000, (int)income);
}

TEST(Volkov_Daniel_DepositTest, equality_dif_balance_initial_amount_profit5) {
    // Arrange
    Deposit test(104000, 7.5, 90, 1, false);

    // Act
    float balance = test.BalanceAfterTimes(90);
    float income = test.IncomeAfterTimes(1, 1, 1);
    // Assert
    EXPECT_NE((int)balance-104000, (int)income);
}

TEST(Volkov_Daniel_DepositTest, equality_dif_balance_initial_amount_profit6) {
    // Arrange
    Deposit test(104000, 7.5, 90, 0, false);

    // Act
    float balance = test.BalanceAfterTimes(90);
    float income = test.IncomeAfterTimes(1, 1, 1);
    // Assert
    EXPECT_NE((int)balance-104000, (int)income);
}

TEST(Volkov_Daniel_DepositTest, copy_constructor) {
    // Arrange
    Deposit test(104000, 7.5, 90, 0, false);

    // Act & Assert
    ASSERT_NO_THROW(Deposit test2(test));
}

TEST(Volkov_Daniel_DepositTest, equality_copy_constructor) {
    // Arrange
    Deposit test(104000, 7.5, 90, 0, false);

    // Act
    Deposit test2(test);

    // Assert
    EXPECT_EQ(test.getIncome(), test2.getIncome());
}
