#ifndef ExpenseFile_hpp
#define ExpenseFile_hpp

#include <stdio.h>
#include <vector>
#include "Expense.hpp"
#include "XMLFile.hpp"
#include "SupportingMethods.hpp"

class ExpenseFile : public XMLFile {
    
    int lastExpenseOperationId;
    int loggedInUserId;
    SupportingMethods supportinMethods;
    
    Expense getExpenseData();
    
public:
    ExpenseFile(string filename) : XMLFile(filename)
    {
        lastExpenseOperationId = getlastExpenseOperationId();
    };
    
    bool saveExpenseOperationToFile(Expense expense);
    vector <Expense> readExpenseOperationsFromFile (int loggedInUserId);
    int getlastExpenseOperationId();
    
};





#endif /* ExpenseFile_hpp */
