// Copyright 2018 Senina Anastasia

#include "include/Triangles.h"
#include <math.h>

Vertex::Vertex(double _x, double _y) {
  x = _x;
  y = _y;
}

double Triangles::Length(Vertex a, Vertex b) {
  return sqrt((a.x - b.x)*
    (a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

Vertex Triangles::Get_Vertex(num_of_ver num) const {
  if (num == 1) return first;
  if (num == 2) return second;
  return third;
}

Triangles::Triangles(const Triangles& obj) : first(obj.first),
second(obj.second), third(obj.third) {}


double Triangles::Get_Length_side(num_of_ver _num1, num_of_ver _num2) {
  if (_num1 == _num2) {
    throw std::logic_error("Vertexes of sides are the same ");
  } else {
    return Length(Get_Vertex(_num1), Get_Vertex(_num2));
  }
}

double Triangles::Get_Angle(num_of_ver _num) {
  num_of_ver _num1 = (num_of_ver)((static_cast<int>(_num)) % 3 + 1);
  num_of_ver _num2 = (num_of_ver)(((static_cast<int>(_num)) + 1) % 3 + 1);
  Vertex v1 = Get_Vertex(_num),
    v2 = Get_Vertex(_num1),
    v3 = Get_Vertex(_num2);

  double l1 = Get_Length_side(_num, _num1),
    l2 = Get_Length_side(_num, _num2);

  return acos(((v2.x - v1.x)*(v3.x - v1.x) +
    (v2.y - v1.y)*(v3.y - v1.y)) /
    (l1 * l2));
}

double Triangles::Get_Radius_Of_Inscribed_Circle() {
  double S = Get_Square();
  double p = Get_Perimeter() / 2;
  return  S / p;
}

double Triangles::Get_Radius_Of_Circumscribed_Circle() {
  double a = Length(first, second);
  double b = Length(second, third);
  double c = Length(first, third);
  double S = Get_Square();

  return a*b*c / (4 * S);
}
double Triangles::Get_Square() {
  return fabs(first.x*(second.y - third.y) + second.x*(third.y - first.y)
    + third.x*(first.y - second.y)) / 2;
}

double Triangles::Get_Perimeter() {
  return Length(first, second) + Length(first, third) + Length(third, second);
}

Vertex Triangles::Get_Barycenter() {
  double x = (first.x + second.x + third.x) / 3;
  double y = (first.y + second.y + third.y) / 3;
  Vertex _barycenter(x, y);

  return _barycenter;
}

Vertex Triangles::Get_Center_Of_Inscribed_Circle() {
  double a = Length(first, second);
  double b = Length(second, third);
  double c = Length(first, third);
  double x = a*first.x + b*second.x + c* third.x / (a + b + c);
  double y = a*first.y + b*second.y + c* third.y / (a + b + c);

  return Vertex(x, y);
}
