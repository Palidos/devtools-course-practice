// Copyright 2018 Evsyakova Ekaterina

#ifndef MODULES_ARBITRARY_PRECISION_CALCULATOR_INCLUDE_ARBITRARY_PRECISION_CALCULATOR_APP_H_
#define MODULES_ARBITRARY_PRECISION_CALCULATOR_INCLUDE_ARBITRARY_PRECISION_CALCULATOR_APP_H_

#include <string>
#include <vector>

class ArbitraryPrecisionCalculatorApp {
 public:
    ArbitraryPrecisionCalculatorApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        std::vector<int> z1;
        std::vector<int> z2;
        char operation;
    } Arguments;
};

#endif  // MODULES_ARBITRARY_PRECISION_CALCULATOR_INCLUDE_ARBITRARY_PRECISION_CALCULATOR_APP_H_
