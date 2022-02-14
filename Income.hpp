#ifndef Income_hpp
#define Income_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Income{

    int incomeOperationId;
    int userId;
    string date;
    int amount;
    string type;
  

public:
    
    void setIncomeOperationId(int newIncomeOperationId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setAmount(int newAmount);
    void setType(string newType);
 
    int getIncomeOperationId();
    int getUserId();
    string getDate();
    int getAmount();
    string getType();
    
    bool operator< (const Income &other) const {
          return stoi(date) < stoi(other.date);
      }

};







#endif /* Income_hpp */
