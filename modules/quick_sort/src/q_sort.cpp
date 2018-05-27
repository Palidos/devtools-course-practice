// Copyright 2018 Romanov Alexander
#include "include/q_sort.h"
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <cstdint>
#include <ctime>
#include <cstdlib>

void sort::quickSort(std::vector<int> *array, int first, int last) {
    if (array->empty())
        throw std::logic_error("Array is empty");
    if ((first < 0) || (last < 0))
        throw std::logic_error("Array index can't be < 0");
    if (static_cast<int>(array->size()) < last)
        throw std::logic_error("Right bound of array > array size");
    if (last - first == 0) {
        return;
    } else {
        int i = first;
        int j = last;
        srand(time(0));
        auto random = rand;
        int randElem = random();
        int base = (*array)[(randElem % (last - first)) + first];

        do {
            while ((*array)[i] < base) i++;
            while ((*array)[j] > base) j--;

            if (i <= j) {
                if ((*array)[i] > (*array)[j])
                    std::swap((*array)[i], (*array)[j]);
                i++;
                j--;
            }
        } while (i <= j);

        if (i < last)
            quickSort(array, i, last);
        if (first < j)
            quickSort(array, first, j);
    }
}
