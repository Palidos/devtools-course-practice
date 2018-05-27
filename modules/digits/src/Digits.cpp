// Copyright 2018 Kozorez Alexandr

#include "include/Digits.h"

#include <string>

void Digits::InitDigits() {
    this->digits = new std::string*[3];
    for (int i = 0; i < 3; i++)
        this->digits[i] = new std::string[10];

    std::string digits[3][10] = {
    { "._.", "...", "._.", "._.", "...", "._.", "._.", "._.", "._.", "._." },
    { "|.|", "..|", "._|", "._|", "|_|", "|_.", "|_.", "..|", "|_|", "|_|" },
    { "|_|", "..|", "|_.", "._|", "..|", "._|", "|_|", "..|", "|_|", "..|" }
    };

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 10; j++)
            this->digits[i][j] = digits[i][j];
}

Digits::Digits() {
    InitDigits();
}

Digits::~Digits() {
    for (int i = 0; i < 3; i++)
        delete[] digits[i];
    delete digits;
}
std::string Digits::getLineOfNumeral(int line, int numeral) {
    return this->digits[line][numeral];
}

std::string Digits::getLineOfNumber(int line, int* arr) {
    int size = arr[0];
    std::string LineOfNumber = "";

    for (int i = size; i >= 1; i--)
        LineOfNumber += (getLineOfNumeral(line, arr[i]) + " ");
    return LineOfNumber;
}

std::string Digits::getNumber(int number) {
    int* numberIntoArray = getNumberIntoArray(number);
    return getLineOfNumber(0, numberIntoArray) + "\n" +
    getLineOfNumber(1, numberIntoArray) +
    "\n" + getLineOfNumber(2, numberIntoArray);
}

int * Digits::getNumberIntoArray(int n) {
    int* numerals = new int[100];
    int temp = n, i = 0;

    for (i = 0; i < 100; i++)
        numerals[0] = 0;

    for (i = 1; temp > 0; temp /= 10, i++)
        numerals[i] = temp % 10;

    // Size
    numerals[0] = i - 1;

    return numerals;
}
