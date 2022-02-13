#ifndef BudgetManager_hpp
#define BudgetManager_hpp

#include <stdio.h>
#include <iostream>
#include "UserManager.hpp"
#include "ExpenseManager.hpp"


using namespace std;

class BudgetManager{
    
    UserManager userManager;
    ExpenseManager *expenseManager;
    const string EXPENSE_FILENAME;
  
public:
    
    BudgetManager(string userFilename, string expenseFilename) : userManager(userFilename), EXPENSE_FILENAME(expenseFilename)
    {
       expenseManager = NULL;
    };
    
   ~BudgetManager(){
       delete expenseManager;
        expenseManager = NULL;
    };
    
    

    void registerUser();
    void logInUser();
    void printAllUsers();
    void mainMenu();
    int getLoggedInUserId();
    void addExpense();
    void printAllExpenses();
    void printAllOperations();
    void printThisMonthsExpenseBalance();

};

#endif /* BudgetManager_hpp */
