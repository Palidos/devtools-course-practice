// Copyright 2018 Tipanov Daniil

#ifndef MODULES_PRIME_NUMBERS_INCLUDE_PRIMENUMBERS_H_
#define MODULES_PRIME_NUMBERS_INCLUDE_PRIMENUMBERS_H_

#include <iostream>
#include <cmath>
#include <vector>

class PrimeNumbers {
 public:
     explicit PrimeNumbers(int _min = 0, int _max = 0);
     ~PrimeNumbers();
     std::vector<int> FindPrimeNums();
 private:
     int min, max, size;
     std::vector<int> arr;
};

#endif  // MODULES_PRIME_NUMBERS_INCLUDE_PRIMENUMBERS_H_
