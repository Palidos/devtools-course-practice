// Copyright 2018 Generalov Aleksandr

#include "include/Sphere.h"

#include <string>

const double pi = 3.141592653589793238463;

Sphere::Sphere() : radius(0) {}

Sphere::Sphere(const double& _rad) {
    if (!negativeNumbers(_rad))
        radius = _rad;
    else
        throw std::string("Number can't be less then zero");
}

Sphere::Sphere(const Sphere & _s) : radius(_s.getRad()) {}

Sphere & Sphere::operator=(const Sphere & _s) {
    radius = _s.getRad();

    return *this;
}

double Sphere::getRad() const {
    return radius;
}

void Sphere::setRad(const double _rad) {
    radius = _rad;
}

bool Sphere::operator==(const Sphere & _s) const {
    return radius == _s.getRad();
}

bool Sphere::operator!=(const Sphere & _s) const {
    return !(*this == _s);
}

double Sphere::areaSph() const {
    return 4 * pi * radius * radius;
}

bool Sphere::negativeNumbers(const double _radius) {
    return _radius < 0;
}
