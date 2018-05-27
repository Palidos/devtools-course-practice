// Copyright 2018 Galochkin Boris

#ifndef MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
#define MODULES_POLYNOMS_INCLUDE_POLYNOM_H_

#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;
class Monom;

class Polynom {
    using monom_vec = vector<Monom>;

 public:
     Polynom();
     explicit Polynom(double coff);
     Polynom(const Polynom& rhs);
     explicit Polynom(const string& str_poly);

     Polynom& operator=(const Polynom& z);

     void AddMonom(const Monom& m);
     string ToString();

     bool operator==(const Polynom& rhs) const;
     bool operator!=(const Polynom& rhs) const;

     Polynom operator+(const Polynom& rhs);
     Polynom operator-(const Polynom& rhs);
     Polynom operator*(const Polynom& rhs);
     Polynom operator/(const Monom& m);

     // Returns the map, where key is name, value should to fill user
     map<char, double> GetVarsList();

     // Accept map with filled values
     double CalculateResult(const map<char, double>& in_params);

 private:
     int Contains(const monom_vec& vec, const Monom& m) const;

 private:
     monom_vec m_monoms;
};
#endif  // MODULES_POLYNOMS_INCLUDE_POLYNOM_H_
