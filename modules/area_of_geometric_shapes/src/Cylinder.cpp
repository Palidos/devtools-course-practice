// Copyright 2018 Generalov Aleksandr

#include "include/Cylinder.h"

#include <string>

const double pi = 3.141592653589793238463;

Cylinder::Cylinder() : radius(0), h(0) {}

Cylinder::Cylinder(const double& _rad, const double& _h) {
    if (!negativeNumbers(_rad, _h)) {
        radius = _rad;
        h = _h;
    } else {
        throw std::string("Numbers can't be less then zero");
    }
}

Cylinder::Cylinder(const Cylinder & _c)
    : radius(_c.getRad()), h(_c.getH()) {}

Cylinder& Cylinder::operator=(const Cylinder & _c) {
    radius = _c.radius;
    h = _c.h;

    return *this;
}

double Cylinder::getRad() const {
    return radius;
}

double Cylinder::getH() const {
    return h;
}

void Cylinder::setRad(const double _rad) {
    radius = _rad;
}

void Cylinder::setH(const double _h) {
    h = _h;
}

bool Cylinder::operator==(const Cylinder & _c) const {
    return radius == _c.getRad() && h == _c.getH();
}

bool Cylinder::operator!=(const Cylinder & _c) const {
    return !(*this == _c);
}

double Cylinder::areaCyl() const {
    return 2 * pi * radius * h;
}

bool Cylinder::negativeNumbers(const double _rad, const double _h) {
    return _rad < 0 || _h < 0;
}
