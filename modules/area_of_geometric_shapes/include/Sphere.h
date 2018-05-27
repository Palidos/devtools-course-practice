// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_SPHERE_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_SPHERE_H_

class Sphere {
 public:
    Sphere();
    explicit Sphere(const double& _rad);
    Sphere(const Sphere& _s);

    Sphere& operator=(const Sphere& _s);

    double getRad() const;
    void setRad(const double _rad);

    bool operator==(const Sphere& _s) const;
    bool operator!=(const Sphere& _s) const;

    double areaSph() const;
 private:
    bool negativeNumbers(const double _radius);
    double radius;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_SPHERE_H_
