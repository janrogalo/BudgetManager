#include "BudgetManager.hpp"

void BudgetManager::registerUser(){
userManager.registerUser();
}

void BudgetManager::printAllUsers(){
userManager.printAllUsers();
}

void BudgetManager::logInUser(){
    userManager.loginUser();
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
    cout << "Twoj wybor: ";
}

int BudgetManager::getLoggedInUserId(){
   return userManager.getLoggedinUserId();
}