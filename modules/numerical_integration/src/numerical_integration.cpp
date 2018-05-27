// Copyright 2018 Lvova Alina

#include "include/numerical_integration.h"
#include <math.h>
#include <stdexcept>

double Integral::function(double x) {
    return (x * x + x + 2);
}

void Integral::limitAdjustment(double _low, double _up) {
    nullResult = false;
    if (_low < _up) {
        low = _low;
        up = _up;
        negative = false;
    } else {
        if (_low > _up) {
            up = _low;
            low = _up;
            negative = true;
        } else {
            nullResult = true;
        }
    }
}

Integral::Integral() {
    low = 0;
    up = 0;
    divisions = 0;
    res = 0;
    step = 0;
    negative = false;
    nullResult = false;
}

Integral::Integral(double lower_limit, double upper_limit, int _divisions) {
    limitAdjustment(lower_limit, upper_limit);
    setDivisions(_divisions);
    res = 0;
    step = (up - low) / divisions;
}

double Integral::RiemannSumLeft() {
    if (nullResult)
        return 0;
    res = 0;
    double A = low - step;
    for (int i = 0; i < divisions; i++) {
        A += step;
        res += step * function(A);
    }
    return negative ? -res : res;
}

double Integral::TrapezoidalRule() {
    if (nullResult)
        return 0;
    res = 0;
    double A = low - step;
    for (int i = 0; i < divisions; i++) {
        A += step;
        res += step / 2 * (function(A) + function(A + step));
    }
    return negative ? -res : res;
}

double Integral::SimpsonRule() {
    if (nullResult)
        return 0;
    res = 0;
    double A = low - step;
    for (int i = 0; i < divisions; i++) {
        A += step;
        res += step / 6 *
            (function(A) + 4 * function((2 * A + step) / 2)
             + function(A + step));
    }
    return negative ? -res : res;
}

double Integral::Simpson3_8Rule() {
    if (nullResult)
        return 0;
    res = 0;
    double A = low - step;
    for (int i = 0; i < divisions; i++) {
        A += step;
        double B = A + step;
        res += (B - A) / 8 *
            (function(A) + 3 * function((2 * A + B) / 3)
             + 3 * function((A + 2 * B) / 3) + function(B));
    }
    return negative ? -res : res;
}

double Integral::BooleRule() {
    if (nullResult)
        return 0;
    res = 0;
    double A = low - step;
    for (int i = 0; i < divisions; i++) {
        A += step;
        double B = A + step;
        res += (B - A) / 90 * (7 * function(A) + 32 * function((3 * A + B) / 4)
             + 12 * function((A + B) / 2) +
             32 * function((A + 3 * B) / 4) + 7 * function(B));
    }
    return negative ? -res : res;
}

double Integral::NewtonCotes5() {
    if (nullResult)
        return 0;
    res = 0;
    double A = low - step;
    for (int i = 0; i < divisions; i++) {
        A += step;
        double B = A + step;
        res += (B - A) / 288 * (19 * function(A)
               + 75 * function((4 * A + B) / 5)
               + 50 * function((3 * A + 2 * B) / 5)
               + 50 * function((2 * A + 3 * B) / 5)
               + 75 * function((A + 4 * B) / 5) + 19 * function(B));
    }
    return negative ? -res : res;
}

double Integral::GaussianQuadrature() {
    if (nullResult)
        return 0;
    res = 0;
    double A = low - step;
    for (int i = 0; i < divisions; i++) {
        A += step;
        double B = A + step;
        double f1 = (A + B) / 2;
        double f2 = (B - A) / (2 * sqrt(3));
        res += (B - A) / 2 * (function(f1 - f2) + function(f1 + f2));
    }
    return negative ? -res : res;
}

void Integral::setLower(double _low) {
    if (_low != low)
        limitAdjustment(_low, up);
    else
        throw std::out_of_range("the lower limits are the same");
    step = (up - low) / divisions;
    res = 0;
}

void Integral::setUpper(double _up) {
    if (_up != up)
        limitAdjustment(low, _up);
    else
        throw std::out_of_range("the upper limits are the same");
    step = (up - low) / divisions;
    res = 0;
}

void Integral::setDivisions(int _div) {
    if (_div > 1)
        divisions = _div;
    else
        throw std::out_of_range("divisions must be greater than 1");
    step = (up - low) / divisions;
    res = 0;
}
