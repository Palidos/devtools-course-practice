// Copyright 2018 Boris Ermachenko

#include"include/Calculation_Rent.h"

#include <cmath>
Calculation_Rent::Calculation_Rent(
    double am_pay,
    double re_term,
    double int_rate) : amount_payment(am_pay), rent_term(re_term),
interest_rate(int_rate) {
    if (int_rate <= 0 || re_term <= 0 || am_pay <= 0) {
        throw "Enter a wrong mumber";
    }
    if (int_rate > 10000000 || re_term > 10000000
        || am_pay > 100000000) {
        throw "Enter a too long mumber";
    }
}
double Calculation_Rent::Rent_Accum_Year_postnum_hard_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*((pow((1 + in), re) - 1) / in);
}
double Calculation_Rent::Rent_Accum_Year_postnum_easy_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*(re + in*(re*(re - 1)) / 2);
}
double Calculation_Rent::Rent_Accum_Year_prenum_hard_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*((1 + in)* (pow((1 + in), re) - 1) / in);
}
double Calculation_Rent::Rent_Accum_Year_prenum_easy_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*(re + in*(re*(re + 1)) / 2);
}
double Calculation_Rent::Rent_Accum_P_Period_postnum(
    double nominal_rate, int number_compounding_per_year,
    int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0 || amount_payment <= 0
        || number_compounding_per_year <= 0
        || number_payments_per_year <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000 || rent_term >10000000
        || amount_payment >100000000 || number_compounding_per_year >100000000
        || number_payments_per_year >100000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re = rent_term;
    int nom = nominal_rate;
    int com = number_compounding_per_year;
    int pay = number_payments_per_year;
    return am*((pow((1 + nom / com), (com*re)) - 1)
        / (pay*((pow((1 + nom / com), (com / pay)) - 1))));
}
double Calculation_Rent::Rent_Accum_P_Period_prenum(
    double nominal_rate, int number_compounding_per_year,
    int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0 || amount_payment <= 0
        || number_compounding_per_year <= 0
        || number_payments_per_year <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000 || rent_term >10000000
        || amount_payment >100000000
        || number_compounding_per_year > 100000000
        || number_payments_per_year >10000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re = rent_term;
    int nom = nominal_rate;
    int com = number_compounding_per_year;
    int pay = number_payments_per_year;
    return am*(pow((1 + nom / com), (com / pay))*
        (pow((1 + nom / com), (com*re)) - 1)
        / (pay*((pow((1 + nom / com), (com / pay)) - 1))));
}
double Calculation_Rent::Rent_Modern_Year_postnum_hard_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*((1 - pow((1 + in), -re)) / in);
}
double Calculation_Rent::Rent_Modern_Year_postnum_easy_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    double rez = 0;
    for (int k = 1; k <= re; k++) {
        rez = rez + (1.0 / (1.0 + (in * k)));
    }
    rez = am*rez;
    return static_cast<int>(rez * 100 + 0.5) / 100.0;
}
double Calculation_Rent::Rent_Modern_Year_prenum_hard_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return static_cast<int>(am*((1 + in)*
        ((1 - pow((1 + in), -re)) / in)) * 10000 + 0.5) / 10000.0;
}
double Calculation_Rent::Rent_Modern_Year_prenum_easy_rate() {
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    double rez = 0;
    for (int k = 0; k <= re - 1; k++) {
        rez += (1 / (1 + in*k));
    }
    return am*(rez);
}
double Calculation_Rent::Rent_Modern_P_Period_postnum(
    double nominal_rate,
    int number_compounding_per_year, int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0
        || amount_payment <= 0 || number_compounding_per_year <= 0
        || number_payments_per_year <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000 || rent_term >10000000
        || amount_payment >100000000
        || number_compounding_per_year >100000000
        || number_payments_per_year >100000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re = rent_term;
    int nom = nominal_rate;
    int com = number_compounding_per_year;
    int pay = number_payments_per_year;
    return static_cast<int>(am*((1 - pow((1 + nom / com), (-com*re)))
        / (pay*((pow((1 + nom / com), (com / pay)) - 1))))
        * 10000 + 0.5) / 10000.0;
}
double Calculation_Rent::Rent_Modern_P_Period_prenum(
    double nominal_rate,
    int number_compounding_per_year, int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0
        || amount_payment <= 0 || number_compounding_per_year <= 0
        || number_payments_per_year <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000
        || rent_term >10000000 || amount_payment >100000000
        || number_compounding_per_year >100000000
        || number_payments_per_year >100000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re = rent_term;
    int nom = nominal_rate;
    int com = number_compounding_per_year;
    int pay = number_payments_per_year;
    return static_cast<int>(am*(pow((1 + nom / com), (com / pay))
        *(1 - pow((1 + nom / com), (-com*re)))
        / (pay*((pow((1 + nom / com), (com / pay)) - 1))))
        * 10000 + 0.5) / 10000.0;
}

