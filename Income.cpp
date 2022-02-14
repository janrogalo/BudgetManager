#include "Income.hpp"



void Income::setIncomeOperationId(int newvOperationId){
    incomeOperationId = newvOperationId;
}
void Income::setUserId(int newUserId){
    if (newUserId >= 0)
    userId = newUserId;
}
void Income::setDate(string newDate)
{
    date = newDate;
}
void Income::setAmount(int newAmount){
    amount = newAmount;
}
void Income::setType(string newType){
    type = newType;
}


int Income::getIncomeOperationId(){
    return incomeOperationId;
}

int Income::getUserId(){
    return userId;
}

string Income::getDate(){
    return date;
}

int Income::getAmount(){
    return amount;
}

string Income::getType(){
    return type;
}
