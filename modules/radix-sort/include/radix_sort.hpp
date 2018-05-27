// Copyright 2018 Batanina Liubov

#ifndef MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_HPP_
#define MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_HPP_


#include <vector>
#include <functional>


using Iterator = std::vector<int>::iterator;

void radixSort(Iterator first, Iterator last);

class RadixSorter {
 public:
  RadixSorter() = default;
  explicit RadixSorter(std::vector<int> data) : m_data(std::move(data)) {}
  RadixSorter(Iterator first, Iterator last) : m_data(first, last) {}
  RadixSorter(const RadixSorter& other) : RadixSorter(other.m_data) {}
  RadixSorter(RadixSorter&& other) : m_data(std::move(other.m_data)) {} // NOLINT

  RadixSorter& operator=(const RadixSorter& other) {
    m_data = other.m_data;
    return *this;
  }

  RadixSorter& operator=(const RadixSorter&& other) { // NOLINT
    m_data = std::move(other.m_data);
    return *this;
  }

  std::vector<int> sort() const {
    std::vector<int> s_data(m_data);
    radixSort(s_data.begin(), s_data.end());
    return s_data;
  }

  std::vector<int> get_data() const { return m_data; }

 private:
  std::vector<int> m_data;
};


#endif  // MODULES_RADIX_SORT_INCLUDE_RADIX_SORT_HPP_
