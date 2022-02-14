#ifndef ExpenseManager_hpp
#define ExpenseManager_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "ExpenseFile.hpp"
#include "UserManager.hpp"
#include "Expense.hpp"
#include "SupportingMethods.hpp"
#include "DateManagement.hpp"

class ExpenseManager {

    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    int lastExpenseOperationId;
    ExpenseFile expenseFile;
    DateManagement dateManagement;
    
   Expense inputNewExpense();
    
public:
   ExpenseManager(int loggedInUserId, string expenseFilename) : LOGGED_IN_USER_ID(loggedInUserId), expenseFile(expenseFilename) {
    
       expenses = expenseFile.readExpenseOperationsFromFile(LOGGED_IN_USER_ID);
    
   };
 
  
    
    
    
    void addExpense();
    void printAllExpenses();
    vector <Expense> readExpenseOperationsFromFile (int loggedInUserId);
    int getLastExpenseOperationId();
    int setLastExpenseOperationId();
    void thisMonthsBalance();
    vector <Expense> SortExpensesByDate();
        
    
};
#endif /* ExpenseManager_hpp */
