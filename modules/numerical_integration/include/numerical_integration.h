// Copyright 2018 Lvova Alina

#ifndef MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_H_
#define MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_H_

class Integral {
 public:
    Integral();
    Integral(double lower_limit, double upper_limit, int divisions);
    double RiemannSumLeft();
    double TrapezoidalRule();
    double SimpsonRule();
    double Simpson3_8Rule();
    double BooleRule();
    double NewtonCotes5();
    double GaussianQuadrature();
    void setLower(double _low);
    void setUpper(double _up);
    void setDivisions(int _div);

 private:
    bool negative;
    bool nullResult;
    double res;
    double step;
    int divisions;
    double low, up;
    double function(double x);
    void limitAdjustment(double _low, double _up);
};
#endif  // MODULES_NUMERICAL_INTEGRATION_INCLUDE_NUMERICAL_INTEGRATION_H_
