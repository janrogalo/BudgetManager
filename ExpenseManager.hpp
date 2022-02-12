//
//  ExpenseManager.hpp
//  XML_Proby
//
//  Created by Jan Rogalo on 11/02/2022.
//

#ifndef ExpenseManager_hpp
#define ExpenseManager_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "ExpenseFile.hpp"
#include "UserManager.hpp"
#include "Expense.hpp"
#include "SupportingMethods.hpp"




class ExpenseManager {

    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    int lastExpenseOperationId;
    ExpenseFile expenseFile;
    
   Expense inputNewExpense();
    
public:
   ExpenseManager(int loggedInUserId, string expenseFilename) : LOGGED_IN_USER_ID(loggedInUserId), expenseFile(expenseFilename) {
       
       cout << "OBIEKT STWORZONY" << endl;
       expenses = expenseFile.readExpenseOperationsFromFile(LOGGED_IN_USER_ID);
       printAllExpenses();
   };
 
    void addExpense();
    void printAllExpenses();
    vector <Expense> readExpenseOperationsFromFile (int loggedInUserId);
    int getLastExpenseOperationId();
    int setLastExpenseOperationId();
};
#endif /* ExpenseManager_hpp */
