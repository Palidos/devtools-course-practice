// Copyright 2018 Bederdinov Daniil

#include <gtest/gtest.h>

#include "include/temperature_converter.h"

TEST(Temperature_Converter_Test, Can_Create_Object) {
    // Assert
    ASSERT_NO_THROW(TemperatureConverter temp);
}

TEST(Temperature_Converter_Test, Can_Convert_Kelvin_To_Celsius) {
    // Arrange
    double kelvin = 10;
    TemperatureConverter temp;

    // Act
    double result = temp.kelToCel(kelvin);

    // Assert
    EXPECT_EQ(-263.15, result);
}

TEST(Temperature_Converter_Test, Can_Convert_Kelvin_To_Fahrenheit) {
    // Arrange
    double kelvin = 273;
    TemperatureConverter temp;

    // Act
    double result = temp.kelToFahr(kelvin);

    // Assert
    EXPECT_EQ((int)31.73, (int)result);
}

TEST(Temperature_Converter_Test, Can_Convert_Kelvin_To_Newton) {
    // Arrange
    double kelvin = 400;
    TemperatureConverter temp;

    // Act
    double result = temp.kelToNewt(kelvin);

    // Assert
    EXPECT_EQ((int)41.8605, (int)result);
}

TEST(Temperature_Converter_Test, Can_Convert_Celsius_To_Kelvin) {
    // Arrange
    double celsius = -273.15;
    TemperatureConverter temp;

    // Act
    double result = temp.celToKel(celsius);

    // Assert
    EXPECT_EQ(0, result);
}

TEST(Temperature_Converter_Test, Can_Convert_Celsius_To_Fahrenheit) {
    // Arrange
    double celsius = -40;
    TemperatureConverter temp;

    // Act
    double result = temp.celToFahr(celsius);

    // Assert
    EXPECT_EQ(-40, result);
}

TEST(Temperature_Converter_Test, Can_Convert_Celsius_To_Newton) {
    // Arrange
    double celsius = 3;
    TemperatureConverter temp;

    // Act
    double result = temp.celToNewt(celsius);

    // Assert
    EXPECT_EQ(0.99, result);
}

TEST(Temperature_Converter_Test, Can_Convert_Fahrenheit_To_Celsius) {
    // Arrange
    double fahrenheit = 5;
    TemperatureConverter temp;

    // Act
    double result = temp.fahrToCel(fahrenheit);

    // Assert
    EXPECT_EQ(-15, result);
}

TEST(Temperature_Converter_Test, Can_Convert_Fahrenheit_To_Kelvin) {
    // Arrange
    double fahrenheit = -211;
    TemperatureConverter temp;

    // Act
    double result = temp.fahrToKel(fahrenheit);

    // Assert
    EXPECT_EQ((int)138.15, (int)result);
}

TEST(Temperature_Converter_Test, Can_Convert_Fahrenheit_To_Newton) {
    // Arrange
    double fahrenheit = 2;
    TemperatureConverter temp;

    // Act
    double result = temp.fahrToNewt(fahrenheit);

    // Assert
    EXPECT_EQ((int)-5.49, (int)result);
}

TEST(Temperature_Converter_Test, Can_Convert_Newton_To_Celsius) {
    // Arrange
    double newton = 3;
    TemperatureConverter temp;

    // Act
    double result = temp.newtToCel(newton);

    // Assert
    EXPECT_EQ(9.090909, result);
}

TEST(Temperature_Converter_Test, Can_Convert_Newton_To_Kelvin) {
    // Arrange
    double newton = -100;
    TemperatureConverter temp;

    // Act
    double result = temp.newtToKel(newton);

    // Assert
    EXPECT_EQ((int)-29.8803, (int)result);
}

TEST(Temperature_Converter_Test, Can_Convert_Newton_To_Fahrenheit) {
    // Arrange
    double newton = 2;
    TemperatureConverter temp;

    // Act
    double result = temp.newtToFahr(newton);

    // Assert
    EXPECT_EQ(42.90909, result);
}
