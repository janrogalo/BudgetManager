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
    
    vector <Expense> expensesSorted = SortExpensesByDate();
    
    for (int i = 0; i < expensesSorted.size(); i++){

        if ((stoi(expensesSorted[i].getDate()) >= dateManagement.currentMonthBegining()) && (stoi(expensesSorted[i].getDate()) <= dateManagement.currentDate())){
            cout << expensesSorted[i].getExpenseOperationId()<<endl;
            cout << expensesSorted[i].getType()<<endl;
            cout << expensesSorted[i].getAmount()<<endl;
            
            string date =  SupportingMethods::convertDateToFormat(expensesSorted[i].getDate());
            cout << date << endl;
            
            expenseBalance += expensesSorted[i].getAmount();
        }
    }
    cout << "This month you spent: " << expenseBalance << endl;
}


vector<Expense> ExpenseManager::SortExpensesByDate(){
vector<Expense>expensesCopy = expenses;
sort(expensesCopy.begin(), expensesCopy.end());
return expensesCopy;
}
    

