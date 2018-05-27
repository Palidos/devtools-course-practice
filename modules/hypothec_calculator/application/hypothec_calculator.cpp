// Copyright 2018 Bederdinov Daniil

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/hypothec_calculator_app.h"

int main(int argc, const char** argv) {
    HypothecCalculatorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
