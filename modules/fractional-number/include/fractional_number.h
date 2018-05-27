//
//  fractional_number.h
//  fractional_number
//
//  Created by Aleksei Khomenko.
//  Copyright © 2018 Aleksei Khomenko. All rights reserved.
//

#ifndef MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_NUMBER_H_
#define MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_NUMBER_H_

class FractionalNumber {
 public:
FractionalNumber();
FractionalNumber(const int numerator, const int denominator);
FractionalNumber(const FractionalNumber& r);

FractionalNumber operator + (const FractionalNumber& s) const;
FractionalNumber operator - (const FractionalNumber& s) const;
FractionalNumber operator * (const FractionalNumber& s) const;
FractionalNumber operator / (const FractionalNumber& s) const;

FractionalNumber& operator= (const FractionalNumber& s);
bool operator == (const FractionalNumber& r) const;
bool operator != (const FractionalNumber& r) const;
int getNumerator() const;
int getDenominator() const;
void setNumerator(const int Numerator);
void setDenominator(const int Denominator);

 private:
int Nod(int, int) const;
int a, b;  // a-числитель b-знаменатель
};

#endif  // MODULES_FRACTIONAL_NUMBER_INCLUDE_FRACTIONAL_NUMBER_H_
