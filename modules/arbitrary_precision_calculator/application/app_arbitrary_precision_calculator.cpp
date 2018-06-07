// Copyright 2018 Evsyakova Ekaterina

#include "include/arbitrary_precision_calculator_app.h"

#include <cstdlib>
#include <cstdio>
#include <string>

int main(int argc, const char** argv) {
    ArbitraryPrecisionCalculatorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
