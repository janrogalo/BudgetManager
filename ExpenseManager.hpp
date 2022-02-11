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
#include "OperationFile.hpp"
#include "UserManager.hpp"
#include "Expense.hpp"
#include "SupportingMethods.hpp"




class ExpenseManager {

   const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
    int lastExpenseOperationId;
    
   Expense inputNewExpense();
    
public:
   ExpenseManager(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId){
       
   };
 
    void addExpense();
    void printAllExpenses();
    
};
#endif /* ExpenseManager_hpp */
