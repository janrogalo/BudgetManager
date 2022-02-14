#include "IncomeManager.hpp"

void IncomeManager::addIncome(){
    Income income;
    
    cout << " >>> INPUT NEW Income<<<" << endl << endl;
   income = inputNewIncome();
    incomes.push_back(income);
    incomeFile.saveIncomeOperationToFile(income);
    
}


Income IncomeManager::inputNewIncome(){
    
    Income income;
    
    income.setIncomeOperationId(incomeFile.getlastIncomeOperationId()+1);
    income.setUserId(LOGGED_IN_USER_ID);
    cout << "Enter income category: " << endl;
    income.setType(SupportingMethods::inputLine());
    cout << "Enter amount: " << endl;
    income.setAmount(stoi(SupportingMethods::inputLine()));
    cout << "Enter operation date in YYYY-MM-DD format: " << endl;
    string date = SupportingMethods::inputLine();
    income.setDate(SupportingMethods::convertDateToDigits(date));
    
    return income;
}

void IncomeManager::printAllIncomes(){
    for(int i=0; i <  incomes.size(); i++){
        cout << incomes[i].getIncomeOperationId()<<endl;
        cout << incomes[i].getUserId()<<endl;
        cout << incomes[i].getType()<<endl;
        cout << incomes[i].getAmount()<<endl;
        cout << incomes[i].getDate()<<endl;
    }
}



int IncomeManager::getLastIncomeOperationId(){
    return lastIncomeOperationId;
}

int IncomeManager::setLastIncomeOperationId(){
    {
        if (incomes.empty() == true)
            return 1;
        else
            return incomes.back().getIncomeOperationId() + 1;
    }
}


vector<Income> IncomeManager::SortIncomesByDate(){
    vector<Income>incomesCopy = incomes;
    sort(incomesCopy.begin(), incomesCopy.end());
    return incomesCopy;
}


void IncomeManager::thisMonthsIncomeBalance(){
    
    int incomesBalance = 0;
    
    
    vector <Income> incomesSorted = SortIncomesByDate();
    
    for (int i = 0; i < incomesSorted.size(); i++){
        
        if ((stoi(incomesSorted[i].getDate()) >= dateManagement.currentMonthBegining()) && (stoi(incomesSorted[i].getDate()) <= dateManagement.currentDate())){
            cout << incomesSorted[i].getIncomeOperationId()<<endl;
            cout << incomesSorted[i].getType()<<endl;
            cout << incomesSorted[i].getAmount()<<endl;
            
            string date =  SupportingMethods::convertDateToFormat(incomesSorted[i].getDate());
            cout << date << endl;
            
            incomesBalance += incomesSorted[i].getAmount();
        }
    }
    cout << "This month you spent: " << incomesBalance << endl;
}

void IncomeManager::previousMonthsIncomeBalance(){
    
    int incomeBalance = 0;
    
    
    vector <Income> incomesSorted = SortIncomesByDate();
    
    for (int i = 0; i < incomesSorted.size(); i++){
        
        if ((stoi(incomesSorted[i].getDate()) >= dateManagement.previousMonthBeginning()) && (stoi(incomesSorted[i].getDate()) <= dateManagement.previousMonthEnd())){
            cout << incomesSorted[i].getIncomeOperationId()<<endl;
            cout << incomesSorted[i].getType()<<endl;
            cout << incomesSorted[i].getAmount()<<endl;
            
            string date =  SupportingMethods::convertDateToFormat(incomesSorted[i].getDate());
            cout << date << endl;
            
            incomeBalance += incomesSorted[i].getAmount();
        }
    }
    cout << "Last month you spent: " << incomeBalance << endl;
}


void IncomeManager::chosenPeriodIncomeBalance(){
    
    int incomeBalance = 0;
    vector <Income> incomesSorted = SortIncomesByDate();
    
    cout << "Input beginning date in YYYY-MM-DD format: " << endl;
    int beginningDate = stoi(SupportingMethods::convertDateToDigits(SupportingMethods::inputLine()));
    cout << "Input ending date in YYYY-MM-DD format: " << endl;
    int endingDate = stoi(SupportingMethods::convertDateToDigits(SupportingMethods::inputLine()));
    
    
    for (int i = 0; i < incomesSorted.size(); i++){
        if ((stoi(incomesSorted[i].getDate()) >= beginningDate) && (stoi(incomesSorted[i].getDate()) <= endingDate)){
            cout << incomesSorted[i].getIncomeOperationId()<<endl;
            cout << incomesSorted[i].getType()<<endl;
            cout << incomesSorted[i].getAmount()<<endl;
            
            string date =  SupportingMethods::convertDateToFormat(incomesSorted[i].getDate());
            cout << date << endl;
            
            incomeBalance += incomesSorted[i].getAmount();
        }
    }
    cout << "Between" << SupportingMethods::convertDateToFormat(to_string(beginningDate)) << " and " << SupportingMethods::convertDateToFormat(to_string(beginningDate))  << " you spent " << incomeBalance << endl;
}

