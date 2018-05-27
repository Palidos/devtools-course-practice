// Copyright 2018 Gusev Alexandr
#include <iostream>
#include <string>

#ifndef MODULES_VIGNER_CODE_INCLUDE_VIGNER_CODE_H_
#define MODULES_VIGNER_CODE_INCLUDE_VIGNER_CODE_H_

class Vigner_code {
 public:
    Vigner_code();
    int Keycode(char s);
    std::string Encode(std::string Text, std::string Key);
    std::string Decode(std::string Text, std::string Key);
};

#endif  // MODULES_VIGNER_CODE_INCLUDE_VIGNER_CODE_H_
