#include "UserFile.hpp"


void UserFile::saveUserToFile(User user){
   
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    
if (!fileExists){
    xml.AddElem("Users");
}
    xml.FindElem("Users");
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Username", user.getUsername());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Password", user.getPassword());
    
    xml.Save(getFilename());
}
  
vector <User> UserFile::getUsersFromFile(){
    User user;
    vector <User> users;
    
    CMarkup xml;
    xml.Load(getFilename());
    xml.FindElem("Users");
    xml.IntoElem();
    while (xml.FindElem("User"))
    {
        xml.FindChildElem("UserId");
        user.setUserId(stoi(xml.GetChildData()));
        xml.FindChildElem("Username");
        user.setUsername(xml.GetChildData());
        xml.FindChildElem("Name");
        user.setName(xml.GetChildData());
        xml.FindChildElem("Surname");
        user.setSurname(xml.GetChildData());
        xml.FindChildElem("Password");
        user.setPassword(xml.GetChildData());
        users.push_back(user);
    }
    return users;
}
    
 
void  UserFile::changePassword(User user){
    
    CMarkup xml;
    xml.Load(getFilename());
  
        xml.FindElem("Users");
        xml.IntoElem();
        while (xml.FindElem("User")){
            xml.FindChildElem("UserId");
            if (stoi( MCD_2PCSZ(xml.GetChildData())) == user.getUserId()){
                xml.FindChildElem("Password");
                xml.SetChildData(user.getPassword());
            }
        }
    xml.Save(getFilename());
}



   
    
    
