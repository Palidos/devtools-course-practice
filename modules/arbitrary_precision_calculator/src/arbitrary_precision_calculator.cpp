// Copyright 2018 Evsyakova Ekaterina

#include "include/arbitrary_precision_calculator.h"

#include <cstdbool>

#include <string>
#include <vector>
#include <sstream>

ArbitraryPrecisionCalculator::ArbitraryPrecisionCalculator() : number({ 0 }) {}

ArbitraryPrecisionCalculator::ArbitraryPrecisionCalculator
(const std::string s) {
    int i = s.size() - 1;

    while (i > 1) {
        number.push_back(static_cast<int>(s[i]) - 48);
        i--;
    }

    if (s[0] == '-') {
        number.push_back(-1 * (static_cast<int>(s[1]) - 48));
    } else {
        if (s[1] != '\0')
            number.push_back(static_cast<int>(s[1]) - 48);
        number.push_back(static_cast<int>(s[0]) - 48);
    }
}

ArbitraryPrecisionCalculator::ArbitraryPrecisionCalculator
(const ArbitraryPrecisionCalculator& z) : number(z.number) {}

ArbitraryPrecisionCalculator& ArbitraryPrecisionCalculator::
operator=(const ArbitraryPrecisionCalculator& z) {
    number = z.number;
    return *this;
}

const ArbitraryPrecisionCalculator ArbitraryPrecisionCalculator::
operator+(const ArbitraryPrecisionCalculator& z) const {
    ArbitraryPrecisionCalculator x = (*this);
    ArbitraryPrecisionCalculator y = (*&z);

    if (number[number.size() - 1] < 0) {
        if (z.number[z.number.size() - 1] < 0) {
            x.number[x.number.size() - 1] *= -1;
            y.number[y.number.size() - 1] *= -1;
            x = x + y;
            x.number[x.number.size() - 1] *= -1;
            return x;                                         // (-x)+(-y)
        }
        x.number[x.number.size() - 1] *= -1;
        return y - x;                                       // (-x)+y
    }
    if (y.number[y.number.size() - 1] < 0) {
        y.number[y.number.size() - 1] *= -1;
        return x - y;                                       // x+(-y)
    }

    int size;
    if ((*this).number.size() > z.number.size()) {
        size = (*this).number.size();
    } else {
        size = z.number.size();
    }

    std::string str_for_res;
    int k = 0;

    for (int i = 0; i <= size + 1; ++i)
        str_for_res += '0';

    ArbitraryPrecisionCalculator *result = new ArbitraryPrecisionCalculator
    (str_for_res);

    if (x.number.size() < y.number.size())
        while (x.number.size() != y.number.size())
            x.number.push_back(0);
    if (x.number.size() > y.number.size())
        while (y.number.size() != x.number.size())
            y.number.push_back(0);

    for (int i = 0; i < size; i++) {
        int t = x.number[i] + y.number[i] + k;
        (*result).number[i] = t % 10;
        k = t / 10;
    }

    (*result).number[size] += k;
    int i = size + 1;
    while ((*result).number[i] == 0 && i != 0) {
        (*result).number.pop_back();
        i--;
    }

    return (*result);
}

const ArbitraryPrecisionCalculator ArbitraryPrecisionCalculator::
operator-(const ArbitraryPrecisionCalculator& z) const {
    ArbitraryPrecisionCalculator x = (*this);
    ArbitraryPrecisionCalculator y = z;

    if (y.number[y.number.size() - 1] < 0) {
        if (x.number[x.number.size() - 1] > 0) {
            y.number[y.number.size() - 1] *= -1;
            return x + y;                                     // x-(-y)
        }
        y.number[y.number.size() - 1] *= -1;
        x.number[x.number.size() - 1] *= -1;
        return y - x;                                       // (-x)-(-y)
    }
    if (x.number[x.number.size() - 1] < 0) {
        x.number[x.number.size() - 1] *= -1;
        x = x + y;
        x.number[x.number.size() - 1] *= -1;
        return x;                                           // (-x)-y
    }

    bool isPositive = true;
    if (z > (*this)) {
        y = (*this);
        x = z;
        isPositive = false;
    }

    int size;
    if ((*this).number.size() > z.number.size()) {
        size = (*this).number.size();
    } else {
        size = z.number.size();
    }

    std::string str_for_res;

    for (int i = 0; i <= size + 1; ++i)
        str_for_res += '0';

    ArbitraryPrecisionCalculator *result = new ArbitraryPrecisionCalculator
    (str_for_res);

    if (x.number.size() > y.number.size())
        while (y.number.size() != x.number.size()) y.number.push_back(0);

    for (unsigned int i = 0; i < y.number.size(); i++) {
        if (x.number[i] < y.number[i]) {
            x.number[i + 1]--;
            x.number[i] += 10;
        }
        (*result).number[i] = x.number[i] - y.number[i];
    }

    int i = size + 1;
    while ((*result).number[i] == 0 && i != 0) {
        (*result).number.pop_back();
        i--;
    }

    int res_size = (*result).number.size();

    if (isPositive == false)
        (*result).number[res_size - 1] *= -1;

    return (*result);
}

const ArbitraryPrecisionCalculator ArbitraryPrecisionCalculator::
operator*(const ArbitraryPrecisionCalculator& z) const {
    ArbitraryPrecisionCalculator x = *this;
    ArbitraryPrecisionCalculator y = z;

    int size_1 = z.number.size();
    int size_2 = (*this).number.size();
    std::string str_for_res;

    if (number[number.size() - 1] < 0) {
        if (z.number[z.number.size() - 1] < 0) {
            x.number[x.number.size() - 1] *= -1;
            y.number[y.number.size() - 1] *= -1;
            return x * y;
        }
        x.number[x.number.size() - 1] *= -1;
        x = x * y;
        x.number[x.number.size() - 1] *= -1;
        return x;
    }
    if (y.number[y.number.size() - 1] < 0) {
        y.number[y.number.size() - 1] *= -1;
        x = x * y;
        x.number[x.number.size() - 1] *= -1;
        return x;
    }

    for (int i = 0; i <= size_2 + size_1 + 1; ++i)
        str_for_res += '0';

    ArbitraryPrecisionCalculator *result = new ArbitraryPrecisionCalculator
    (str_for_res);

    int i = 0;
    for (int k = 0, j = 0; j < size_1; j++) {
        k = 0;
        if (z.number[j] == 0) {
            (*result).number[j + size_2] = 0;
            continue;
        }
        for (i = 0; i < size_2; i++) {
            int tmp = (*this).number[i] * z.number[j] +
                (*result).number[i + j] + k;
            (*result).number[i + j] = tmp % 10;
            k = tmp / 10;
        }
        (*result).number[j + size_2] = k;
    }

    i = size_2 + size_1 + 1;
    while ((*result).number[i] == 0 && i != 0) {
        (*result).number.pop_back();
        i--;
    }

    return (*result);
}

bool ArbitraryPrecisionCalculator::operator>
(const ArbitraryPrecisionCalculator & z) const {
    int size_1 = (*this).number.size();
    int size_2 = z.number.size();

    if ((*this).number[size_1 - 1] < 0 && (z.number[size_2 - 1] >= 0))
        return false;
    if ((*this).number[size_1 - 1] >= 0 && (z.number[size_2 - 1] < 0))
        return true;
    if (size_1 > size_2)
        return true;
    if (size_1 < size_2)
        return false;

    bool isLarger = false;

    while (size_1 - 1 >= 0 && !isLarger) {
        if ((*this).number[size_1 - 1] > z.number[size_1 - 1])
            isLarger = true;
        if ((*this).number[size_1 - 1] < z.number[size_1 - 1])
            size_1 = 0;
        size_1--;
    }

    return isLarger;
}

const ArbitraryPrecisionCalculator ArbitraryPrecisionCalculator::
operator/(const ArbitraryPrecisionCalculator& z) const {
    if (z == ArbitraryPrecisionCalculator("0"))
        throw std::string("Can't divide by zero");

    ArbitraryPrecisionCalculator x = (*this);
    ArbitraryPrecisionCalculator y = (*&z);

    if (x.number[x.number.size() - 1] < 0) {
        if (y.number[y.number.size() - 1] < 0) {
            x.number[x.number.size() - 1] *= -1;
            y.number[y.number.size() - 1] *= -1;
            return x / y;
        }
        x.number[x.number.size() - 1] *= -1;
        x = x / y;
        x.number[x.number.size() - 1] *= -1;
        return x;
    }
    if (y.number[y.number.size() - 1] < 0) {
        y.number[y.number.size() - 1] *= -1;
        x = x / y;
        x.number[x.number.size() - 1] *= -1;
        return x;
    }

    ArbitraryPrecisionCalculator result("0"), p("1");
    int k = 0;

    while (!(y > x)) {
        y = y + y;
        p = p + p;
        ++k;
    }
    while (k) {
        y = y / 2;
        p = p / 2;
        --k;
        while (!(y > x)) {
            x = x - y;
            result = result + p;
        }
    }

    return result;
}

const ArbitraryPrecisionCalculator ArbitraryPrecisionCalculator::
operator/(const int & z) const {
    if (z == 0)
        throw std::string("Can't divide by zero");

    int size = (*this).number.size();
    std::string str_for_res;
    int k = 0;

    for (int i = 0; i <= size; ++i)
        str_for_res += '0';

    ArbitraryPrecisionCalculator *result =
        new ArbitraryPrecisionCalculator(str_for_res);

    for (int i = size - 1; i >= 0; i--) {
        int cur = 10 * k + (*this).number[i];
        (*result).number[i] = cur / z;
        k = cur % z;
    }

    int i = size;
    while ((*result).number[i] == 0 && i != 0) {
        (*result).number.pop_back();
        i--;
    }

    return (*result);
}

std::vector<int> ArbitraryPrecisionCalculator::getNumber() {
    std::vector<int> result = reverseVector(number);
    return result;
}

std::string ArbitraryPrecisionCalculator::getResultInString() {
    std::string result;
    std::vector<int> tmp = reverseVector(number);

    if (tmp[0] < 0) {
        result += "-";
        tmp[0] = -tmp[0];
    }
    for (unsigned int i = 0; i < tmp.size(); i++) {
        std::ostringstream s;
        s << tmp[i];
        result += s.str();
    }

    return result;
}

void ArbitraryPrecisionCalculator::setNumber(const std::vector<int> z) {
    std::vector<int> number_ = reverseVector(z);
    number = number_;
}

bool ArbitraryPrecisionCalculator::operator ==
(const ArbitraryPrecisionCalculator& z) const {
    return (*this).number == z.number;
}

bool ArbitraryPrecisionCalculator::operator !=
(const ArbitraryPrecisionCalculator& z) const {
    return !((*this).number == z.number);
}

std::vector<int> ArbitraryPrecisionCalculator::
reverseVector(std::vector<int> z) {
    std::vector<int> result = z;
    int size = z.size();
    for (int i = 0; i != size; i++) {
        result[size - 1 - i] = z[i];
    }
    return result;
}
