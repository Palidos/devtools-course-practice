// Copyright 2018 Gribov Pavel

#ifndef MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_H_
#define MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_H_

#include <vector>

class LMetricsFloat {
 public:
    static float LinfVecDistance(const std::vector<float>& vec1,
                                   const std::vector<float>& vec2);
    static float L1VecDistance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
    static float L2VecDistance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
    static float L3VecDistance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
    static float L4VecDistance(const std::vector<float>& vec1,
                                 const std::vector<float>& vec2);
 private:
    static std::vector<float> VecSubstractMod(const std::vector<float> vec1,
                                                const std::vector<float> vec2);
};

#endif  // MODULES_L_METRICS_FLOAT_INCLUDE_L_METRICS_FLOAT_H_
