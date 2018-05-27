// Copyright 2018 Usova Marina

#include "include/converter_numbers_in_words.h"

#include <string>
#include <stdexcept>

ConverterNumbersInWords::ConverterNumbersInWords() : number(0.0) {}

ConverterNumbersInWords::ConverterNumbersInWords(const double number_)
  : number(number_) {}

void ConverterNumbersInWords::SetNumber(const double number_) {
  number = number_;
}

double ConverterNumbersInWords::GetNumber() {
  return number;
}

std::string ConverterNumbersInWords::ConvertToWords() {
  int number_ = static_cast<int>(number);
  int hundred = GetRemainderOfDivisionBy1000(number_);
  int thousand = GetThousand(number_);
  int million = GetMillion(number_);

  std::string result = "";
  if (number < 0.0) {
    return GetWorldForElementaryNumber(-1);
  } else {
    if (number == 0.0) {
      result = "zero";
    } else if (number <= 999999999.0) {
      if (million != 0) {
        result = GetWordsForNumberFrom_1_To_999(million) + " million";
        number_ = number_ % 1000000;
        if (number_ != 0)
          result += " ";
      }
      if (thousand != 0) {
        result += GetWordsForNumberFrom_1_To_999(thousand) + " thousand";
        number_ = number_ % 1000;
        if (number_ != 0)
          result += " ";
      }
      if (hundred != 0) {
        result += GetWordsForNumberFrom_1_To_999(hundred);
      }
    } else {
      throw std::
        logic_error("Input error: number is too large for our converter.\n");
    }
  }
  return result;
}

int ConverterNumbersInWords::GetLastDigit(int number) {
  int lastDigit = number % 10;
  return lastDigit;
}

// example: 123 456 -> 50
int ConverterNumbersInWords::GetTen(int number) {
  int ten = number % 100 - GetLastDigit(number);
  return ten;
}

// example: 123 456 -> 400
int ConverterNumbersInWords::GetHundred(int number) {
  int hundred = number % 1000 - GetTen(number) - GetLastDigit(number);
  return hundred;
}

// example: 1 234 567 -> 234
int ConverterNumbersInWords::GetThousand(int number) {
  int thousand = (number / 1000) % 1000;
  return thousand;
}

// example: 123 456 789 -> 123
int ConverterNumbersInWords::GetMillion(int number) {
  int million = (number / 1000000) % 1000;
  return million;
}

// example: 123 456 789 -> 789
int ConverterNumbersInWords::GetRemainderOfDivisionBy1000(int number) {
  int remainder = number % 1000;
  return remainder;
}

std::string
ConverterNumbersInWords::GetWordsForNumberFrom_1_To_99(int number) {
  std::string result = "";
  int lastDigit = GetLastDigit(number);
  int ten = GetTen(number);

  if (number <= 20) {
    result = GetWorldForElementaryNumber(number);
  } else if (number <= 99) {
    result = GetWorldForElementaryNumber(ten);
    if (lastDigit != 0) {
      result += " " + GetWorldForElementaryNumber(lastDigit);
    }
  }
  return result;
}

std::string
ConverterNumbersInWords::GetWordsForNumberFrom_1_To_999(int number) {
  std::string result = "";
  int hundred = GetHundred(number);

  if (number <= 99) {
    result = GetWordsForNumberFrom_1_To_99(number);
  } else if (number <= 999) {
    result = GetWorldForElementaryNumber(hundred);
    if (number - hundred != 0) {
      result += " and " + GetWordsForNumberFrom_1_To_99(number - hundred);
    }
  }

  return result;
}

std::string ConverterNumbersInWords::GetWorldForElementaryNumber(int number) {
  switch (number)  {
  case 1:
    return "one";
    break;
  case 2:
    return "two";
    break;
  case 3:
    return "three";
    break;
  case 4:
    return "four";
    break;
  case 5:
    return "five";
    break;
  case 6:
    return "six";
    break;
  case 7:
    return "seven";
    break;
  case 8:
    return "eight";
    break;
  case 9:
    return "nine";
    break;
  case 10:
    return "ten";
    break;
  case 11:
    return "eleven";
    break;
  case 12:
    return "twelve";
    break;
  case 13:
    return "thirteen";
    break;
  case 14:
    return "fourteen";
    break;
  case 15:
    return "fifteen";
    break;
  case 16:
    return "sixteen";
    break;
  case 17:
    return "seventeen";
    break;
  case 18:
    return "eighteen";
    break;
  case 19:
    return "nineteen";
    break;
  case 20:
    return "twenty";
    break;
  case 30:
    return "thirty";
    break;
  case 40:
    return "forty";
    break;
  case 50:
    return "fifty";
    break;
  case 60:
    return "sixty";
    break;
  case 70:
    return "seventy";
    break;
  case 80:
    return "eighty";
    break;
  case 90:
    return "ninety";
    break;
  case 100:
    return "one hundred";
    break;
  case 200:
    return "two hundred";
    break;
  case 300:
    return "three hundred";
    break;
  case 400:
    return "four hundred";
    break;
  case 500:
    return "five hundred";
    break;
  case 600:
    return "six hundred";
    break;
  case 700:
    return "seven hundred";
    break;
  case 800:
    return "eight hundred";
    break;
  case 900:
    return "nine hundred";
    break;
  default:
    throw std::logic_error("Input error: number must be pozitive.\n");
    break;
  }
}
