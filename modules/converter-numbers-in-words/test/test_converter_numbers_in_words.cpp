// Copyright 2018 Usova Marina

#include <gtest/gtest.h>

#include <string>

#include "include/converter_numbers_in_words.h"

class ConverterNumbersInWordsTest : public ::testing::Test {
 protected:
  double epsilon = 0.0001;
};

TEST_F(ConverterNumbersInWordsTest, Can_Use_Default_Constructor) {
  // Act
  ConverterNumbersInWords converter;

  // Assert
  EXPECT_EQ(0, converter.GetNumber());
}

TEST_F(ConverterNumbersInWordsTest, Can_Use_Copy_Constructor) {
  // Arrange
  double number = 123.0;

  // Act
  ConverterNumbersInWords converter(number);

  // Assert
  EXPECT_EQ(number, converter.GetNumber());
}

TEST_F(ConverterNumbersInWordsTest, Can_Set_Number) {
  // Arrange
  ConverterNumbersInWords converter;
  double number = 123.0;

  // Act
  converter.SetNumber(number);

  // Assert
  EXPECT_NEAR(number, converter.GetNumber(),
    ConverterNumbersInWordsTest::epsilon);
}

TEST_F(ConverterNumbersInWordsTest, Can_Get_Number) {
  // Arrange
  ConverterNumbersInWords converter(123.0);

  // Act
  double number = converter.GetNumber();

  // Assert
  EXPECT_NEAR(123.0, number, ConverterNumbersInWordsTest::epsilon);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Zero_To_Word) {
  // Arrange
  ConverterNumbersInWords converter(0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("zero", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_One_Elementary_Digit_To_Word) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(6.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("six", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_1) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(11.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("eleven", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_2) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(12.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("twelve", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_3) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(14.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("fourteen", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_4) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(15.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("fifteen", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_5) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(17.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("seventeen", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_6) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(18.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("eighteen", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_7) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(19.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("nineteen", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Number_From_10_to_19_8) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(10.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("ten", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Round_Number_From_20_to_99) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(50.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("fifty", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_20_to_99) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(49.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("forty nine", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Elementary_Round_Number_From_100_to_999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(500.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("five hundred", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_100_to_999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(467.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("four hundred and sixty seven", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_1000_to_9999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(5628.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("five thousand six hundred and twenty eight", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Thousand_To_Word) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(7000.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("seven thousand", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Million_To_Word) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(2000013.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("two million thirteen", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_9999_to_99999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(73790.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("seventy three thousand seven hundred and ninety", result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_99999_to_999999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(506816.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("five hundred and six thousand eight hundred and sixteen", result);
}

TEST_F(ConverterNumbersInWordsTest,
  Can_Convert_Number_From_999999_to_9999999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(4300932.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("four million three hundred thousand nine hundred and thirty two",
    result);
}

TEST_F(ConverterNumbersInWordsTest, Can_Convert_Number_From_9999999) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(200105081.0);

  // Act
  std::string result = converter.ConvertToWords();

  // Assert
  EXPECT_EQ("two hundred million one hundred and five thousand eighty one",
    result);
}

TEST_F(ConverterNumbersInWordsTest, No_Throw_When_Large_Number) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(9999999991.0);

  // Act & Assert
  EXPECT_ANY_THROW(converter.ConvertToWords());
}

TEST_F(ConverterNumbersInWordsTest, No_Throw_When_Negative_Number) {
  // Arrange
  ConverterNumbersInWords converter;
  converter.SetNumber(-1332.0);

  // Act & Assert
  EXPECT_ANY_THROW(converter.ConvertToWords());
}
