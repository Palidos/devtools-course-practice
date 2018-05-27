// Copyright 2018 Grishin Anton

#include <gtest/gtest.h>
#include <string>

#include "include/currency_converter.h"

class CurrencyConverterTest : public ::testing::Test {
 protected:
    double epsilon = 0.001;
};

TEST_F(CurrencyConverterTest, Can_Create_With_Dollar_And_Euro) {
    // Arrange
    double usd = 26.0;
    double eur = 20.0;

    // Act
    CurrencyConverter currency(usd, eur);

    // Assert
    EXPECT_NEAR(usd, currency.getUsdRate(), CurrencyConverterTest::epsilon);
    EXPECT_NEAR(eur, currency.getEurRate(), CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Create_Via_Copying) {
    // Arrange
    CurrencyConverter currency(26.0, 20.0);

    // Act
    CurrencyConverter expected_currency = currency;

    // Assert
    EXPECT_EQ(expected_currency, currency);
}

TEST_F(CurrencyConverterTest, Can_Assigment) {
    // Arrange
    CurrencyConverter currency1(0.0, 0.0);
    CurrencyConverter currency2(26.0, 20.0);

    // Act
    currency1 = currency2;

    // Assert
    EXPECT_EQ(currency1, currency2);
}

TEST_F(CurrencyConverterTest, Can_Set_Usd) {
    // Arrange
    CurrencyConverter currency;
    double usd = 20.0;

    // Act
    currency.setUsdRate(usd);

    // Assert
    EXPECT_NEAR(usd, currency.getUsdRate(), CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Set_Eur) {
    // Arrange
    CurrencyConverter currency;
    double eur = 26.0;

    // Act
    currency.setEurRate(eur);

    // Assert
    EXPECT_NEAR(eur, currency.getEurRate(), CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Currency_Is_Equal_To_Itself) {
    // Arrange
    CurrencyConverter currency(26.0, 14.0);

    // Act & Assert
    EXPECT_TRUE(currency == currency);
}

TEST_F(CurrencyConverterTest, Equal_Currency_Are_Equal) {
    // Arrange
    CurrencyConverter currency1(26.0, 14.0);
    CurrencyConverter currency2(26.0, 14.0);

    // Act & Assert
    EXPECT_EQ(currency1, currency2);
}


TEST_F(CurrencyConverterTest, Different_Currency_Not_Equal) {
    // Arrange
    CurrencyConverter currency1(26.0, 14.0);
    CurrencyConverter currency2(26.1, 14.1);

    // Act & Assert
    EXPECT_TRUE(currency1 != currency2);
}

TEST_F(CurrencyConverterTest, Can_Convert_Rub_To_Usd) {
    // Arrange
    CurrencyConverter currency;
    double rub = 26.0;

    // Act
     double usd = currency.roubleToDollar(rub);

    // Assert
    double expected_usd = rub / currency.getUsdRate();
    EXPECT_NEAR(usd, expected_usd, CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Convert_Rub_To_Eur) {
    // Arrange
    CurrencyConverter currency;
    double rub = 26.0;

    // Act
    double eur = currency.roubleToEuro(rub);

    // Assert
    double expected_eur = rub / currency.getEurRate();
    EXPECT_NEAR(eur, expected_eur, CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Convert_Eur_To_Rub) {
    // Arrange
    CurrencyConverter currency;
    double eur = 26.0;

    // Act
    double rub = currency.euroToRouble(eur);

    // Assert
    double expected_rub = eur * currency.getEurRate();
    EXPECT_NEAR(rub, expected_rub, CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Convert_Usd_To_Rub) {
    // Arrange
    CurrencyConverter currency;
    double usd = 26.0;

    // Act
    double rub = currency.dollarToRouble(usd);

    // Assert
    double expected_rub = usd * currency.getUsdRate();
    EXPECT_NEAR(rub, expected_rub, CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Convert_Usd_To_Eur) {
    // Arrange
    CurrencyConverter currency;
    double usd = 26.0;

    // Act
    double eur = currency.dollarToEuro(usd);

    // Assert
    double expected_eur = usd * currency.getUsdRate() / currency.getEurRate();
    EXPECT_NEAR(eur, expected_eur, CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest, Can_Convert_Eur_To_Usd) {
    // Arrange
    CurrencyConverter currency;
    double eur = 26.0;

    // Act
    double usd = currency.euroToDollar(eur);

    // Assert
    double expected_usd = eur * currency.getEurRate() / currency.getUsdRate();
    EXPECT_NEAR(usd, expected_usd, CurrencyConverterTest::epsilon);
}

TEST_F(CurrencyConverterTest,
    Do_Throw_When_Convert_Rub_To_Eur_By_Zero) {
    // Arrange
    CurrencyConverter currency(0.0, 0.0);
    double rub = 10.0;

    // Act & Assert
    EXPECT_THROW(currency.roubleToEuro(rub), std::string);
}

TEST_F(CurrencyConverterTest,
    Do_Throw_When_Convert_Rub_To_Usd_By_Zero) {
    // Arrange
    CurrencyConverter currency(0.0, 0.0);
    double rub = 10.0;

    // Act & Assert
    EXPECT_THROW(currency.roubleToDollar(rub), std::string);
}

TEST_F(CurrencyConverterTest,
    Do_Throw_When_Convert_Eur_To_Usd_By_Zero) {
    // Arrange
    CurrencyConverter currency(0.0, 3.0);
    double eur = 10.0;

    // Act & Assert
    EXPECT_THROW(currency.euroToDollar(eur), std::string);
}

TEST_F(CurrencyConverterTest,
    Do_Throw_When_Convert_Usd_To_Eur_By_Zero) {
    // Arrange
    CurrencyConverter currency(3.0, 0.0);
    double usd = 10.0;

    // Act & Assert
    EXPECT_THROW(currency.dollarToEuro(usd), std::string);
}
