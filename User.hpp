#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

class User{

    int userId;
    string username;
    string password;

public:
    
    void setUserId(int newId);
    void setUsername( string newUsername);
    void setPassword (string newPassword);
    
    int getUserId();
    string getUsername();
    string getPassword();
};

#endif /* User_hpp */
