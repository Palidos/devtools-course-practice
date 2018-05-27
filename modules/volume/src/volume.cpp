// Copyright 2018 Shurygin Dmitriy

#include "include/volume.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <string>

Sphere::Sphere() : Radius(0) {}

Sphere::Sphere(const double _R) {
    if (!negativeNumbers(_R))
        Radius = _R;
    else
        throw std::string("Number can't be less then zero");
}

Sphere::Sphere(const Sphere& sphere) : Radius(sphere.getRadius()) {}

double Sphere::getRadius() const {
    return Radius;
}

void Sphere::setRadius(const double _R) {
    Radius = _R;
}

double Sphere::Volume() {
    return M_PI * Radius * Radius * Radius;
}

bool Sphere::negativeNumbers(const double _rad) {
    return _rad < 0;
}

Cube::Cube() : SideLength(0) {}

Cube::Cube(const double _L) {
    if (!negativeNumbers(_L))
        SideLength = _L;
    else
        throw std::string("Number can't be less then zero");
}

Cube::Cube(const Cube& Cube) : SideLength(Cube.getL()) {}

double Cube::getL() const {
    return SideLength;
}

void Cube::setL(const double _A) {
    SideLength = _A;
}


double Cube::Volume() {
    return SideLength * SideLength * SideLength;
}

bool Cube::negativeNumbers(const double _L) {
    return _L < 0;
}

Cylinder::Cylinder() : Radius(0), Height(0) {}

Cylinder::Cylinder(const double _R, const double _h) {
    if (!negativeNumbers(_R, _h)) {
        Radius = _R;
        Height = _h;
    } else {
        throw std::string("Number can't be less then zero");
    }
}

Cylinder::Cylinder(const Cylinder& cylinder)
         : Radius(cylinder.getRadius()), Height(cylinder.getHeight()) {}

double Cylinder::getRadius() const {
    return Radius;
}

void Cylinder::setRadius(const double _R) {
    Radius = _R;
}

void Cylinder::setHeight(const double _h) {
    Height = _h;
}


double Cylinder::getHeight() const {
    return Height;
}

double Cylinder::Volume() {
    return M_PI * Radius * Radius * Height;
}

bool Cylinder::negativeNumbers(const double _rad, const double _h) {
    return _rad < 0 || _h < 0;
}
