// Copyright 2018 Boris Ermachenko

#ifndef MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_
#define MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_

class Calculation_Rent{
 private:
    double amount_payment;
    double rent_term;
    double interest_rate;

 public:
    Calculation_Rent(
        double am_pay = 1,
        double re_term = 1,
        double int_rate = 1);
    ~Calculation_Rent() {}
    double Rent_Accum_Year_postnum_hard_rate();
    double Rent_Accum_Year_postnum_easy_rate();
    double Rent_Accum_Year_prenum_hard_rate();
    double Rent_Accum_Year_prenum_easy_rate();
    double Rent_Accum_P_Period_postnum(double nominal_rate,
        int number_compounding_per_year,
        int number_payments_per_year);
    double Rent_Accum_P_Period_prenum(
        double nominal_rate,
        int number_compounding_per_year,
        int number_payments_per_year);
    double Rent_Modern_Year_postnum_hard_rate();
    double Rent_Modern_Year_postnum_easy_rate();
    double Rent_Modern_Year_prenum_hard_rate();
    double Rent_Modern_Year_prenum_easy_rate();
    double Rent_Modern_P_Period_postnum(double nominal_rate,
        int number_compounding_per_year,
        int number_payments_per_year);
    double Rent_Modern_P_Period_prenum(double nominal_rate,
        int number_compounding_per_year,
        int number_payments_per_year);
};

#endif  // MODULES_RENT_CALCULATION_INCLUDE_CALCULATION_RENT_H_

