// Copyright 2018 Kiselev Denis

// It's a class of simple regular expressions
// The following metacharacters are available:
// "\\d" - digit
// "\\D" - any character except digits
// "\\w" - digit, character (a-z, A-Z) or '_'
// "\\W" - any character except characters in \\w

#ifndef MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_H_
#define MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_H_

#include <cstddef>

class SimpleRegex {
 public:
    explicit SimpleRegex(const char* regex);

    const char* getRegex() const;
    void  setRegex(const char* regex);

    bool isMatch(const char* str);
    void getMatch(char* buffer, std::size_t size);
    int getMatchIndex() const;

 private:
    const char* regex_;
    const char* str_;
    int matchBegin_;
    int matchEnd_;
};

#endif  // MODULES_SIMPLE_REGEX_INCLUDE_SIMPLE_REGEX_H_
