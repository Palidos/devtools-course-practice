// Copyright 2018 Gusev Alexandr

#include "include/Vigner_code.h"
#include <string>

std::string symbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

Vigner_code::Vigner_code() {
}

int Vigner_code::Keycode(char s) {
    int res;
    for (unsigned int k = 0; k < symbols.length(); k++)
        if (s == symbols[k])
            res = k;
    return res;
}

std::string Vigner_code::Encode(std::string Text, std::string Key) {
    std::string result;
    unsigned int i, j = 0;
    for (i = 0; i < Text.length(); i++) {
        if (j >= Key.length())
            j = 0;
        unsigned int sum = Keycode(Text[i]) + Keycode(Key[j]) + 1;
        if (sum > symbols.length() - 1)
            sum = sum - symbols.length();
        result += symbols[sum];
        j++;
    }
    j = 0;
    return result;
}

std::string Vigner_code::Decode(std::string Text, std::string Key) {
    std::string result;
    unsigned int i, j = 0;
    for (i = 0; i < Text.length(); i++) {
        if (j >= Key.length())
            j = 0;
        int sum = Keycode(Text[i]) - Keycode(Key[j]) - 1;
        if (sum < 0)
            sum = sum + symbols.length();
        result += symbols[sum];
        j++;
    }
    j = 0;
    return result;
}
