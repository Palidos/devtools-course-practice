// Copyright 2018 Galochkin Boris

#include <string>
#include <sstream>
#include <cmath>
#include <set>
#include <map>

#include "include/monom.h"
#include "include/polynom.h"

using std::stringstream;

Polynom::Polynom() : m_monoms() {
}

Polynom::Polynom(double coff) {
    if (coff != 0.0) m_monoms.emplace_back(Monom(coff));
}

Polynom::Polynom(const Polynom & rhs) : m_monoms(rhs.m_monoms) {
}

Polynom::Polynom(const string & str_poly) {
    string s;
    for (size_t i = 0; i < str_poly.size(); ++i) {
        s += str_poly[i];
        if (str_poly[i] == '+' || str_poly[i] == '-' || str_poly[i] == '*') {
            while (i < str_poly.size() && str_poly[i + 1] == ' ') { i++; }
        }
    }

    if (s.empty()) return;
    stringstream ss(s);
    string temp;
    while (!ss.eof()) {
        ss >> temp;
        Monom t(temp);
        if (t.m_coff != 0.0)
            m_monoms.emplace_back(t);
    }
}

Polynom & Polynom::operator=(const Polynom & z) {
    m_monoms = z.m_monoms;
    return *this;
}

void Polynom::AddMonom(const Monom & m) {
    for (auto& mm : m_monoms) {
        if (mm.m_variabels == m.m_variabels) {
            mm.m_coff += m.m_coff;
            return;
        }
    }
    m_monoms.push_back(m);
}

string Polynom::ToString() {
    stringstream ss;
    for (size_t i = 0; i < m_monoms.size() - 1; ++i)
        ss << "(" << m_monoms[i].ToString() << ") + ";
    if (m_monoms.size() > 0)
        ss << "(" << m_monoms[m_monoms.size() - 1].ToString() << ")";
    return ss.str();
}

bool Polynom::operator==(const Polynom & rhs) const {
    if (m_monoms.size() != rhs.m_monoms.size())
        return false;
    // N^2 mb use another data structure for savemonoms
    for (size_t i = 0; i < m_monoms.size(); ++i) {
        bool cont = false;
        for (size_t j = 0; j < rhs.m_monoms.size(); j++)
            if (m_monoms[i] == rhs.m_monoms[i]) {
                cont = true;
                break;
            }
        if (!cont) return false;
    }
    return true;
}

bool Polynom::operator!=(const Polynom & rhs) const {
    return !(*this == rhs);
}

Polynom Polynom::operator+(const Polynom & rhs) {
    Polynom tmp(*this);
    for (size_t j = 0; j < rhs.m_monoms.size(); j++) {
        int ind = Contains(tmp.m_monoms, rhs.m_monoms[j]);
        if (ind > -1)
            tmp.m_monoms[ind] = (tmp.m_monoms[ind] + rhs.m_monoms[j]);
        else
            tmp.m_monoms.push_back(rhs.m_monoms[j]);
    }
    return tmp;
}

Polynom Polynom::operator-(const Polynom & rhs) {
    Polynom tmp(*this);
    for (size_t j = 0; j < rhs.m_monoms.size(); j++) {
        int ind = Contains(tmp.m_monoms, rhs.m_monoms[j]);
        if (ind > -1) {
            auto t = (tmp.m_monoms[ind] - rhs.m_monoms[j]);
            if (t.m_coff != 0.0)
                tmp.m_monoms[ind] = t;
            else
                tmp.m_monoms.erase(tmp.m_monoms.begin() + ind);
        } else {
            tmp.m_monoms.push_back(Monom(-1.0) * rhs.m_monoms[j]);
        }
    }
    return tmp;
}

Polynom Polynom::operator*(const Polynom & rhs) {
    Polynom tmp;
    for (size_t i = 0; i < m_monoms.size(); i++) {
        for (size_t j = 0; j < rhs.m_monoms.size(); j++) {
            Monom t = m_monoms[i] * rhs.m_monoms[j];
            if (t.m_coff != 0.0)
                tmp.m_monoms.emplace_back(t);
        }
    }
    return tmp;
}

Polynom Polynom::operator/(const Monom & m) {
    Polynom tmp;
    for (size_t i = 0; i < m_monoms.size(); i++) {
        Monom t = m_monoms[i] / m;
        if (!std::isnan(t.m_coff))
            tmp.m_monoms.emplace_back(t);
    }
    return tmp;
}

map<char, double> Polynom::GetVarsList() {
    std::set<char> tmp;
    for (const auto& m : m_monoms) {
        for (const auto& v : m.m_variabels) {
            tmp.insert(v.first);
        }
    }
    map<char, double> ret;
    for (auto& t : tmp) {
        ret[t] = 1.0;
    }
    return ret;
}

double Polynom::CalculateResult(const map<char, double>& in_params) {
    double res = 0.0;
    for (const auto& m : m_monoms) {
        double tmp = m.m_coff;
        for (const auto& in_var : in_params) {
            auto m_var = m.m_variabels.find(in_var.first);
            if (m_var != m.m_variabels.end()) {
                tmp *= std::pow(in_var.second, (*m_var).second);
            }
        }
        res += tmp;
    }
    return res;
}

int Polynom::Contains(const monom_vec& vec, const Monom & m) const {
    for (size_t i = 0; i < vec.size(); i++)
        if (vec[i].m_variabels == m.m_variabels) return i;
    return -1;
}
