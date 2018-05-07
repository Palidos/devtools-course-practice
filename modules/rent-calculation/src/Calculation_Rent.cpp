// Copyright 2018 Boris Ermachenko

#include"include/Calculation_Rent.h"

#include <cmath>
double Calculation_Rent::Rent_Accum_Yearly_postnumerando_hard_rate(double amount_of_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 10000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*((pow((1 + in), re) - 1) / in);
}
double Calculation_Rent::Rent_Accum_Yearly_postnumerando_easy_rate(double amount_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 100000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;

    return am*(re + in*(re*(re-1))/2 );
}
double Calculation_Rent::Rent_Accum_Yearly_prenumerando_hard_rate(double amount_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 100000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*( (1+in)* (pow((1 + in), re) - 1) / in );
}
double Calculation_Rent::Rent_Accum_Yearly_pretnumerando_easy_rate(double amount_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 100000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*(re + in*(re*(re + 1)) / 2);
}
double Calculation_Rent::Rent_Accum_P_Period_postnumerando(double amount_payment, double rent_term, double nominal_rate, int number_compounding_per_year, int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0 || amount_payment <= 0 || number_compounding_per_year <= 0 || number_payments_per_year <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000 || rent_term >10000000 || amount_payment >100000000 || number_compounding_per_year>100000000 || number_payments_per_year >100000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re=rent_term;
    int nom = nominal_rate;
    int com=number_compounding_per_year;
    int pay=number_payments_per_year;
    return am*((pow((1 + nom / com), (com*re)) - 1) / (pay*((pow((1 + nom / com), (com / pay)) - 1))));
}
double Calculation_Rent::Rent_Accum_P_Period_prenumerando(double amount_payment, double rent_term, double nominal_rate, int number_compounding_per_year, int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0 || amount_payment <= 0 || number_compounding_per_year <= 0 || number_payments_per_year <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000 || rent_term >10000000 || amount_payment >100000000 || number_compounding_per_year>100000000 || number_payments_per_year >10000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re = rent_term;
    int nom = nominal_rate;
    int com = number_compounding_per_year;
    int pay = number_payments_per_year;
    return am*(pow((1 + nom / com), (com / pay))*(pow((1 + nom / com), (com*re)) - 1) / (pay*((pow((1 + nom / com), (com / pay)) - 1))));
}
double Calculation_Rent::Rent_Modern_Yearly_postnumerando_hard_rate(double amount_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 100000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return am*((1-pow((1 + in), -re)) / in);
}
double Calculation_Rent::Rent_Modern_Yearly_postnumerando_easy_rate(double amount_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 100000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    double rez = 0;
    for (int k = 1; k <= re; k++) {
    rez = rez + (1.0 / (1.0 + (in * k)));
    }
    rez = am*rez;
    return int(rez*100+0.5)/100.0;
}
double Calculation_Rent::Rent_Modern_Yearly_prenumerando_hard_rate(double amount_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 100000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    return int(am*((1 + in)* ((1 - pow((1 + in), -re)) / in))*10000+0.5)/10000.0;
}
double Calculation_Rent::Rent_Modern_Yearly_pretnumerando_easy_rate(double amount_payment, double rent_term, double interest_rate) {
    if (interest_rate <= 0 || rent_term <= 0 || amount_payment <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (interest_rate > 10000000 || rent_term > 10000000 || amount_payment > 100000000) {
        throw "Enter a too long mumber";
        return 0;
    }
    int in = interest_rate;
    double am = amount_payment;
    double re = rent_term;
    double rez = 0;
    for (int k = 0; k <= re-1; k++) {
        rez += (1 / (1 + in*k));
    }
    return am*(rez);
}
double Calculation_Rent::Rent_Modern_P_Period_postnumerando(double amount_payment, double rent_term, double nominal_rate, int number_compounding_per_year, int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0 || amount_payment <= 0 || number_compounding_per_year <= 0 || number_payments_per_year <= 0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000 || rent_term >10000000 || amount_payment >100000000 || number_compounding_per_year>100000000 || number_payments_per_year >100000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re = rent_term;
    int nom = nominal_rate;
    int com = number_compounding_per_year;
    int pay = number_payments_per_year;
    return int(am*((1 - pow((1 + nom / com), (-com*re))) / (pay*((pow((1 + nom / com), (com / pay)) - 1)))) * 10000 + 0.5) / 10000.0;
}
double Calculation_Rent::Rent_Modern_P_Period_prenumerando(double amount_payment, double rent_term, double nominal_rate, int number_compounding_per_year, int number_payments_per_year) {
    if (nominal_rate <= 0 || rent_term <= 0 || amount_payment <= 0 || number_compounding_per_year<=0 || number_payments_per_year <=0) {
        throw "Enter a wrong mumber";
        return 0;
    }
    if (nominal_rate > 100000000 || rent_term >10000000 || amount_payment >100000000 || number_compounding_per_year>100000000 || number_payments_per_year >100000000) {
        throw "Enter a wrong mumber";
        return 0;
    }
    double am = amount_payment;
    double re = rent_term;
    int nom = nominal_rate;
    int com = number_compounding_per_year;
    int pay = number_payments_per_year;
    return int(am*(pow((1 + nom / com), (com / pay))*(1 - pow((1 + nom / com), (-com*re))) / (pay*((pow((1 + nom / com), (com / pay)) - 1)))) * 10000 + 0.5) / 10000.0;
}
