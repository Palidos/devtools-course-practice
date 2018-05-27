// Copyright Volkov Daniel

#include "include/deposit-calculator.h"

Deposit::Deposit(int _Sum, float _percent,
                 int _duration, int type_of_capitalization,
                 bool On_the_bill) {
    if (_percent < 0 || _Sum < 0 || _duration <= 0)
        throw - 1;
    if (type_of_capitalization == 0 || type_of_capitalization == 1
    || type_of_capitalization == 2)
        capitalization = type_of_capitalization;
    else
        throw - 1;
    Sum = static_cast<double>(_Sum);
    percent = _percent;
    duration = _duration;
    on_the_bill = On_the_bill;
}
Deposit::Deposit(const Deposit& copy) {
    Sum = copy.Sum;
    percent = copy.percent;
    duration = copy.duration;
    capitalization = copy.capitalization;
    on_the_bill = copy.on_the_bill;
}

double Deposit::getIncome() {
    return IncomeAfterDays(duration);
}

double Deposit::IncomeAfterTimes(int num_of_days, int num_of_Months,
                                 int num_of_years) {
    if (num_of_days < 0 || num_of_Months < 0 || num_of_years < 0)
        throw - 1;

    return IncomeAfterDays(num_of_days) + IncomeAfterMonts(num_of_Months)
    + IncomeAfterYears(num_of_years);
}

double Deposit::BalanceAfterTimes(int num_of_days, int num_of_Months,
                                  int num_of_years) {
    return Sum + IncomeAfterTimes(num_of_days, num_of_Months, num_of_years);
}

double Deposit::IncomeAfterDays(int num_of_days) {
    if (num_of_days == 0)
        return 0;
    if (on_the_bill) {
        if (capitalization == 0) {
            return Sum * (pow((percent / 36500 + 1), num_of_days)) - Sum;
        } else {
        if (capitalization == 1) {
            return IncomeAfterMonts(num_of_days / 30);
        } else {
            return IncomeAfterYears(num_of_days / 365);
        }
      }
    } else {
        if (capitalization == 0) {
            return (Sum * (percent / 36500 + 1) - Sum) * num_of_days;
        } else {
        if (capitalization == 1) {
            return IncomeAfterMonts(num_of_days / 30);
        } else {
            return IncomeAfterYears(num_of_days / 365);
        }
      }
    }
}

double Deposit::IncomeAfterMonts(int num_of_months) {
    if (num_of_months == 0)
        return 0;
    if (on_the_bill) {
        if (capitalization == 0) {
            return IncomeAfterDays(num_of_months * 30);
        } else {
        if (capitalization == 1) {
            return Sum * (pow((percent / 1200 + 1), num_of_months)) - Sum;
        } else {
            return IncomeAfterYears(num_of_months / 12);
        }
      }
    } else {
        if (capitalization == 0) {
            return IncomeAfterDays(num_of_months * 30);
        } else {
        if (capitalization == 1) {
            return (Sum * (percent / 1200 + 1) - Sum) * num_of_months;
        } else {
            return IncomeAfterYears(num_of_months / 12);
        }
      }
    }
}

double Deposit::IncomeAfterYears(int num_of_years) {
    if (num_of_years == 0)
        return 0;
    if (on_the_bill) {
        if (capitalization == 0) {
            return IncomeAfterDays(num_of_years * 365);
        } else {
        if (capitalization == 1) {
            return IncomeAfterMonts(num_of_years * 12);
        } else {
            return Sum * (pow((percent / 100 + 1), num_of_years)) - Sum;
        }
      }
    } else {
        if (capitalization == 0) {
            return IncomeAfterDays(num_of_years * 365);
        } else {
        if (capitalization == 1) {
            return IncomeAfterMonts(num_of_years * 12);
        } else {
            return (Sum * (percent / 100 + 1) - Sum) * num_of_years;
        }
    }
}
}
