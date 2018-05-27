// Copyright 2018 Kuznetsov Konstantin

#ifndef MODULES_PROBABILITY_DISTRIBUTION_INCLUDE_PROBABILITY_DISTRIBUTION_H_
#define MODULES_PROBABILITY_DISTRIBUTION_INCLUDE_PROBABILITY_DISTRIBUTION_H_

#include <vector>

class DescretePD {
 public:
    DescretePD();

    std::vector<double> getValues() const;
    std::vector<double> getProbabilities() const;
    void setData(const std::vector<double> &values,
      const std::vector<double> &probabilities);

    double expectedValue() const;
    double variance() const;
    double rawMoment(const unsigned char k) const;
    double centralMoment(const unsigned char k) const;

    // returns true if there is at least one value
    bool hasData() const;
 private:
    // verifies that probabilities are non-negative
    // and their sum equals 1
    bool verifyProbabilities(const std::vector<double> &probabilities) const;

    // probability of value[i] is probability[i]
    std::vector<double> values_;
    std::vector<double> probabilities_;
};

#endif  // MODULES_PROBABILITY_DISTRIBUTION_INCLUDE_PROBABILITY_DISTRIBUTION_H_
