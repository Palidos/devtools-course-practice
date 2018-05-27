// Copyright 2018 Bolshakov Konstantin

#ifndef MODULES_BOOKS_INCLUDE_BOOKS_H_
#define MODULES_BOOKS_INCLUDE_BOOKS_H_

#include <iostream>

class Books {
 public:
  Books(int n, int* arr);
  ~Books();
  double CalculatePayForCurrentCollection(int*arr, int collection);
  int CurentCollectionSize(int*arr);
  double CalculateAllPayment(int*arr);
 private:
  int* arr;
  int n;
};

#endif  // MODULES_BOOKS_INCLUDE_BOOKS_H_
