#include "BudgetManager.hpp"

void BudgetManager::registerUser(){
    userManager.registerUser();
}

void BudgetManager::printAllUsers(){
    userManager.printAllUsers();
}

void BudgetManager::changePassword(){
    userManager.changePassword();
}

void BudgetManager::logout(){
    userManager.logout();
}
void BudgetManager::logInUser(){
    userManager.loginUser();
    if (userManager.isUserLoggedIn() == true){
        expenseManager = new ExpenseManager(getLoggedInUserId(), "expense.xml");
        incomeManager = new IncomeManager(getLoggedInUserId(), "income.xml");
    }
}

void BudgetManager::mainMenu(){
    
    cout << endl << "Welcome to Budget Manager" << endl;
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << endl << "   >>> MAIN MENU <<<    " << endl;
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << "1. Register User" << endl;
    cout << "2. Login" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}

void BudgetManager::userMenu(){
    
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << endl << "   >>> USER MENU<<<    " << endl;
    cout << "-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
    cout << "1. Add Income" << endl;
    cout << "2. Add Expense" << endl;
    cout << "3. Print current month's balance" << endl;
    cout << "4. Print last month's balance" << endl;
    cout << "5. Print user-defined period balance" << endl;
    cout << "6. Change user password" << endl;
    cout << "7. Logout" << endl;
    cout << "9. Quit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
}


int BudgetManager::getLoggedInUserId(){
    return userManager.getLoggedinUserId();
}

void BudgetManager::addExpense(){
    expenseManager ->addExpense();
}

void BudgetManager::addIncomes(){
    incomeManager ->addIncome();
}

void BudgetManager::thisMonthsBalance(){
    
    cout << "<<< THIS MONTH'S BALANCE >>>" << endl << endl;
    cout << "Your income operations: " << endl;
    double income = incomeManager ->thisMonthsIncomeBalance();
    
    
    cout << endl << "Your expense operations: " << endl;
    double expense = expenseManager ->thisMonthsExpenseBalance();
    cout << "---------------------------------------" << endl;
    
    if (income > expense){
        cout << "This month you saved: " << income-expense << " - congratulations!" << endl;
    }
    else if ( expense > income){
        cout << "This month your savings diminished by: " << expense - income << " - be careful about spending!" << endl;
        
    }
    else {
        cout << "Your savings remained the same!" << endl;
    }
}

void BudgetManager::lastMonthsBalance(){
    
    cout << "<<< PREVIOUS MONTH'S BALANCE >>>" << endl << endl;
    cout << "Your income operations: " << endl;
    double income = incomeManager ->previousMonthsIncomeBalance();
    
    
    cout << endl << "Your expense operations: " << endl;
    double expense = expenseManager ->previousMonthsExpenseBalance();
    cout << "---------------------------------------" << endl;
    
    if (income > expense){
        cout << "Last month you saved: " << income-expense << " - congratulations!" << endl;
    }
    else if ( expense > income){
        cout << "Last month your savings diminished by: " << expense - income << " - be careful about spending!" << endl;
    }
    else {
        cout << "Your savings remained the same!" << endl;
    }
}

void BudgetManager::chosenPeriodBalance(){
    
    bool isBeginningDateValid = false;
    bool isEndingDateValid = false;
    int beginningDate=0, endingDate=0;
    
    
    while (isBeginningDateValid == false){
        cout << "Input beginning date in YYYY-MM-DD format: " << endl;
        beginningDate = stoi(SupportingMethods::convertDateToDigits(SupportingMethods::inputLine()));
        if ((DateManagement::dateValidation(to_string(beginningDate)) == true)){
            isBeginningDateValid = true; }
        
        
        while (isEndingDateValid == false){
            cout << "Input ending date in YYYY-MM-DD format: " << endl;
            endingDate = stoi(SupportingMethods::convertDateToDigits(SupportingMethods::inputLine()));
            if ((DateManagement::dateValidation(to_string(endingDate)) == true)){
                isEndingDateValid = true; }
            
        }
        cout<< "<<< BALANCE BETWEEN ";
        cout<< SupportingMethods::convertDateToFormat(to_string(beginningDate));
        cout<< " AND " << SupportingMethods::convertDateToFormat(to_string(endingDate));
        cout<<" >>> " << endl << endl;
        
        cout << "Your income operations: " << endl;
        double income = incomeManager ->chosenPeriodIncomeBalance(beginningDate, endingDate);
        
        cout << endl << "Your expense operations: " << endl;
        double expense = expenseManager ->chosenPeriodExpenseBalance(beginningDate, endingDate);
        cout << "---------------------------------------" << endl;
        
        if (income > expense){
            cout << "In this period you saved: " << income-expense << " - congratulations!" << endl;
        }
        else if ( expense > income){
            cout << "In this period your savings diminished by: " << expense - income << " - be careful about spending!" << endl;
        }
        else {
            cout << "Your savings remained the same!" << endl;
        }
    }
}


