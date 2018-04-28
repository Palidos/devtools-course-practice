// Copyright 2018 Bederdinov Daniil

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#include <iostream>

class TemperatureConverter {
 public:
  TemperatureConverter() {}
  ~TemperatureConverter() {}

  double kelToCel(double kel);
  double kelToFahr(double kel);
  double kelToNewt(double kel);
  double celToKel(double cel);
  double celToFahr(double cel);
  double celToNewt(double cel);
  double fahrToCel(double fahr);
  double fahrToKel(double fahr);
  double fahrToNewt(double fahr);
  double newtToCel(double newt);
  double newtToKel(double newt);
  double newtToFahr(double newt);
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
