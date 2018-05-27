// Copyright 2018 Pozdeeva Varvara

#ifndef MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
#define MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_

#include <iostream>

class BinarySearch {
 private:
     int* pMem;
     int size;
     int center;
 public:
     BinarySearch(int mas[], int size);
     ~BinarySearch();
     int Search(int num);
};

#endif  // MODULES_BINARY_SEARCH_INCLUDE_BINARY_SEARCH_H_
