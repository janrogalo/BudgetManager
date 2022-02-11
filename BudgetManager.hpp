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
  
    
public:
    
    BudgetManager(string userFilename) : userManager(userFilename)
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
    //void addOperation();
    void printAllOperations();

};

#endif /* BudgetManager_hpp */
