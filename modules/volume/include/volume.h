// Copyright 2018 Shurygin Dmitriy


#ifndef MODULES_VOLUME_INCLUDE_VOLUME_H_
#define MODULES_VOLUME_INCLUDE_VOLUME_H_

class Sphere {
 private:
    double Radius;
    bool negativeNumbers(const double _rad);

 public:
    Sphere(const Sphere& sphere);
    explicit Sphere(const double _R);
    Sphere();
    double getRadius() const;
    void setRadius(const double _R);
    double Volume();
};

class Cube {
 private:
    double SideLength;
    bool negativeNumbers(const double _L);

 public:
    Cube(const Cube& cube);
    explicit Cube(const double _L);
    Cube();
    double getL() const;
    void setL(const double _L);
    double Volume();
};

class Cylinder {
 private:
    double Radius;
    double Height;
    bool negativeNumbers(const double _rad, const double _h);

 public:
    Cylinder(const Cylinder& cylinder);
    Cylinder(const double _R, const double _h);
    Cylinder();
    double getRadius() const;
    double getHeight() const;
    void setRadius(const double _R);
    void setHeight(const double _H);
    double Volume();
};

#endif  // MODULES_VOLUME_INCLUDE_VOLUME_H_
