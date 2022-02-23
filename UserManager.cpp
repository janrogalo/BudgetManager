#include "UserManager.hpp"

User UserManager::inputNewUserData(){
    User user;
    string username, password, name, surname;
    cin.ignore();
    
    user.setUserId(getNewUserId());
    do{
        cout << "Input username: ";
        username = SupportingMethods::inputLine();
        user.setUsername(username);
    }
    while (userExists(user.getUsername()) == true);
    cout << "Input name: ";
    name = SupportingMethods::inputLine();
    user.setName(name);
    cout << "Input Surname: ";
    surname = SupportingMethods::inputLine();
    user.setSurname(surname);
    
    cout << "Input password: ";
    password = SupportingMethods::inputLine();
    user.setPassword(password);
    return user;
        
    }

int UserManager::getNewUserId(){
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::userExists(string username){
    for(int i=0; i <  users.size(); i++){
        if (users[i].getUsername() == username)
        {
            cout << "Following username already exists in the database." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::registerUser(){
    User user = inputNewUserData();
   users.push_back(user);
    userFile.saveUserToFile(user);

    cout << endl << "Account has been created successfully!" << endl << endl;
}


void UserManager::printAllUsers(){
    for(int i=0; i <  users.size(); i++){
        cout << "User ID: "<< users[i].getUserId()<<endl;
        cout << "Username: "<<users[i].getUsername()<< endl;
        cout <<"Name: "<< users[i].getName()<< endl;
        cout << "Surname: "<< users[i].getSurname()<< endl;
        cout << "Password: "<<users[i].getPassword()<< endl;
    }
}

int UserManager::loginUser()
{
    User user;
    string username = "", password = "";
    cin.ignore();
    
    cout << endl << "Enter username: ";
    username = SupportingMethods::inputLine();
    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getUsername() == username){ 
            for (int attempts = 3; attempts > 0; attempts--){
                cout << "Enter password. Attempts remaining: " << attempts << ": ";
                password = SupportingMethods::inputLine();
                
                if (itr -> getPassword() == password){
                    cout << endl << "You logged in successfully." << endl << endl;
                    loggedInUserId = itr -> getUserId();
                    return loggedInUserId;
                }
            }
            cout << "You made 3 unsuccessful attempts." << endl;
            return 0;
        }
        itr++;
        
    }
    cout << "Username not found" << endl << endl;
    return 0;
}

int UserManager::getLoggedinUserId()
{
    return loggedInUserId;
}

bool UserManager::isUserLoggedIn()
{
    if (loggedInUserId >0)
        return true;
    else
        return false;
}

void UserManager::changePassword(){
    
    string newPassword = "";
        cout << "Enter new password: ";
        cin >> newPassword;
        
        for (int i=0; i < users.size(); i++){
            if (users[i].getUserId() == getLoggedinUserId()){ users[i].setPassword(newPassword);
                userFile.changePassword(users[i]);
                cout <<"Your password has been changed." << endl << endl;
            }
        }
    }

void UserManager::setLoggedInUserId(int newLoggedInUserId){
    loggedInUserId = newLoggedInUserId;
}

void UserManager::logout(){
    setLoggedInUserId(0);
}
