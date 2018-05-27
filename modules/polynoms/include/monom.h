// Copyright 2018 Galochkin Boris

#ifndef MODULES_POLYNOMS_INCLUDE_MONOM_H_
#define MODULES_POLYNOMS_INCLUDE_MONOM_H_

#include <string>
#include <map>
using std::string;
using std::map;

class Monom {
    using POW_TYPE = double;
    using VAR_NAME = char;
    using var_map = map<VAR_NAME, POW_TYPE>;

 public:
    Monom();
    explicit Monom(double c);

    Monom(const Monom& rhs);
    explicit Monom(const string& str_monom);

    Monom& operator=(const Monom& z);

    string ToString();

    bool operator==(const Monom& rhs) const;
    bool operator!=(const Monom& rhs) const;

 private:
    // That is unsafe methods, can be called only from Polynom
    Monom operator+(const Monom& rhs);
    Monom operator-(const Monom& rhs);
    Monom operator*(const Monom& rhs);
    Monom operator/(const Monom& rhs);

    string StrEmplaceSpaces(const string& s);
    void StrParseSymbols(const string& s);
    bool EqualsVariabels(const Monom& r) const;

 private:
    var_map m_variabels;
    double m_coff;

    friend class Polynom;
};
#endif  // MODULES_POLYNOMS_INCLUDE_MONOM_H_
