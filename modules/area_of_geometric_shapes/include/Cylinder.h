// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CYLINDER_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CYLINDER_H_

class Cylinder {
 public:
    Cylinder();
    Cylinder(const double& _rad, const double& _h);
    Cylinder(const Cylinder& _c);

    Cylinder& operator=(const Cylinder& _c);

    double getRad() const;
    double getH() const;
    void setRad(const double _rad);
    void setH(const double _h);

    bool operator==(const Cylinder& _c) const;
    bool operator!=(const Cylinder& _c) const;

    double areaCyl() const;
 private:
    bool negativeNumbers(const double _rad, const double _h);
    double radius;
    double h;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CYLINDER_H_
