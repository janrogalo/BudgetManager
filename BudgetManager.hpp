#ifndef BudgetManager_hpp
#define BudgetManager_hpp

#include <stdio.h>
#include <iostream>
#include "UserManager.hpp"


using namespace std;

class BudgetManager{
    
    UserManager userManager;
    
public:
    
    BudgetManager(string userFilename) : userManager(userFilename){};
    
    void registerUser();
    void logInUser();
    void printAllUsers();
    void mainMenu();
    int getLoggedInUserId();

};

#endif /* BudgetManager_hpp */
