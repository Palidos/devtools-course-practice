// Copyright 2018 Kozorez Alexandr

#ifndef MODULES_DIGITS_INCLUDE_DIGITS_H_
#define MODULES_DIGITS_INCLUDE_DIGITS_H_

#include <iostream>

#include <string>

class Digits {
 public:
    Digits();
    ~Digits();
    std::string getLineOfNumeral(int line, int numeral);
    std::string getLineOfNumber(int line, int* arr);
    std::string getNumber(int number);
    int* getNumberIntoArray(int n);
 private:
    std::string** digits;
    void InitDigits();
};

#endif  // MODULES_DIGITS_INCLUDE_DIGITS_H_
