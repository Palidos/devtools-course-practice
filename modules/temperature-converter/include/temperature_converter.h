// Copyright 2018 Bederdinov Daniil

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_

class TemperatureConverter {
 public:
  TemperatureConverter(double current_temperature_ = 0,
       char current_scale_ = 'C');
  /* TemperatureConverter(const TemperatureConverter& temp) :
      current_temperature(temp.current_temperature),
      current_scale(temp.current_scale) {} */

  TemperatureConverter convert(TemperatureConverter temperature,
      char new_scale);
  double getCurrentTemperature();
  // void setCurrentTemperature(double current_temperature_);
  TemperatureConverter & operator=(const TemperatureConverter &temp);

 private:
  double current_temperature;
  char current_scale;
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_H_
