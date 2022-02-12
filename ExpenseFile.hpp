//
//  ExpenseFile.hpp
//  XML_Proby
//
//  Created by Jan Rogalo on 11/02/2022.
//

#ifndef ExpenseFile_hpp
#define ExpenseFile_hpp

#include <stdio.h>
#include <vector>
#include "Expense.hpp"
#include "XMLFile.hpp"

class ExpenseFile : public XMLFile {
    
    int lastExpenseOperationId;
    int loggedInUserId;
    
    Expense getExpenseData();
    
public:
    ExpenseFile(string filename) : XMLFile(filename)
    {
        lastExpenseOperationId = 0;
    };
    
    bool saveExpenseOperationToFile(Expense expense);
    vector <Expense> readExpenseOperationsFromFile (int loggedInUserId);
    int getlastExpenseOperationId();
    
};





#endif /* ExpenseFile_hpp */
