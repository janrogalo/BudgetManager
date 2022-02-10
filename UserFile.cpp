#include "UserFile.hpp"


void UserFile::saveUserToFile(User user){
   
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    
if (!fileExists){
    xml.AddElem("Users");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Username", user.getUsername());
    xml.AddElem("Password", user.getPassword());
    xml.Save(getFilename());
}
  
vector <User> UserFile::getUsersFromFile(){
    User user;
    vector <User> users;
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (fileExists){
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.FindChildElem("UserId");
        user.setUserId(stoi(xml.GetChildData()));
        xml.FindChildElem("Username");
        user.setUsername(xml.GetChildData());
        xml.FindChildElem("Password");
        user.setPassword(xml.GetChildData());
        users.push_back(user);
    }
    }
    return users;
}
    
    

   
    
    
