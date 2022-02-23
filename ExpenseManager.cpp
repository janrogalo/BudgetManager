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
    bool isDateValid = false;
    cin.ignore();
    expense.setExpenseOperationId(expenseFile.getlastExpenseOperationId()+1);
    expense.setUserId(LOGGED_IN_USER_ID);

    cout << "Enter expense category: " << endl;
    expense.setType(SupportingMethods::inputLine());
    cout << "Enter amount: " << endl;
    expense.setAmount(stod(SupportingMethods::convertComaToDot( SupportingMethods::inputLine())));
                 
    cout << "Would you like to input operation with today's date? Y/N" << endl;
    
    char choice = getchar();
    if ((choice == 'y') ||  (choice == 'Y')){
        expense.setDate(to_string(dateManagement.currentDate()));
    }
    else{
        while (isDateValid == false){
            cout << "Enter operation date in YYYY-MM-DD format: " << endl;
            string date = SupportingMethods::inputLine();
            date = SupportingMethods::convertDateToDigits(date);
            if (dateManagement.dateValidation(date)==true){
                isDateValid = true;
               expense.setDate(date);}
            else cout << "Entered date is not valid. Try again!" << endl;
        }
    }
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


vector<Expense> ExpenseManager::SortExpensesByDate(){
    vector<Expense>expensesCopy = expenses;
    sort(expensesCopy.begin(), expensesCopy.end());
    return expensesCopy;
}


void ExpenseManager::printTotalExpense(vector <Expense> &expenses, int i, double &expenseBalance){
    
    string date =  SupportingMethods::convertDateToFormat(expenses[i].getDate());
    cout << "Operation Date: " << date << endl;
    cout << "Expense Operation Id: " << expenses[i].getExpenseOperationId()<<endl;
    cout << "Description: "<<  expenses[i].getType()<<endl;
    cout << "Amount: "<< expenses[i].getAmount()<<endl;
    cout << "-----";
    cout << endl;
    expenseBalance += expenses[i].getAmount();
}

double ExpenseManager::thisMonthsExpenseBalance(){
    
    double expenseBalance = 0;
    vector <Expense> expensesSorted = SortExpensesByDate();
    
    for (int i = 0; i < expensesSorted.size(); i++){
        if ((stoi(expensesSorted[i].getDate()) >= dateManagement.currentMonthBegining()) && (stoi(expensesSorted[i].getDate()) <= dateManagement.currentDate())){
           printTotalExpense(expensesSorted, i, expenseBalance);
        }
    }
    cout << endl << "Total expense: " << expenseBalance << endl;
    return expenseBalance;
}

double ExpenseManager::previousMonthsExpenseBalance(){
    
    double expenseBalance = 0;
    vector <Expense> expensesSorted = SortExpensesByDate();
    
    for (int i = 0; i < expensesSorted.size(); i++){
        if ((stoi(expensesSorted[i].getDate()) >= dateManagement.previousMonthBeginning()) && (stoi(expensesSorted[i].getDate()) <= dateManagement.previousMonthEnd())){
            printTotalExpense(expensesSorted, i, expenseBalance);
        }
    }
    cout << endl << "Total expense: " << expenseBalance << endl;
    return expenseBalance;
}

double ExpenseManager::chosenPeriodExpenseBalance(int beginningDate, int endDate){
    
    double expenseBalance = 0;
    vector <Expense> expensesSorted = SortExpensesByDate();
    
    for (int i = 0; i < expensesSorted.size(); i++){
        if ((stoi(expensesSorted[i].getDate()) >= beginningDate) && (stoi(expensesSorted[i].getDate()) <= endDate)){
            printTotalExpense(expensesSorted, i, expenseBalance);
        }
    }
    cout << endl << "Total expense: " << expenseBalance << endl;
    return expenseBalance;
}
























