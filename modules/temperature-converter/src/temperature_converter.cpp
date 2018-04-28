// Copyright 2018 Bederdinov Daniil

#include "include/temperature_converter.h"

double TemperatureConverter::kelToCel(double kel) {
    return kel - 273.15;
}

double TemperatureConverter::kelToFahr(double kel) {
    return (9.0 / 5) * (kel - 273.15) + 32;
}

double TemperatureConverter::kelToNewt(double kel) {
    return (kel - 273.15) * 0.33;
}

double TemperatureConverter::celToKel(double cel) {
    return cel + 273.15;
}

double TemperatureConverter::celToFahr(double cel) {
    return cel * (9.0 / 5) + 32;
}

double TemperatureConverter::celToNewt(double cel) {
    return cel * 0.33;
}

double TemperatureConverter::fahrToCel(double fahr) {
    return (5.0 / 9) * (fahr - 32);
}

double TemperatureConverter::fahrToKel(double fahr) {
    return  (5.0 / 9) * (fahr - 32) + 273.15;
}

double TemperatureConverter::fahrToNewt(double fahr) {
    return (fahr - 32) * 0.183333;
}

double TemperatureConverter::newtToCel(double newt) {
    return newt * 3.030303;
}

double TemperatureConverter::newtToKel(double newt) {
    return newt * 3.030303 + 273.15;
}

double TemperatureConverter::newtToFahr(double newt) {
    return newt * 5.454545 + 32;
}
