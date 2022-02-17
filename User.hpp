#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class User{

    int userId;
    string username;
    string password;
    string name;
    string surname;

public:
    
    void setUserId(int newId);
    void setUsername( string newUsername);
    void setPassword (string newPassword);
    void setName (string newName);
    void setSurname (string surName);
    
    int getUserId();
    string getUsername();
    string getPassword();
    string getName();
    string getSurname();
};

#endif /* User_hpp */
