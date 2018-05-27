// Copyright 2018 Pozdeeva Varvara

#include "include/binary_search.h"
#include <algorithm>
#include <string>

BinarySearch::BinarySearch(int mas[], int size) {
         if (mas != nullptr) {
             if (size > 0) {
                 pMem = new int[size];
                 for (int i = 0; i < size; i++)
                     pMem[i] = mas[i];
                 center = size / 2;
                 this->size = size;
             } else {
                  throw std::string("Error size!");
             }
         } else {
             throw std::string("Error mas!");
         }
}
BinarySearch::~BinarySearch() {
         if (pMem!= nullptr)
          delete[] pMem;
}
int BinarySearch::Search(int num) {
     std::sort(pMem, pMem + size);
     int result = -1;
     int right = size;
     int left = 0;

     while ((left <= right)) {
          center = (left + right) / 2;
     if (pMem[center] == num) {
          result = center;
          break;
     }
     if (pMem[center] > num)
           right = center - 1;
     else
           left = center + 1;
     }
     return result;
}
