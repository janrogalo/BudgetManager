#ifndef BudgetManager_hpp
#define BudgetManager_hpp

#include <stdio.h>
#include <iostream>
#include "UserManager.hpp"
#include "ExpenseManager.hpp"
#include "IncomeManager.hpp"
#include "DateManagement.hpp"


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
    void userMenu();
    int getLoggedInUserId();
    void changePassword();
    void logout();
    void addExpense();
    void addIncomes();
    void thisMonthsBalance();
    void lastMonthsBalance();
    void chosenPeriodBalance();
    


};

#endif /* BudgetManager_hpp */
