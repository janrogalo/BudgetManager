#include "ExpenseManager.hpp"

void ExpenseManager::addExpense(){

    Expense expense;

    cout << " >>> INPUT NEW EXPENSE <<<" << endl << endl;
    expense = inputNewExpense();
    cout << expenses.size() << "TYLE" << endl;
    expenses.push_back(expense);
}


Expense ExpenseManager::inputNewExpense(){

Expense expense;
    
expense.setExpenseOperationId(666);
expense.setUserId(2);
cout << "Enter Type: " << endl;
expense.setType("POWER");
cout << "Enter amount: " << endl;
expense.setAmount(123);
cout << "Set operation date: " << endl;
expense.setDate("DATE");
    
return expense;
}

void ExpenseManager::printAllExpenses(){
    for(int i=0; i <  expenses.size(); i++){
        cout << expenses[i].getExpenseOperationId()<<endl;
        cout << expenses[i].getUserId()<<endl;
        cout << expenses[i].getType()<<endl;
        cout << expenses[i].getAmount()<<endl;
        cout << expenses[i].getDate()<<endl;
    }
}
