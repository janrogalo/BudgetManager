#include "Expense.hpp"


void Expense::setExpenseOperationId(int newExpenseOperationId){
    expenseOperationId = newExpenseOperationId;
}
void Expense::setUserId(int newUserId){
    if (newUserId >= 0)
    userId = newUserId;
}
void Expense::setDate(string newDate)
{
    date = newDate;
}
void Expense::setAmount(int newAmount){
    amount = newAmount;
}
void Expense::setType(string newType){
    type = newType;
}


int Expense::getExpenseOperationId(){
    return expenseOperationId;
}

int Expense::getUserId(){
    return userId;
}

string Expense::getDate(){
    return date;
}

int Expense::getAmount(){
    return amount;
}

string Expense::getType(){
    return type;
}
