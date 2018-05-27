// Copyright 2018 Konakov Alexandr
#include "include/interp_search.h"
#include <stdexcept>
#include <vector>
int xab::interpSearch(const std::vector<int> &v, const int val) {
  if (v.empty()) throw std::logic_error("Cant find element in empty array");

  auto map_value = [](double val, double old_lb, double old_rb, double new_lb,
                      double new_rb) -> int {
    return (new_lb + (val - old_lb) * (new_rb - new_lb) / (old_rb - old_lb));
  };
  int lbound = 0;
  int rbound = v.size() - 1;
  //= -1;
  while (lbound < rbound) {
    int pos = map_value(val, v[lbound], v[rbound], lbound, rbound);
    if (pos < lbound || (pos >= static_cast<int>(v.size())))
      return -1;
    if (v[pos] == val) return pos;
    if (v[pos] < val)
      lbound = pos + 1;
    else
      rbound = pos - 1;
  }
  if (val == v[lbound])
    return lbound;
  else
    return -1;
}
