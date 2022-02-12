#include "ExpenseManager.hpp"

void ExpenseManager::addExpense(){
    Expense expense;

    cout << " >>> INPUT NEW EXPENSE <<<" << endl << endl;
    expense = inputNewExpense();
    expenses.push_back(expense);
    expenseFile.saveExpenseOperationToFile(expense);
    
}


Expense ExpenseManager::inputNewExpense(){

Expense expense;
    
expense.setExpenseOperationId(setLastExpenseOperationId());
expense.setUserId(LOGGED_IN_USER_ID);
cout << "Enter Type: " << endl;
expense.setType(SupportingMethods::inputLine());
cout << "Enter amount: " << endl;
expense.setAmount(stoi(SupportingMethods::inputLine()));
cout << "Set operation date: " << endl;
expense.setDate(SupportingMethods::inputLine());
    
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



int ExpenseManager::getLastExpenseOperationId(){
    return lastExpenseOperationId;
}

int ExpenseManager::setLastExpenseOperationId(){
    {
        if (expenses.empty() == true)
            return 1;
        else
            return expenses.back().getExpenseOperationId() + 1;
    }
}
