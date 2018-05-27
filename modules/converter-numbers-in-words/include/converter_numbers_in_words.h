// Copyright 2018 Usova Marina

#ifndef MODULES_CONVERTER_NUMBERS_IN_WORDS_INCLUDE_CONVERTER_NUMBERS_IN_WORDS_H_
#define MODULES_CONVERTER_NUMBERS_IN_WORDS_INCLUDE_CONVERTER_NUMBERS_IN_WORDS_H_

#include <string>

class ConverterNumbersInWords {
 public:
  ConverterNumbersInWords();
  explicit ConverterNumbersInWords(const double number);
  void SetNumber(const double number);
  double GetNumber();

  std::string ConvertToWords();

 private:
  double number;
  int GetLastDigit(int number);
  int GetTen(int number);
  int GetHundred(int number);
  int GetThousand(int number);
  int GetMillion(int number);
  int GetRemainderOfDivisionBy1000(int number);
  std::string GetWordsForNumberFrom_1_To_99(int number);
  std::string GetWordsForNumberFrom_1_To_999(int number);
  std::string GetWorldForElementaryNumber(int number);
};

#endif  // MODULES_CONVERTER_NUMBERS_IN_WORDS_INCLUDE_CONVERTER_NUMBERS_IN_WORDS_H_
