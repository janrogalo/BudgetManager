#include "User.hpp"

void User::setUserId(int newUserId){
    if (newUserId >= 0)
        userId = newUserId;
}
void User::setUsername( string newUsername){
    username = newUsername;
}
void User::setPassword (string newPassword){
    password=newPassword;
}

void User::setName( string newName){
    name = newName;
}
void User::setSurname (string newSurname){
    surname=newSurname;
}

int User::getUserId(){
    return userId;
}
string User::getUsername(){
    return username;
}
string User::getPassword(){
    return password;
}

string User::getName(){
    return name;
}
string User::getSurname(){
    return surname;
}
