// Copyright 2018 Sharov Ivan

#ifndef MODULES_WAGES_INCLUDE_WAGES_H_
#define MODULES_WAGES_INCLUDE_WAGES_H_

typedef enum {  // for months
    January = 1, February, March, April, May, June,
    July, August, September, October, November, December
} Month;

class Wages {
 public:
    Wages();
    Wages(const double salary, const double administrativeLeaveHours,
    const double overtime, Month month);  // constructor with parameters
    Wages(const Wages& wages);  // copy constructor

    // methods for initializing class fields
    double getSalary() const;
    double getAdministrativeLeaveHours() const;
    double getOvertime() const;
    Month getMonth() const;

    // methods for accessing class fields
    void setSalary(const double salary);
    void setAdministrativeLeaveHours(const double administrativeLeaveHours);
    void setOvertime(const double overtime);
    void setMonth(Month month);

    // methods for controlling class fields
    bool controlMROT(const double field);
    bool controlField(const double field);
    void controlOvertime(const double overtime);
    void controlAdministrativeLeaveHours(const double administrativeLeaveHours);

    // methods for calculating
    double getNumberWorkingDaysInCurrentMonth();
    double calculationPaymentOvertime();
    double calculationActualWorkingDays();
    double calculationWagesWithoutOvertime();
    double calculationFullWages();
    double calculationHourPayment();

 private:
    double salary_;  // basic salary
    double administrativeLeaveHours_;  // number of administrative hours
    double overtime_;  // number of overtime hours
    Month current_month_;  // name of the month
};

#endif   //  MODULES_WAGES_INCLUDE_WAGES_H_
