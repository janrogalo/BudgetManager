
#ifndef UserFile_hpp
#define UserFile_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include "User.hpp"
#include "SupportingMethods.hpp"
#include "XMLFile.hpp"

using namespace std;

class UserFile : public XMLFile {
  ;
    User getUserData();
    
    
public:
UserFile(string filename) : XMLFile(filename){};
    void saveUserToFile(User user);
    vector <User> getUsersFromFile();
   void  saveAllUsersToFile(vector <User> &users);
  
};












#endif /* UserFile_hpp */
