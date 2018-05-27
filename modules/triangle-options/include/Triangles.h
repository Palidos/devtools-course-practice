// Copyright 2018 Senina Anastasia

#ifndef MODULES_TRIANGLE_OPTIONS_INCLUDE_TRIANGLES_H_
#define MODULES_TRIANGLE_OPTIONS_INCLUDE_TRIANGLES_H_

#include <stdexcept>
#define PI 3.14159265358979323846

struct Vertex {
  double x, y;  // the coordinates of the point

  Vertex() {
    x = 0;
    y = 0;
  }
  Vertex(double _x, double _y);

  bool operator==(const Vertex& a) const {
    return ((a.x == x) && (a.y == y));
  }
};

typedef enum {  // for name of vertex
  first = 1, second, third
} num_of_ver;

class Triangles {  // class of calculation of parameters of triangle
 private:
  Vertex first, second, third;
  double Length(Vertex, Vertex);

 public:
  Vertex Get_Vertex(num_of_ver num) const;
  Triangles(Vertex _first, Vertex _second, Vertex _third) : first(_first),
    second(_second), third(_third) {  // constructor with parameters
  double right = (third.x - first.x) / (second.x - first.x);
  double left = (third.y - first.y) / (second.y - first.y);
  if (right == left) {
    throw std::logic_error
    ("These points do not form a triangle!They lie on one straight line!!");
  }
  }
  Triangles(const Triangles& obj);  // copy constructor

  // numeric parameter
  double Get_Length_side(num_of_ver, num_of_ver);
  double Get_Angle(num_of_ver);
  double Get_Radius_Of_Inscribed_Circle();
  double Get_Radius_Of_Circumscribed_Circle();
  double Get_Square();
  double Get_Perimeter();

  // some remarkable points of a triangle
  Vertex Get_Barycenter();
  Vertex Get_Center_Of_Inscribed_Circle();
};
#endif  // MODULES_TRIANGLE_OPTIONS_INCLUDE_TRIANGLES_H_
