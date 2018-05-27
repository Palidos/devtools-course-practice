// Copyright Volkov Daniel

#ifndef MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
#define MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
#include <cmath>

class Deposit {
    double Sum;         // сумма сейчас на счету
    float percent;      // процент
    bool on_the_bill;   // оставлять проценты на счету
    int duration;       // продолжительность вклада(дней)
    int capitalization;   // тип капитализации

 public:
    // (_Sum сумма вклада, _percent процент годовой,
    // _duration продолжительность вклада(дней),
    // type_of_capitalization тип капитализации
    // (0-ежегодно, 1-ежемесечно, 2-ежедневно),
    // On_the_bill(выплачивать деньги, или пополнять вклад))
    Deposit(int _Sum = 100000, float _percent = 8,
            int _duration = 360, int type_of_capitalization = 0,
            bool On_the_bill = true);
    Deposit(const Deposit& copy);
    double getIncome();
    double IncomeAfterTimes(int num_of_days = 0, int num_of_Months = 0,
                            int num_of_years = 0);
    double BalanceAfterTimes(int num_of_days = 0, int num_of_Months = 0,
                             int num_of_years = 0);

 private:
    double IncomeAfterDays(int num_of_days);
    double IncomeAfterMonts(int num_of_months);
    double IncomeAfterYears(int num_of_years);
};

#endif  // MODULES_DEPOSIT_CALCULATOR_INCLUDE_DEPOSIT_CALCULATOR_H_
