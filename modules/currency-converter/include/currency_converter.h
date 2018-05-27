// Copyright 2018 Grishin Anton

#ifndef MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
#define MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_


class CurrencyConverter {
 public:
    CurrencyConverter();
    CurrencyConverter(const double usd, const double eur);
    CurrencyConverter(const CurrencyConverter& currency);

    CurrencyConverter& operator=(const CurrencyConverter& currency);

    double getUsdRate() const;
    double getEurRate() const;

    void setUsdRate(const double usd);
    void setEurRate(const double eur);

    double roubleToDollar(double rub);
    double dollarToRouble(double usd);

    double roubleToEuro(double rub);
    double euroToRouble(double eur);

    double dollarToEuro(double usd);
    double euroToDollar(double eur);

    bool operator == (const CurrencyConverter& currency) const;
    bool operator != (const CurrencyConverter& currency) const;

 private:
    bool equalsZero(const double& value) const;
    double UsdToRub_rate;
    double EurToRub_rate;
};

#endif  // MODULES_CURRENCY_CONVERTER_INCLUDE_CURRENCY_CONVERTER_H_
