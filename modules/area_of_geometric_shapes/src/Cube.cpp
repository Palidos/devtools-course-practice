// Copyright 2018 Generalov Aleksandr

#include "include/Cube.h"

#include <string>

Cube::Cube() : h(0) {}

Cube::Cube(const double& _h) {
    if (!negativeNumbers(_h))
        h = _h;
    else
        throw std::string("Number can't be less then zero");
}

Cube::Cube(const Cube & _c) : h(_c.getH()) {}

Cube & Cube::operator=(const Cube & _c) {
    h = _c.getH();

    return *this;
}

double Cube::getH() const {
    return h;
}

void Cube::setH(const double _h) {
    h = _h;
}

bool Cube::operator==(const Cube & _c) const {
    return h == _c.getH();
}

bool Cube::operator!=(const Cube & _c) const {
    return !(*this == _c);
}

double Cube::areaCube() const {
    return 6 * h * h;
}

bool Cube::negativeNumbers(const double _h) {
    return _h < 0;
}
