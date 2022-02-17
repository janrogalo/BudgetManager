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
    bool isDateValid = false;
    
    income.setIncomeOperationId(incomeFile.getlastIncomeOperationId()+1);
    income.setUserId(LOGGED_IN_USER_ID);
    cout << "Enter income category: " << endl;
    income.setType(SupportingMethods::inputLine());
    cout << "Enter amount: " << endl;
    income.setAmount(stod(SupportingMethods::convertComaToDot(SupportingMethods::inputLine())));
                     
                 
    cout << "Would you like to input operation with today's date? Y/N" << endl;
   
    if ((getchar() == 'y') ||  (getchar() == 'Y')){
        income.setDate(to_string(dateManagement.currentDate()));
    }
    else{
        while (isDateValid == false){
            cout << "Enter operation date in YYYY-MM-DD format: " << endl;
            string date = SupportingMethods::inputLine();
            date = SupportingMethods::convertDateToDigits(date);
            if (dateManagement.dateValidation(date)==true){
                isDateValid = true;
                income.setDate(date);}
            else cout << "Entered date is not valid. Try again!" << endl;
        }
    }
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

vector<Income> IncomeManager::sortIncomesByDate(){
    vector<Income>incomesCopy = incomes;
    sort(incomesCopy.begin(), incomesCopy.end());
    return incomesCopy;
}

void IncomeManager::printTotalIncome(vector <Income> &incomes, int i, double &incomeBalance){
    
    string date =  SupportingMethods::convertDateToFormat(incomes[i].getDate());
    cout << "Operation Date: " << date << endl;
    cout << "Income Operation Id: " << incomes[i].getIncomeOperationId()<<endl;
    cout << "Description: "<<  incomes[i].getType()<<endl;
    cout << "Amount: "<< incomes[i].getAmount()<<endl;
    cout << "-----";
    cout << endl;
    incomeBalance += incomes[i].getAmount();
}


double IncomeManager::thisMonthsIncomeBalance(){
    
    double incomesBalance = 0;
    vector <Income> incomesSorted = sortIncomesByDate();

    for (int i = 0; i < incomesSorted.size(); i++){
        if ((stoi(incomesSorted[i].getDate()) >= dateManagement.currentMonthBegining()) && (stoi(incomesSorted[i].getDate()) <= dateManagement.currentDate())){
            printTotalIncome( incomesSorted, i, incomesBalance);
        }
    }
    cout << endl << "Total income: " << incomesBalance << endl;
    return incomesBalance;
}

double IncomeManager::previousMonthsIncomeBalance(){
    
   double incomeBalance = 0;
    
    vector <Income> incomesSorted = sortIncomesByDate();
    for (int i = 0; i < incomesSorted.size(); i++){
        if ((stoi(incomesSorted[i].getDate()) >= dateManagement.previousMonthBeginning()) && (stoi(incomesSorted[i].getDate()) <= dateManagement.previousMonthEnd())){
            printTotalIncome( incomesSorted, i, incomeBalance);
        }
    }
    cout << endl << "Total income: " << incomeBalance << endl;
    return incomeBalance;
}

double IncomeManager::chosenPeriodIncomeBalance(int beginningDate, int endDate){
    
    double incomeBalance = 0;
    vector <Income> incomesSorted = sortIncomesByDate();
    
    for (int i = 0; i < incomesSorted.size(); i++){
        if ((stoi(incomesSorted[i].getDate()) >= beginningDate) && (stoi(incomesSorted[i].getDate()) <= endDate)){
            printTotalIncome( incomesSorted, i, incomeBalance);
        }
    }
    cout << endl << "Total income: " << incomeBalance << endl;
    return incomeBalance;
}

