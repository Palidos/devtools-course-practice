// Copyright 2018 Kuznetsov Konstantin

#include "include/probability_distribution.h"

#include <cmath>
#include <stdexcept>
#include <string>
#include <vector>

DescretePD::DescretePD() {}

void DescretePD::setData(const std::vector<double> &values,
  const std::vector<double> &probabilities) {
    if (values.size() != probabilities.size()) {
        throw std::logic_error("Sizes of vectors do not match");
    } else {
        if (verifyProbabilities(probabilities)) {
            values_ = values;
            probabilities_ = probabilities;
        } else {
            throw std::logic_error("Invalid probabilities values");
        }
    }
  }

double DescretePD::expectedValue() const {
    if (values_.empty()) {
        throw std::logic_error("No data");
    }

    double expectedValue = 0.0;

    for (int i = 0; i < static_cast<int>(values_.size()); i++) {
        expectedValue += values_[i] * probabilities_[i];
    }

    return expectedValue;
}

double DescretePD::variance() const {
    if (values_.empty()) {
        throw std::logic_error("No data");
    }

    double variance = 0.0;
    double ev = expectedValue();

    for (int i = 0; i < static_cast<int>(values_.size()); i++) {
        variance += probabilities_[i] * pow((values_[i] - ev), 2);
    }

    return variance;
}

double DescretePD::rawMoment(const unsigned char k) const {
    if (values_.empty()) {
        throw std::logic_error("No data");
    }

    double rawMoment = 0.0;

    switch (k) {
    case 0: {
        rawMoment = 1.0;
        break;
    }
    case 1: {
        rawMoment = expectedValue();
        break;
    }
    default: {
        for (int i = 0; i < static_cast<int>(values_.size()); i++) {
            rawMoment += pow(values_[i], k) * probabilities_[i];
        }
    }
    }

    return rawMoment;
}

double DescretePD::centralMoment(const unsigned char k) const {
    if (values_.empty()) {
        throw std::logic_error("No data");
    }

    double centralMoment = 0.0;
    double ev = expectedValue();

    switch (k) {
    case 0: {
        centralMoment = 1.0;
        break;
    }
    case 1: {
        centralMoment = 0.0;
        break;
    }
    case 2: {
        centralMoment = variance();
        break;
    }
    default: {
        for (int i = 0; i < static_cast<int>(values_.size()); i++) {
            centralMoment += probabilities_[i] * pow((values_[i] - ev), k);
        }
    }
    }

    return centralMoment;
}

std::vector<double> DescretePD::getValues() const {
    if (values_.empty()) {
        throw std::logic_error("No data");
    }

    return values_;
}

std::vector<double> DescretePD::getProbabilities() const {
    if (values_.empty()) {
        throw std::logic_error("No data");
    }

    return probabilities_;
}

bool DescretePD::verifyProbabilities(const std::vector<double> &probabilities)
                                                                      const {
    double eps = 1.0e-6;
    double sum = 0.0;
    bool sign = true;

    // probabilities should be non-negative
    // sum of probabilities equals 1
    for (int i = 0; i < static_cast<int>(probabilities.size()); i++) {
        if (probabilities[i] < 0) {
            sign = false;
            break;
        }
        sum += probabilities[i];
    }

    return (sum > 1.0 - eps) && (sum < 1.0 + eps) && sign;
}

bool DescretePD::hasData() const {
    return !values_.empty();
}
