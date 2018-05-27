// Copyright 2018 Generalov Aleksandr

#ifndef MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CUBE_H_
#define MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CUBE_H_

class Cube {
 public:
    Cube();
    explicit Cube(const double& _h);
    Cube(const Cube& _c);

    Cube& operator=(const Cube& _c);

    double getH() const;
    void setH(const double _h);

    bool operator==(const Cube& _c) const;
    bool operator!=(const Cube& _c) const;

    double areaCube() const;
 private:
    bool negativeNumbers(const double _h);
    double h;
};

#endif  // MODULES_AREA_OF_GEOMETRIC_SHAPES_INCLUDE_CUBE_H_
