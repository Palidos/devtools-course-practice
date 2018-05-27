// Copyright 2018 Generalov Aleksandr

#include "include/Cone.h"

#include <string>

const double pi = 3.141592653589793238463;

Cone::Cone() : radius(0), l(0) {}

Cone::Cone(const double& _rad, const double& _l) {
    if (!negativeNumbers(_rad, _l)) {
        radius = _rad;
        l = _l;
    } else {
        throw std::string("Numbers can't be less then zero");
    }
}

Cone::Cone(const Cone & _c)
           : radius(_c.getRad()), l(_c.getL()) {}

Cone & Cone::operator=(const Cone & _c) {
    radius = _c.radius;
    l = _c.l;

    return *this;
}

double Cone::getRad() const {
    return radius;
}

double Cone::getL() const {
    return l;
}

void Cone::setRad(const double _rad) {
    radius = _rad;
}

void Cone::setL(const double _l) {
    l = _l;
}

bool Cone::operator==(const Cone & _c) const {
    return radius == _c.getRad() && l == _c.getL();
}

bool Cone::operator!=(const Cone & _c) const {
    return !(*this == _c);
}

double Cone::areaCone() const {
    return pi * radius * (radius + l);
}

bool Cone::negativeNumbers(const double _rad, const double _l) {
    return _rad < 0 || _l < 0;
}
