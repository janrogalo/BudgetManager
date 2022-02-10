#ifndef UserManager_hpp
#define UserManager_hpp


#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "SupportingMethods.hpp"
#include "UserFile.hpp"



using namespace std;

class UserManager{
    
   
    vector  <User> users;
    UserFile userFile;
    User inputNewUserData();
    int loggedInUserId;
    int getNewUserId();
    bool userExists(string username);
    
public:
    
UserManager(string userFilename) : userFile(userFilename){
    loggedInUserId = 0;
    users=userFile.getUsersFromFile();
};
    
    int loginUser();
    void registerUser();
    void printAllUsers();
    int getLoggedinUserId();
    
    //void wczytajUzytkownikowZPliku();
  //  void zmianaHaslaZalogowanegoUzytkownika();
  //  void ustawIdZalogowanegoUzytkownika (int IDZALOGOWANEGOUZYTKOWNIKA );

   // void wylogujUzytkownika();
   // bool czyUzytkownikJestZalogowany();
    
};



#endif /* UserManager_hpp */
