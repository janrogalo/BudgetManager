#ifndef Expense_hpp
#define Expense_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Expense{

    int expenseOperationId;
    int userId;
    string date;
    int amount;
    string type;
  
public:
    
    void setExpenseOperationId(int newExpenseOperationId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setAmount(int newAmount);
    void setType(string newType);
 
    int getExpenseOperationId();
    int getUserId();
    string getDate();
    int getAmount();
    string getType();
 
  
};

#endif /* Expense_hpp */
