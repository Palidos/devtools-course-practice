// Copyright 2018 Kiselev Denis

#define _CRT_SECURE_NO_WARNINGS

#include "include/simple_regex.h"

#include <stdexcept>
#include <cstring>

SimpleRegex::SimpleRegex(const char* regex) : str_(nullptr) {
    str_ = nullptr;
    setRegex(regex);
}

const char* SimpleRegex::getRegex() const {
    return regex_;
}

void SimpleRegex::setRegex(const char* regex) {
    matchBegin_ = matchEnd_ = -1;
    regex_ = regex;
}

bool SimpleRegex::isMatch(const char* str) {
    bool isDigit, isLetter;
    matchBegin_ = 0;
    str_ = str;

    int i = 0, j = 0;
    while (true) {
        if ((regex_[i] != '\0') && (str[j] == '\0')) {
            matchBegin_ = matchEnd_ = -1;
            str_ = nullptr;
            return false;
        }

        switch (regex_[i]) {
            case '\\' :
                isDigit = ('0' <= str[j]) && (str[j] <= '9');
                isLetter = (('A' <= str[j]) && (str[j] <= 'Z')) ||
                           (('a' <= str[j]) && (str[j] <= 'z'));
                switch (regex_[++i]) {
                    case 'd' :
                        if (!isDigit) {
                            if (i > 1) {
                                --j;
                            }
                            i = -1;
                            matchBegin_ = j + 1;
                        }
                        break;

                    case 'w' :
                        if (!isDigit && !isLetter && str[j] != '_') {
                            if (i > 1) {
                                --j;
                            }
                            i = -1;
                            matchBegin_ = j + 1;
                        }
                        break;

                    case 'D' :
                        if (isDigit) {
                            if (i > 1) {
                                --j;
                            }
                            i = -1;
                            matchBegin_ = j + 1;
                        }
                        break;

                    case 'W' :
                        if (isDigit || isLetter || str[j] == '_') {
                            if (i > 1) {
                                --j;
                            }
                            i = -1;
                            matchBegin_ = j + 1;
                        }
                        break;

                    case '\\' :
                        if (str[j] != '\\') {
                            if (i > 1) {
                                --j;
                            }
                            i = -1;
                            matchBegin_ = j + 1;
                        }
                        break;

                    default:
                        throw std::invalid_argument("Invalid metasymbol.");
                        break;
                }
                ++i;
                ++j;
                break;

            case '\0':
                matchEnd_ = j;
                return true;

            default :
                if (regex_[i] != str[j]) {
                    if (i > 0) {
                        --j;
                    }
                    i = -1;
                    matchBegin_ = j + 1;
                }
                ++i;
                ++j;
                break;
        }
    }
    matchEnd_ = j;

    return true;
}

void SimpleRegex::getMatch(char* buffer, std::size_t size) {
    if (size - 1 < static_cast<std::size_t>(matchEnd_ - matchBegin_)) {
        throw std::length_error("Insufficient buffer size.");
    }

    strncpy(buffer, str_ + matchBegin_, matchEnd_ - matchBegin_);
    buffer[matchEnd_ - matchBegin_] = '\0';
}

int SimpleRegex::getMatchIndex() const {
    return matchBegin_;
}
