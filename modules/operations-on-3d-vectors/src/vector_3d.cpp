// Copyright 2018 Gracheva Elena

#include "include/vector_3d.h"
#include <stdexcept>

Vector3d::Vector3d() {
    x = y = z = 0;
}

Vector3d::Vector3d(double component0, double component1, double component2) {
    x = component0;
    y = component1;
    z = component2;
}

bool operator==(const Vector3d & vector1, const Vector3d & vector2) {
    return (vector1.x == vector2.x) &&
        (vector1.y == vector2.y) &&
        (vector1.z == vector2.z);
}

bool operator!=(const Vector3d & vector1, const Vector3d & vector2) {
    return (vector1.x != vector2.x) ||
        (vector1.y != vector2.y) ||
        (vector1.z != vector2.z);
}

