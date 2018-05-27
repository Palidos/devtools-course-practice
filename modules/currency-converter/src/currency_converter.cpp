// Copyright 2018 Grishin Anton

#include "include/currency_converter.h"
#include <limits>
#include <string>

const double eps = std::numeric_limits<double>::epsilon();

CurrencyConverter::CurrencyConverter() : UsdToRub_rate(60), EurToRub_rate(75) {}

CurrencyConverter::CurrencyConverter(const double usd, const double eur)
                      : UsdToRub_rate(usd), EurToRub_rate(eur) {}

CurrencyConverter::CurrencyConverter(const CurrencyConverter& currency)
                      : UsdToRub_rate(currency.getUsdRate()),
                        EurToRub_rate(currency.getEurRate()) {}

CurrencyConverter& CurrencyConverter::operator=(
                  const CurrencyConverter& currency) {
    UsdToRub_rate = currency.getUsdRate();
    EurToRub_rate = currency.getEurRate();

    return *this;
}

double CurrencyConverter::getUsdRate() const {
    return UsdToRub_rate;
}

double CurrencyConverter::getEurRate() const {
    return EurToRub_rate;
}


void CurrencyConverter::setUsdRate(const double usd) {
    UsdToRub_rate = usd;
}

void CurrencyConverter::setEurRate(const double eur) {
    EurToRub_rate = eur;
}

double CurrencyConverter::roubleToDollar(double rub) {
    if (equalsZero(
        (this->getUsdRate()))) throw std::string("Can't divide by zero");
    return rub / (this->getUsdRate());
}

double CurrencyConverter::dollarToRouble(double usd) {
    return usd * (this->getUsdRate());
}

double CurrencyConverter::roubleToEuro(double rub) {
    if (equalsZero(
        (this->getEurRate()))) throw std::string("Can't divide by zero");
    return rub / (this->getEurRate());
}

double CurrencyConverter::euroToRouble(double eur) {
    return eur * (this->getEurRate());
}

double CurrencyConverter::dollarToEuro(double usd) {
    if (equalsZero(
        (this->getEurRate()))) throw std::string("Can't divide by zero");
    return usd * (this->getUsdRate()) / (this->getEurRate());
}

double CurrencyConverter::euroToDollar(double eur) {
    if (equalsZero(
        (this->getUsdRate()))) throw std::string("Can't divide by zero");
    return eur * (this->getEurRate()) / (this->getUsdRate());
}

bool CurrencyConverter::equalsZero(const double& value) const {
    return (value < eps && value > -eps);
}

bool CurrencyConverter::operator == (const CurrencyConverter& currency) const {
    if (((this->getUsdRate() - currency.getUsdRate()) == 0) &&
      ((this->getEurRate() - currency.getEurRate()) == 0)) return true;
    return false;
}

bool CurrencyConverter::operator != (const CurrencyConverter& currency) const {
    return !(*this == currency);
}
