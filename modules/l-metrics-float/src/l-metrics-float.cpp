// Copyright 2018 Gribov Pavel

#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>

#include "include/l-metrics-float.h"

std::vector<float> LMetricsFloat::VecSubstractMod(std::vector<float> vec1,
                                                    std::vector<float> vec2) {
    size_t size = std::max(vec1.size(), vec2.size());
    std::vector<float> vec3(size);

    if (vec1.size() < size)
        vec1.resize(size);
    else if (vec2.size() < size)
        vec2.resize(size);

    for (size_t i = 0; i < size; ++i)
        vec3[i] = fabs(vec1[i] - vec2[i]);

    return vec3;
}

float LMetricsFloat::LinfVecDistance(const std::vector<float>& vec1,
                                       const std::vector<float>& vec2) {
    float linf_vec_dist;
    std::vector<float> vec3;

    vec3 = VecSubstractMod(vec1, vec2);

    linf_vec_dist = *std::max_element(vec3.cbegin(), vec3.cend());

    return linf_vec_dist;
}

float LMetricsFloat::L1VecDistance(const std::vector<float>& vec1,
                                     const std::vector<float>& vec2) {
    float l1_vec_dist;
    std::vector<float> vec3;

    vec3 = VecSubstractMod(vec1, vec2);

    l1_vec_dist = std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f);

    return l1_vec_dist;
}

float LMetricsFloat::L2VecDistance(const std::vector<float>& vec1,
                                     const std::vector<float>& vec2) {
    float l2_vec_dist;
    std::vector<float> vec3;

    vec3 = VecSubstractMod(vec1, vec2);

    l2_vec_dist = sqrtf(std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f,
        [](const float& elem1, const float& elem2) {
            return elem1 + elem2 * elem2;
        }));

    return l2_vec_dist;
}

float LMetricsFloat::L3VecDistance(const std::vector<float>& vec1,
                                     const std::vector<float>& vec2) {
    float l3_vec_dist;
    std::vector<float> vec3;

    vec3 = VecSubstractMod(vec1, vec2);

    l3_vec_dist = powf(std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f,
        [](const float& elem1, const float& elem2) {
            return elem1 + powf(elem2, 3.0f);
        }), 1.0f / 3.0f);

    return l3_vec_dist;
}

float LMetricsFloat::L4VecDistance(const std::vector<float>& vec1,
                                     const std::vector<float>& vec2) {
    float l4_vec_dist;
    std::vector<float> vec3;

    vec3 = VecSubstractMod(vec1, vec2);

    l4_vec_dist = powf(std::accumulate(vec3.cbegin(), vec3.cend(), 0.0f,
        [](const float& elem1, const float& elem2) {
            return elem1 + powf(elem2, 4.0f);
            }), 1.0f / 4.0f);

    return l4_vec_dist;
}
