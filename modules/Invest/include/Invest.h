// Copyright 2018 Churakov Sergey

#ifndef MODULES_INVEST_INCLUDE_INVEST_H_
#define MODULES_INVEST_INCLUDE_INVEST_H_
#include <vector>

typedef double money;
enum ERRORS {WRONG_VALUE};

class Investition{
 private:
    money* Incomes;
    money* Expenses;
    double RatePercent;
    int YearCount;

 public:
    Investition();
    Investition(const int& years, std::vector<money> Income_arr,
                std::vector<money> Expenses_arr, const double& rate);
    ~Investition();
    void SetRate(const double& rate);
    void SetYearCount(const int& years);
    void SetIncomes(std::vector<money> Income_arr);
    void SetExpenses(std::vector<money> Expenses_arr);
    int GetYearCount() const;
    double GetRate() const;
    money* GetIncomes() const;
    money* GetExpenses() const;
    money GetIncomeOfYear(const int& year) const;
    money GetExpenseOfYear(const int& year) const;
    double FindNPV() const;
    double FindNPV(const double& rate) const;
    double FindIRR() const;
    int FindRecoupmentTime() const;
    double FindPBIndex() const;
};

#endif  //  MODULES_INVEST_INCLUDE_INVEST_H_
