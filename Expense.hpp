#ifndef Expense_hpp
#define Expense_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Expense{

    int expenseOperationId;
    int userId;
    string date;
    double amount;
    string type;
  
public:
    
    void setExpenseOperationId(int newExpenseOperationId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setAmount(double newAmount);
    void setType(string newType);
 
    int getExpenseOperationId();
    int getUserId();
    string getDate();
    double getAmount();
    string getType();
    
    bool operator< (const Expense &other) const {
          return stoi(date) < stoi(other.date);
      }
};

#endif /* Expense_hpp */
