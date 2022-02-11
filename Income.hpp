#ifndef Income_hpp
#define Income_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class Income{

    int incomeOperationId;
    int userId;
    int amount;
    string date;
   

public:
    
    void setIncomeOperationId(int newIncomeOperationId);
    void setUserId(int newUserId);
    void setAmount(int newAmount);
    void setDate(string newDate);
 
    int getIncomeOperationId();
    int getUserId();
    int getAmount();
    string getDate();

  
};







#endif /* Income_hpp */
