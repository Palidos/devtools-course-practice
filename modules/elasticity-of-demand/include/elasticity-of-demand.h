// Copyright 2018 Lalykin Oleg

#ifndef MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
#define MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_

#include <string>

class Elasticity {
 public:
    Elasticity();

    double PriceElasticity(double Q1, double Q2, double P1, double P2);
    double IncomeElasticity(double Q1, double Q2, double Y1, double Y2);
    double CrossElasticity(double Q1X, double Q2X, double P1Y, double P2Y);
    void PriceAnswer();
    void IncomeAnswer();
    void CrossAnswer();
    double GetCoeff();
    std::string GetAns();


 private:
    double coeff;
    std::string answer;
    bool IsZero(const double& value) const;
};
#endif  //  MODULES_ELASTICITY_OF_DEMAND_INCLUDE_ELASTICITY_OF_DEMAND_H_
