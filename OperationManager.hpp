//
//  OperationManager.hpp
//  XML_Proby
//
//  Created by Jan Rogalo on 10/02/2022.
//

#ifndef OperationManager_hpp
#define OperationManager_hpp


#include <stdio.h>
#include <iostream>
#include <vector>
#include "OperationFile.hpp"
#include "User.hpp"
#include "Expense.hpp"




class ExpenseManager{

    const int LOGGED_IN_USER_ID;
    vector <Expense> expenses;
   
    
    int lastExpenseOperationId;

    
    
    
};
    
    /*
    const int LOGGED_USER_ID;
    vector <Operation> operations;
    int lastOperationId;
    OperationFile operationFile;
    
    Operation inputNewOperation();
    
public:
 

    OperationManager(string OperationFilename, int loggedInUserId) : operationFile(OperationFilename), LOGGED_USER_ID(loggedInUserId) {
        operations=operationFile.getOperationData(loggedInUserId);
    };
    
    
    
    void addOperation();
    void printAllOperations();



*/

#endif /* OperationManager_hpp */
