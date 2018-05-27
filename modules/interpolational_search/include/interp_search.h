// Copyright 2018 Konakov Alexandr
#ifndef MODULES_INTERPOLATIONAL_SEARCH_INCLUDE_INTERP_SEARCH_H_
#define MODULES_INTERPOLATIONAL_SEARCH_INCLUDE_INTERP_SEARCH_H_

#include <cstdint>
#include <stdexcept>
#include <vector>

struct xab {
  static int interpSearch(const std::vector<int> &v, const int val);
};
#endif  // MODULES_INTERPOLATIONAL_SEARCH_INCLUDE_INTERP_SEARCH_H_
