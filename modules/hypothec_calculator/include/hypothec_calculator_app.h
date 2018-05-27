// Copyright 2018 Bederdinov Daniil

#ifndef MODULES_HYPOTHEC_CALCULATOR_INCLUDE_HYPOTHEC_CALCULATOR_APP_H_
#define MODULES_HYPOTHEC_CALCULATOR_INCLUDE_HYPOTHEC_CALCULATOR_APP_H_
#include <string>

class HypothecCalculatorApp {
 public:
    HypothecCalculatorApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        float apartments_cost;
        float an_initial_fee;
        int credit_term_in_month;
        float interest_rate_in_month;
        const char* output_file_name;
    } Arguments;
};

#endif  // MODULES_HYPOTHEC_CALCULATOR_INCLUDE_HYPOTHEC_CALCULATOR_APP_H_
