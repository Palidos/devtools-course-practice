// Copyright 2018 Gracheva Elena

#ifndef MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTOR_3D_H_
#define MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTOR_3D_H_

struct Vector3d {
    double x;
    double y;
    double z;

    Vector3d();
    Vector3d(double component0, double component1, double component2);

    friend bool operator==(const Vector3d& vector1, const Vector3d& vector2);
    friend bool operator!=(const Vector3d& vector1, const Vector3d& vector2);
};

#endif  // MODULES_OPERATIONS_ON_3D_VECTORS_INCLUDE_VECTOR_3D_H_
