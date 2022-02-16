#ifndef IncomeManager_hpp
#define IncomeManager_hpp


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "IncomeFile.hpp"
#include "UserManager.hpp"
#include "Income.hpp"
#include "SupportingMethods.hpp"
#include "DateManagement.hpp"

using namespace std;

class IncomeManager{

const int LOGGED_IN_USER_ID;
vector <Income> incomes;
int lastIncomeOperationId;
IncomeFile incomeFile;
DateManagement dateManagement;

Income inputNewIncome();

public:
    IncomeManager(int loggedInUserId, string incomeFilename) : LOGGED_IN_USER_ID(loggedInUserId), incomeFile(incomeFilename) {

    incomes = incomeFile.readIncomeOperationsFromFile(LOGGED_IN_USER_ID);

};

void addIncome();
void printAllIncomes();
vector <Income> readIncomeOperationsFromFile (int loggedInUserId);
int getLastIncomeOperationId();
int setLastIncomeOperationId();
int thisMonthsIncomeBalance();
int previousMonthsIncomeBalance();
vector <Income> SortIncomesByDate();
    int chosenPeriodIncomeBalance( int beginningDate, int endDate);
    
};

#endif /* IncomeManager_hpp */
