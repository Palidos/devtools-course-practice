// Copyright 2018 Chvanov Leonid

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_

#include <vector>

class QuadraticEquation {
 public:
     QuadraticEquation(const double& _a,
                       const double& _b,
                       const double& _c);
     ~QuadraticEquation();

     std::vector<double> getRoots();
     void setCoefficients(const double& _a,
                          const double& _b,
                          const double& _c);

 private:
     double a, b, c;  // coefficients in a*x^2 + b*x + c = 0
     double discriminant;
     std::vector<double> roots;

     bool isSolved;

     bool hasRealRoots() const;
     void solve();
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_H_
