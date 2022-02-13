#include <iostream>
//#include <cmath>
//#include<ctime>
//#include <cstdlib>
//#include "Markup.h"
#include "BudgetManager.hpp"

using namespace std;

int main(){
    BudgetManager budgetManager("user.xml", "expense.xml"); 
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
                    budgetManager.printThisMonthsExpenseBalance();
                 budgetManager.addExpense();
                //    budgetManager.printAllExpenses();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Please make another choice." << endl << endl;
                    break;
            }
            if (loggedInUserId != 0){cout << "USER MENU";}
        }
       
}
    while (true);
}

