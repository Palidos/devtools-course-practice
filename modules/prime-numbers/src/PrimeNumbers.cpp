// Copyright 2018 Tipanov Daniil

#include <vector>
#include "include/PrimeNumbers.h"

PrimeNumbers::PrimeNumbers(int _min, int _max) {
    min = _min;
    max = _max;
    if (min < 0)
        throw "Error! Negative numbers can't be prime!";
    if (min > max)
        throw "Error! Max can't be less than min!";
    size = max - min + 1;
    int tmp = min;
    for (int i = 0; i < size; i++) {
        arr.push_back(tmp);
        tmp++;
    }
}

PrimeNumbers::~PrimeNumbers() {
    min = max = size = 0;
    arr.clear();
}

std::vector<int> PrimeNumbers::FindPrimeNums() {
    for (int i = 0; i < size; i++) {
        for (int j = 2; j <= sqrt(static_cast<double>(arr[i])); j++)
            if (arr[i] % j == 0 && arr[i] != j && arr[i] != 1) {
                arr.erase(arr.begin() + i);
                size--;
                break;
            }
    }
    return arr;
}
