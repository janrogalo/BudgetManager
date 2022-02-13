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
    
expense.setExpenseOperationId(expenseFile.getlastExpenseOperationId()+1);
expense.setUserId(LOGGED_IN_USER_ID);
cout << "Enter expense category: " << endl;
expense.setType(SupportingMethods::inputLine());
cout << "Enter amount: " << endl;
expense.setAmount(stoi(SupportingMethods::inputLine()));
cout << "Enter operation date in YYYY-MM-DD format: " << endl;
    string date = SupportingMethods::inputLine();
expense.setDate(SupportingMethods::convertDateToDigits(date));
    
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

void ExpenseManager::thisMonthsBalance(){
   
    int expenseBalance = 0;
    cout <<dateManagement.currentMonthBegining() << endl;
    cout <<dateManagement.currentDate()<< endl;
    
    for (int i = 0; i < expenses.size(); i++){

        if ((stoi(expenses[i].getDate()) >= dateManagement.currentMonthBegining()) && (stoi(expenses[i].getDate()) <= dateManagement.currentDate())){
            cout << expenses[i].getExpenseOperationId()<<endl;
            cout << expenses[i].getType()<<endl;
            cout << expenses[i].getAmount()<<endl;
            
            string date =  SupportingMethods::convertDateToFormat(expenses[i].getDate());
            cout << date << endl;
            
            expenseBalance += expenses[i].getAmount();
        }
    }
    
    cout << "This month you spent: " << expenseBalance << endl;
}

vector <Expense> ExpenseManager::sortExpenses()
{
    return expenses;
}



