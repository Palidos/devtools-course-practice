// Copyright 2018 Evsyakova Ekaterina

#ifndef MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIG_NUMBER_H_
#define MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIG_NUMBER_H_

#include <vector>
#include <string>

class ArbitraryPrecisionCalculator {
public:
    ArbitraryPrecisionCalculator();
    explicit ArbitraryPrecisionCalculator(const std::string s);
    ArbitraryPrecisionCalculator(const ArbitraryPrecisionCalculator& z);

    ArbitraryPrecisionCalculator& operator=(const ArbitraryPrecisionCalculator& z);

    const ArbitraryPrecisionCalculator operator + (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator - (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator * (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator / (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator / (const int & z) const;

    bool operator>(const ArbitraryPrecisionCalculator & z) const;

    bool operator == (const ArbitraryPrecisionCalculator& z) const;
    bool operator != (const ArbitraryPrecisionCalculator& z) const;

    std::vector<int> getNumber();
    std::string getResultInString();
    void setNumber(const std::vector<int> number_);
    std::vector<int> reverseVector(std::vector<int> z);

private:
    std::vector<int> number;
};

#endif  // MODULES_BIGNUM_ARITHMETIC_INCLUDE_BIG_NUMBER_H_
