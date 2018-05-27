// Copyright 2018 Batanina Liubov
#include <vector>
#include <iterator>
#include <algorithm>
#include <queue>
#include <cstddef>
#include <stdexcept>
#include "include/radix_sort.hpp"

template<typename T>
inline T nth_byte(int number, int pos) {
    return *(reinterpret_cast<T*>(&number) + pos);
}

void radixSort(Iterator first, Iterator last) {
    if (first > last) {
      throw std::logic_error
               ("The first iterator must be less than the last iterator");
    }
    const int size = last - first;
    std::vector<int> copy_in_arr(first, last);
    const int counts_bucket = 256;
    std::queue<int> buckets[counts_bucket];
    int size_bucket;
    int val;
    int bucket_index;
    const int num_bytes = 4;
    for (int i = 0; i < num_bytes; ++i) {
        for (int j = 0; j < size; ++j) {
            val = copy_in_arr[j];
            bucket_index = (i == num_bytes - 1) ? nth_byte<char>(val, i) + 128 :
                                                nth_byte<unsigned char>(val, i);
            buckets[bucket_index].push(val);
          }
    int k = 0;
    for (auto& bucket : buckets) {
        size_bucket = bucket.size();
        for (int j = 0; j < size_bucket; ++j) {
            copy_in_arr[k++] = bucket.front();
            bucket.pop();
        }
    }
  }
    copy(copy_in_arr.begin(), copy_in_arr.end(), first);
}
