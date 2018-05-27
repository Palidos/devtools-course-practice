// Copyright 2018 Churakov Sergey

#include <gtest/gtest.h>
#include <vector>

#include "include/Invest.h"

TEST(Churakov_Sergey_Investition, can_create_empty_investition) {
    //  AAA
    ASSERT_NO_THROW(Investition inv);
}

TEST(Churakov_Sergey_Investition, can_create_investition ) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;

    //  Assert
    ASSERT_NO_THROW(Investition inv(years, Income_vector,
                    Expense_vector, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_year ) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = -2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;

    //  Assert
    ASSERT_ANY_THROW(Investition inv(years, Income_vector,
                     Expense_vector, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_negative_rate) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = -20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;

    //  Assert
    ASSERT_ANY_THROW(Investition inv(years, Income_vector,
                     Expense_vector, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_investition_with_huge_rate) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 201;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;

    //  Assert
    ASSERT_ANY_THROW(Investition inv(years, Income_vector,
                     Expense_vector, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_invest_with_neg_income) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = -10;
    Expense_vector[0] = Expense_vector[1] = 10;

    //  Assert
    ASSERT_ANY_THROW(Investition inv(years, Income_vector,
                     Expense_vector, rate));
}

TEST(Churakov_Sergey_Investition, cant_create_invest_with_neg_expenses) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = -10;

    //  Assert
    ASSERT_ANY_THROW(Investition inv(years, Income_vector,
                     Expense_vector, rate));
}

TEST(Churakov_Sergey_Investition, can_get_year_count) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.GetYearCount(), 2);
}

TEST(Churakov_Sergey_Investition, can_get_rate) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.GetRate(), 20);
}

TEST(Churakov_Sergey_Investition, can_get_incomes) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(*(inv.GetIncomes())+0, 10);
}

TEST(Churakov_Sergey_Investition, can_get_expenses) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(*(inv.GetExpenses()) + 0, 10);
}

TEST(Churakov_Sergey_Investition, can_get_income_of_year) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.GetIncomeOfYear(0), 10);
}

TEST(Churakov_Sergey_Investition, can_get_expense_of_year) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.GetExpenseOfYear(0), 10);
}

TEST(Churakov_Sergey_Investition, cant_get_income_of_unexisting_year) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    ASSERT_ANY_THROW(inv.GetIncomeOfYear(10));
}

TEST(Churakov_Sergey_Investition, cant_get_expense_of_unexisting_year) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    ASSERT_ANY_THROW(inv.GetExpenseOfYear(10));
}

TEST(Churakov_Sergey_Investition, can_set_rate) {
    //  Arrange
    double rate;
    Investition inv;

    //  Act
    rate = 20;
    inv.SetRate(rate);

    //  Assert
    EXPECT_EQ(inv.GetRate(), rate);
}

TEST(Churakov_Sergey_Investition, can_set_year_count) {
    //  Arrange
    int years;
    Investition inv;

    //  Act
    years = 3;
    inv.SetYearCount(years);

    //  Assert
    EXPECT_EQ(inv.GetYearCount(), years);
}

TEST(Churakov_Sergey_Investition, can_set_lesser_year_count) {
    //  Arrange
    std::vector<money> Income_vector(2);
    std::vector<money> Expense_vector(2);
    int years;
    double rate;

    //  Act
    years = 2;
    rate = 20;
    Income_vector[0] = Income_vector[1] = 10;
    Expense_vector[0] = Expense_vector[1] = 10;
    Investition inv(years, Income_vector, Expense_vector, rate);
    years = 1;
    inv.SetYearCount(years);

    //  Assert
    EXPECT_EQ(inv.GetYearCount(), years);
}

TEST(Churakov_Sergey_Investition, can_set_incomes) {
    //  Arrange
    std::vector<money> Input_vector(2);
    Investition inv;

    //  Act
    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        Input_vector[i] = i;
    inv.SetIncomes(Input_vector);

    //  Assert
    EXPECT_TRUE(inv.GetIncomeOfYear(0) == 0 && inv.GetIncomeOfYear(1) == 1);
}

TEST(Churakov_Sergey_Investition, can_set_expenses) {
    //  Arrange
    std::vector<money> Input_vector(2);
    Investition inv;

    //  Act
    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        Input_vector[i] = i;
    inv.SetExpenses(Input_vector);

    //  Assert
    EXPECT_TRUE(inv.GetExpenseOfYear(0) == 0 && inv.GetExpenseOfYear(1) == 1);
}

TEST(Churakov_Sergey_Investition, cant_set_invalid_rate) {
    //  Arrange
    double rate;
    Investition inv;

    //  Act
    rate = -20;

    //  Assert
    ASSERT_ANY_THROW(inv.SetRate(rate));
}

TEST(Churakov_Sergey_Investition, cant_set_invalid_year_count) {
    //  Arrange
    int years;
    Investition inv;

    //  Act
    years = -3;

    //  Assert
    ASSERT_ANY_THROW(inv.SetYearCount(years));
}

TEST(Churakov_Sergey_Investition, cant_set_negative_incomes) {
    //  Arrange
    std::vector<money> Input_vector(2);
    Investition inv;

    //  Act
    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        Input_vector[i] = -i;

    ASSERT_ANY_THROW(inv.SetIncomes(Input_vector));
}

TEST(Churakov_Sergey_Investition, cant_set_incomes_with_small_a) {
    //  Arrange
    std::vector<money> Input_vector(1);
    Investition inv;

    //  Act
    inv.SetYearCount(2);
    Input_vector[0] = 1;

    //  Assert
    ASSERT_ANY_THROW(inv.SetIncomes(Input_vector));
}

TEST(Churakov_Sergey_Investition, cant_set_negative_expenses) {
    //  Arrange
    std::vector<money> Input_vector(2);
    Investition inv;

    //  Act
    inv.SetYearCount(2);
    for (int i = 0; i < 2; i++)
        Input_vector[i] = -i;

    //  Assert
    ASSERT_ANY_THROW(inv.SetExpenses(Input_vector));
}

TEST(Churakov_Sergey_Investition, cant_set_expenses_with_small_a) {
    //  Arrange
    std::vector<money> Input_vector(1);
    Investition inv;

    //  Act
    inv.SetYearCount(2);
    Input_vector[0] = 1;

    //  Assert
    ASSERT_ANY_THROW(inv.SetExpenses(Input_vector));
}

TEST(Churakov_Sergey_Investition, can_find_NPV) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_TRUE(inv.FindNPV() > 687 && inv.FindNPV() < 688);
}

TEST(Churakov_Sergey_Investition, can_find_NPV_for_rate) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.FindNPV(), inv.FindNPV(8));
}

TEST(Churakov_Sergey_Investition, can_find_recoupment_time) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.FindRecoupmentTime(), 3);
}

TEST(Churakov_Sergey_Investition, cant_find_recoupment_time_when_no_answer) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 88;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.FindRecoupmentTime(), -1);
}

TEST(Churakov_Sergey_Investition, can_find_IRR) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_TRUE(inv.FindIRR() > 24 && inv.FindIRR() < 24.2);
}

TEST(Churakov_Sergey_Investition, cant_find_IRR_when_it_is_infinite) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 0;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.FindIRR(), -2);
}

TEST(Churakov_Sergey_Investition, cant_find_IRR_when_there_is_no_recoupment) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 100;
    Income_vector[2] = Income_vector[3] = 80;
    Income_vector[4] = 60;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_EQ(inv.FindIRR(), -1);
}

TEST(Churakov_Sergey_Investition, can_find_PBIndex) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = Expense_vector[2] = 0;
    Expense_vector[3] = Expense_vector[4] = 0;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    EXPECT_TRUE(inv.FindPBIndex()> 0.46 && inv.FindPBIndex() <0.47);
}

TEST(Churakov_Sergey_Investition, cant_find_PBIndex_with_multiple_expenses) {
    //  Arrange
    std::vector<money> Income_vector(5);
    std::vector<money> Expense_vector(5);
    int years;
    double rate;

    //  Act
    years = 5;
    rate = 8;
    Expense_vector[0] = 2000;
    Income_vector[0] = Expense_vector[1] = 0;
    Expense_vector[2] = Expense_vector[3] = 0;
    Expense_vector[4] = 10;
    Income_vector[1] = 1000;
    Income_vector[2] = Income_vector[3] = 800;
    Income_vector[4] = 600;
    Investition inv(years, Income_vector, Expense_vector, rate);

    //  Assert
    ASSERT_ANY_THROW(inv.FindPBIndex());
}
