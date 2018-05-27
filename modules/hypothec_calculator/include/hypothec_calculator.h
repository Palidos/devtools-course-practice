// Copyright 2018 Rodionov Fedor

#ifndef MODULES_HYPOTHEC_CALCULATOR_INCLUDE_HYPOTHEC_CALCULATOR_H_
#define MODULES_HYPOTHEC_CALCULATOR_INCLUDE_HYPOTHEC_CALCULATOR_H_

struct date {
    int day;
    int month;
    int year;
};
class HypothecCalculator {
 private:
    float apartments_cost;
    float an_initial_fee;
    int credit_term_in_month;
    float interest_rate_in_month;
    float first_commissions;
    float monthly_commissions;
    bool differentiated_payment_type;
    bool annuity_payment_type;
    date start_of_payments;
    date final_date_of_payment;

 public:
    HypothecCalculator();
    HypothecCalculator(float costs, float fee, int term, float rate);
    void set_first_commissions(float _first_commissions);
    void set_monthly_commissions(float _monthly_commissions);
    void set_payment_type(int type);
    void set_date_of_payment(date _start_of_payments);
    float return_final_amount_of_payment();
    date return_final_date_of_payment();
};

#endif  // MODULES_HYPOTHEC_CALCULATOR_INCLUDE_HYPOTHEC_CALCULATOR_H_
