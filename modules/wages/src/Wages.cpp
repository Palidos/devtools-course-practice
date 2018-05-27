// Copyright 2018 Sharov Ivan

#include"include/Wages.h"
#include<string.h>
#include <string>

Wages::Wages() : salary_(10000), administrativeLeaveHours_(0),
    overtime_(0), current_month_(January) {}

Wages::Wages(const double salary, const double administrativeLeaveHours,
    const double overtime, Month month) {
    setSalary(salary);
    setAdministrativeLeaveHours(administrativeLeaveHours);
    setOvertime(overtime);
    setMonth(month);
}

Wages::Wages(const Wages& wages) : salary_(wages.getSalary()),
    administrativeLeaveHours_(wages.getAdministrativeLeaveHours()),
    overtime_(wages.getOvertime()), current_month_(wages.getMonth()) {}

double Wages::getSalary() const {
    return salary_;
}

double Wages::getAdministrativeLeaveHours() const {
    return administrativeLeaveHours_;
}

double Wages::getOvertime() const {
    return overtime_;
}

Month Wages::getMonth() const {
    return current_month_;
}

void Wages::setSalary(const double salary) {
    bool control;
    control = controlMROT(salary);
    if (control == true) salary_ = salary;
    else
        throw std::string("The salary can not be less than the minimum wage!");
}

void Wages::setAdministrativeLeaveHours(const double administrativeLeaveHours) {
    bool control;
    control = controlField(administrativeLeaveHours);
    if (control == true) administrativeLeaveHours_ = administrativeLeaveHours;
    else
        throw std::string("Administrative leave hours can not be negative!");
}

void Wages::setOvertime(const double overtime) {
    bool control;
    control = controlField(overtime);
    if (control == true) overtime_ = overtime;
    else
        throw std::string("Overtime leave hours can not be negative!");
}


void Wages::setMonth(Month month) {
    current_month_ = month;
}

bool Wages::controlField(const double field) {
    bool result = true;
    if (field < 0) result = false;
    return result;
}

bool Wages::controlMROT(const double field) {
    bool result = true;
    if (field < 9489) result = false;
    return result;
}

void Wages::controlOvertime(const double overtime) {
    int workDays = static_cast<int>(calculationActualWorkingDays());
    if (overtime > 3 * (static_cast<double>(workDays)))
        throw std::string("Exceeded the maximum number of overtime in month");
}

void Wages::
    controlAdministrativeLeaveHours(const double administrativeLeaveHours) {
    double workDays = getNumberWorkingDaysInCurrentMonth();
    if (administrativeLeaveHours > 8 * workDays)
       throw std:: string("Exceeding the administrative hours limit");
}

double Wages::getNumberWorkingDaysInCurrentMonth() {
    double result;
    Month month = getMonth();
    switch (month) {
    case January: {
        result = 17;
        break;
    }
    case February: {
        result = 19;
        break;
    }
    case March: {
        result = 20;
        break;
    }
    case April: {
        result = 21;
        break;
    }
    case May: {
        result = 20;
        break;
    }
    case June: {
        result = 20;
        break;
    }
    case July: {
        result = 22;
        break;
    }
    case August: {
        result = 23;
        break;
    }
    case September: {
        result = 20;
        break;
    }
    case October: {
        result = 23;
        break;
    }
    case November: {
        result = 21;
        break;
    }
    case December: {
        result = 21;
        break;
    }
    }
    return result;
}

double Wages::calculationPaymentOvertime() {
    double result, hours, hourPayment;
    hours = getOvertime();
    controlOvertime(hours);
    hourPayment = calculationHourPayment();
    if (hours < 3) {
        result = 1.5 * hourPayment*hours;
    } else {
        double hours2Payment = hours - 2;
        result = 1.5 * hourPayment* 2.0 + 2.0 * hourPayment*hours2Payment;
    }

    return result;
}

double Wages::calculationActualWorkingDays() {
    double result, daysInMonth, hoursInAdministrativeLeave, workHours;
    daysInMonth = getNumberWorkingDaysInCurrentMonth();
    hoursInAdministrativeLeave = getAdministrativeLeaveHours();
    controlAdministrativeLeaveHours(hoursInAdministrativeLeave);
    workHours = 8 * daysInMonth - hoursInAdministrativeLeave;
    result = workHours / 8;
    return result;
}

double Wages::calculationWagesWithoutOvertime() {
    double result, workDays, daysInMonth, hoursInAdministrativeLeave, Salary;
    daysInMonth = getNumberWorkingDaysInCurrentMonth();
    hoursInAdministrativeLeave = getAdministrativeLeaveHours();
    controlAdministrativeLeaveHours(hoursInAdministrativeLeave);
    workDays = calculationActualWorkingDays();
    Salary = getSalary();
    result = Salary*(workDays / daysInMonth);
    return result;
}

double Wages::calculationFullWages() {
    double result, wagesWithoutOvertime, paymentOvertime;
    wagesWithoutOvertime = calculationWagesWithoutOvertime();
    paymentOvertime = calculationPaymentOvertime();
    result = wagesWithoutOvertime + paymentOvertime;
    return result;
}

double Wages::calculationHourPayment() {
    double Salary, Days, result;
    Salary = getSalary();
    Days = getNumberWorkingDaysInCurrentMonth();
    result = Salary / (8 * Days);
    return result;
}
