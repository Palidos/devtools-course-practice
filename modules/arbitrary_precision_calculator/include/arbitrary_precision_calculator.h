// Copyright 2018 Evsyakova Ekaterina

#ifndef MODULES_ARBITRARY_PRECISION_CALCULATOR_INCLUDE_ARBITRARY_PRECISION_CALCULATOR_H_
#define MODULES_ARBITRARY_PRECISION_CALCULATOR_INCLUDE_ARBITRARY_PRECISION_CALCULATOR_H_

#include <vector>
#include <string>

class ArbitraryPrecisionCalculator {
 public:
    ArbitraryPrecisionCalculator();
    explicit ArbitraryPrecisionCalculator(const std::string s);
    ArbitraryPrecisionCalculator(const ArbitraryPrecisionCalculator& z);

    ArbitraryPrecisionCalculator& operator=
        (const ArbitraryPrecisionCalculator& z);

    const ArbitraryPrecisionCalculator operator +
        (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator -
        (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator *
        (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator /
        (const ArbitraryPrecisionCalculator& z) const;
    const ArbitraryPrecisionCalculator operator /
        (const int & z) const;

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

#endif  // MODULES_ARBITRARY_PRECISION_CALCULATOR_INCLUDE_ARBITRARY_PRECISION_CALCULATOR_H_
