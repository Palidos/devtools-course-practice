// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_

class Cone {
 public:
    Cone();
    Cone(const double& _rad, const double& _l);
    Cone(const Cone& _c);

    Cone& operator=(const Cone& _c);

    double getRad() const;
    double getL() const;
    void setRad(const double _rad);
    void setL(const double _l);

    bool operator==(const Cone& _c) const;
    bool operator!=(const Cone& _c) const;

    double areaCone() const;
 private:
    bool negativeNumbers(const double _rad, const double _l);
    double radius;
    double l;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CONE_H_
