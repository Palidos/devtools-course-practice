// Copyright 2018 Lalykin Oleg

#include "include/elasticity-of-demand.h"
#include <math.h>
#include <limits>
#include <string>

const double eps = std::numeric_limits<double>::epsilon();

Elasticity::Elasticity(): coeff(0), answer("") {}


double Elasticity::GetCoeff() { return coeff; }

std::string Elasticity::GetAns() { return answer; }

bool Elasticity::IsZero(const double& value) const {
    return (value < eps && value > -eps);
}
double Elasticity::PriceElasticity(double Q1,
    double Q2,
    double P1,
    double P2) {
    // Q1 and Q2 - initial and current volume of demand;
    // P1 and P2 - initial and current price
    if (IsZero(P2 - P1) || IsZero(Q2 + Q1)) {
    throw std::string("Can't divide by zero");
    }
    coeff =
    fabs(((Q2 - Q1) / (Q2 + Q1)) *
    ((P2 + P1) / (P2 - P1)));
    return coeff;
}
double Elasticity::IncomeElasticity(double Q1,
    double Q2,
    double Y1,
    double Y2) {
     // Q1 and Q2 - initial and new volumes of demand;
     // Y1 and Y2 - initial and new income levels
    if (IsZero(Y2 - Y1) || IsZero(Q2 + Q1)) {
    throw std::string("Can't divide by zero");
    }
     coeff =
    ((Q2 - Q1) / (Q2 + Q1)) *
    ((Y2 + Y1) / (Y2 - Y1));
    return coeff;
}
double Elasticity::CrossElasticity(double Q1X,
    double Q2X,
    double P1Y,
    double P2Y) {
    // Q1X and Q2X - initial and new volumes of demand for goods X;
    // P2Y and P1Y - initial and new price of goods Y
    if (IsZero(P2Y - P1Y) || IsZero(Q2X + Q1X)) {
    throw std::string("Can't divide by zero");
    }
    coeff =
    ((Q2X - Q1X) / (Q2X + Q1X)) *
    ((P2Y + P1Y) / (P2Y - P1Y));
    return coeff;
}
void Elasticity::PriceAnswer() {
    if (coeff > 1) answer = "demand is elastic";
    if (coeff < 1) answer = "demand is inelastic";
    if (coeff == 1) answer = "unit elasticity";
}
void Elasticity::IncomeAnswer() {
    if (coeff > 0) answer = "normal goods";
    if (coeff <= 0) answer = "inferior goods";
}
void Elasticity::CrossAnswer() {
    if (coeff > 0) answer = "goods are interchangeable";
    if (coeff < 0) answer = "mutually complementary goods";
    if (coeff == 0) answer = "goods independent of each other";
}
