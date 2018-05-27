// Copyright 2018 Gracheva Elena

#include "include/operations_on_3d_vectors.h"
#include <cmath>

double OperationsOn3dVectors::GetNorm(const Vector3d& vector) {
    return sqrt(OperationsOn3dVectors::DotProduct(vector, vector));
}

double OperationsOn3dVectors::DotProduct(const Vector3d& vector1,
    const Vector3d& vector2) {
    return vector1.x * vector2.x +
        vector1.y * vector2.y +
        vector1.z * vector2.z;
}

Vector3d OperationsOn3dVectors::CrossProduct(const Vector3d& vector1,
    const Vector3d& vector2) {
    Vector3d result;
    result.x = vector1.y*vector2.z -
        vector1.z*vector2.y;
    result.y = vector1.z*vector2.x -
        vector1.x*vector2.z;
    result.z = vector1.x*vector2.y -
        vector1.y*vector2.x;
    return result;
}

Vector3d OperationsOn3dVectors::GetNormalizedVector(const Vector3d& vector) {
    if (GetNorm(vector) == 0)
        return vector;
    Vector3d result = vector;
    result.x /= GetNorm(vector);
    result.y /= GetNorm(vector);
    result.z /= GetNorm(vector);
    return result;
}
