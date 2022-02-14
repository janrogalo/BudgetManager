#ifndef BudgetManager_hpp
#define BudgetManager_hpp

#include <stdio.h>
#include <iostream>
#include "UserManager.hpp"
#include "ExpenseManager.hpp"
#include "IncomeManager.hpp"


using namespace std;

class BudgetManager{
    
    UserManager userManager;
    ExpenseManager *expenseManager;
    IncomeManager *incomeManager;
    const string EXPENSE_FILENAME;
    const string INCOME_FILENAME;
  
public:
    
    BudgetManager(string userFilename, string expenseFilename, string incomeFilename) : userManager(userFilename), EXPENSE_FILENAME(expenseFilename), INCOME_FILENAME(incomeFilename)
    {
       expenseManager = NULL;
        incomeManager = NULL;
    };
    
   ~BudgetManager(){
       delete expenseManager;
        expenseManager = NULL;
       delete incomeManager;
       incomeManager = NULL;
    };
    
    ;
    void registerUser();
    void logInUser();
    void printAllUsers();
    void mainMenu();
    int getLoggedInUserId();
    void addExpense();
    void printAllExpenses();
    void printThisMonthsExpenseBalance();
    void printPreviousMonthsExpenseBalance();
    void printchosenPeriodExpenseBalance();
    
    void addIncomes();
    void printAllIncomes();
    void printThisMonthsIncomeBalance();
    void printPreviousMonthsIncomeBalance();
    void printchosenPeriodIncomeBalance();

};

#endif /* BudgetManager_hpp */
