//
//  fractional_number.cpp
//  fractional_number
//
//  Created by Aleksei Khomenko.
//  Copyright © 2018 Aleksei Khomenko. All rights reserved.
//

#include "include/fractional_number.h"

#include <stdbool.h>
#include <string>
#include <iostream>

FractionalNumber::FractionalNumber(): a(0), b(1) {}
FractionalNumber::FractionalNumber(const int Numerator, const int Denominator) {
    a = Numerator;
    b = Denominator;
    if (b == 0) {
        throw std::string("Division by zero");
    }
}
FractionalNumber::FractionalNumber(const FractionalNumber& r):
                   a(r.getNumerator()), b(r.getDenominator()) {}

    FractionalNumber& FractionalNumber::operator=(const FractionalNumber& s) {
    a = s.getNumerator();
    b = s.getDenominator();
    return *this;
}

FractionalNumber FractionalNumber::operator+(const FractionalNumber&s) const {
    int c;
    FractionalNumber Sum;
    Sum.a = a * s.b + b * s.a;
    Sum.b = b * s.b;
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

FractionalNumber FractionalNumber::operator- (const FractionalNumber&s) const {
    int c;
    FractionalNumber Sum;
    Sum.a = a * s.b - b * s.a;
    Sum.b = b * s.b;
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

FractionalNumber FractionalNumber::operator* (const FractionalNumber&s) const {
    int c;
    FractionalNumber Sum;
    Sum.a = a * s.a;
    Sum.b = b * s.b;
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

FractionalNumber FractionalNumber::operator/ (const FractionalNumber&s) const {
    int c;
    FractionalNumber Sum;
    Sum.a = a * s.b;
    Sum.b = b * s.a;
    if  (s.a == 0) {
    throw std::string("Can't divide by zero");
    }
    c = Nod(Sum.b, Sum.a);
    Sum.a = (Sum.a)/c;
    Sum.b = (Sum.b)/c;
    return Sum;
}

int FractionalNumber::Nod(int c, int d) const {
    if (d == 0) {
    return c;
    } else {
    return Nod (d, c % d);
    }
}

int FractionalNumber::getNumerator() const {
    return a;
}

int FractionalNumber::getDenominator() const {
    return b;
}

void FractionalNumber::setNumerator(const int Numerator) {
    a = Numerator;
}

void FractionalNumber::setDenominator(const int Denominator) {
    b = Denominator;
}

bool FractionalNumber::operator == (const FractionalNumber& r) const {
    FractionalNumber tmp  = (*this - r);
    if ((tmp.a == 0) && (tmp.b == 1)) {
        return true;
    } else {
        return false;
    }
}

bool FractionalNumber::operator != (const FractionalNumber& r) const {
    return !(*this == r);
}
