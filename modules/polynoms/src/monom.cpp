// Copyright 2018 Galochkin Boris

#include <sstream>
#include <set>
#include <cmath>
#include <string>

#include "include/monom.h"

using std::set;
using std::stringstream;

Monom::Monom() : m_coff(1.0) {
}

Monom::Monom(double c) : m_coff(c) {
}

Monom::Monom(const Monom & rhs) :
    m_variabels(rhs.m_variabels),
    m_coff(rhs.m_coff) {
}

Monom::Monom(const string & str_monom) {
    static set<char> ok_symbols = { '^', '.', ',', '+', '-' };
    m_coff = 1.0;
    string s;
    for (auto&c : str_monom) {
        if (!(isspace(c) || !(isalpha(c) || isdigit(c) || ok_symbols.count(c))))
            s += c;
    }
    if (s.empty()) return;
    StrParseSymbols(StrEmplaceSpaces(s));
}

Monom & Monom::operator=(const Monom & z) {
    m_variabels = z.m_variabels;
    m_coff = z.m_coff;
    return *this;
}

string Monom::ToString() {
    stringstream ss;
    ss << m_coff;
    for (auto& v : m_variabels) {
        if (v.second != 0.0) {
            ss << v.first;
            ss << '^';
            ss << v.second;
        }
    }
    return ss.str();
}

bool Monom::operator==(const Monom & rhs) const {
    if (std::abs(m_coff - rhs.m_coff) > 1.0e-05) return false;
    return EqualsVariabels(rhs);
}

bool Monom::operator!=(const Monom & rhs) const {
    return !(*this == rhs);
}

Monom Monom::operator+(const Monom & rhs) {
    Monom tmp(*this);
    if (EqualsVariabels(rhs)) {
        tmp.m_coff += rhs.m_coff;
    }
    return tmp;
}

Monom Monom::operator-(const Monom & rhs) {
    Monom tmp(*this);
    if (EqualsVariabels(rhs)) {
        tmp.m_coff -= rhs.m_coff;
    }
    return tmp;
}

Monom Monom::operator*(const Monom & rhs) {
    Monom ret(*this);
    ret.m_coff *= rhs.m_coff;
    for (auto& var : rhs.m_variabels) {
        auto rv = ret.m_variabels.find(var.first);
        if (rv == ret.m_variabels.end()) {
            ret.m_variabels.insert(var);
        } else {
            ret.m_variabels[var.first] += var.second;
        }
    }
    return ret;
}

Monom Monom::operator/(const Monom & rhs) {
    if (rhs.m_coff == 0.0)
        throw string("Can't divide by zero");
    Monom ret(*this);
    ret.m_coff /= rhs.m_coff;
    for (auto& var : rhs.m_variabels) {
        auto rv = ret.m_variabels.find(var.first);
        if (rv == ret.m_variabels.end()) {
            auto tmp = var;
            tmp.second *= -1;
            ret.m_variabels.insert(tmp);
        } else {
            ret.m_variabels[var.first] -= var.second;
            if (ret.m_variabels[var.first] == 0.0) {
                auto it = ret.m_variabels.find(var.first);
                ret.m_variabels.erase(it);
            }
        }
    }
    return ret;
}

string Monom::StrEmplaceSpaces(const string& s_in) {
    if (s_in.empty()) return "";
    auto s(s_in);
    for (size_t i = 0; i < s.size(); ++i) {
        if (isalpha(s[i]) || s[i] == '^') {
            if (i > 0 && s[i - 1] != ' ') {
                s.insert(i, 1, ' ');
                s.insert(++i + 1, 1, ' ');
            } else {
                s.insert(++i, 1, ' ');
            }
        } else if (s[i] == '+' || s[i] == '-') {
            s.insert(i++, 1, ' ');
        }
    }
    return s;
}

void Monom::StrParseSymbols(const string & s) {
    if (s.empty()) return;
    stringstream ss(s);
    string temp;
    double found = 0.0;
    char symbol;
    char last_found_symbol;
    bool its_pow = false;
    bool istrash = true;
    while (!ss.eof()) {
        ss >> temp;
        if (stringstream(temp) >> found) {
            if (!its_pow) {
                m_coff *= found;
            } else {
                m_variabels[last_found_symbol] += found - 1;
            }
            its_pow = false;
            istrash = false;
        } else if (stringstream(temp) >> symbol) {
            its_pow = (symbol == '^');
            if (isalpha(symbol)) {
                m_variabels[symbol]++;
                last_found_symbol = symbol;
                istrash = false;
            }
            if (symbol == '-') m_coff *= -1.0;
        }
        temp = "";
    }
    if (istrash)
        m_coff = 0.0;
}

bool Monom::EqualsVariabels(const Monom& r) const {
    for (auto& var : m_variabels) {
        auto rv = r.m_variabels.find(var.first);
        if (rv == r.m_variabels.end() || (*rv).second != var.second) {
            return false;
        }
    }
    return true;
}
