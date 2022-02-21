#include <iostream>

#include "BudgetManager.hpp"

using namespace std;

int main(){
    BudgetManager budgetManager("user.xml", "expense.xml", "income.xml"); 
    int loggedInUserId = 0;

    budgetManager.printAllUsers();
    
    do{
        char menuChoice;
        if (loggedInUserId == 0){
            budgetManager.mainMenu();
            menuChoice = getchar();
            switch (menuChoice)
            {
                case '1':
                    budgetManager.registerUser();
                    break;
                case '2':
                    budgetManager.logInUser();
                    loggedInUserId = budgetManager.getLoggedInUserId();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Please make another choice." << endl << endl;
                    break;
            }
            if (loggedInUserId != 0){
                budgetManager.userMenu();
                menuChoice = getchar();
                switch (menuChoice)
                {
                    case '1':
                        budgetManager.addIncomes();
                        break;
                    case '2':
                        budgetManager.addExpense();
                        break;
                    case '3':
                        budgetManager.thisMonthsBalance();
                        break;
                    case '4':
                        budgetManager.lastMonthsBalance();
                        break;
                    case '5':
                        budgetManager.chosenPeriodBalance();
                        break;
                    case '6':
                        budgetManager.changePassword();
                        break;
                    case '7':
                        budgetManager.logout();
                        loggedInUserId = 0;
                        break;
                    case '9':
                        exit(0);
                        break;
                }
                
            }
        }
       
}
    while (true);
}

