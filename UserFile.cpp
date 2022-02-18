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
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
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
        xml.FindChildElem("Name");
        user.setUsername(xml.GetChildData());
        xml.FindChildElem("Surname");
        user.setUsername(xml.GetChildData());
        xml.FindChildElem("Password");
        user.setPassword(xml.GetChildData());
        users.push_back(user);
    }
    }
    return users;
}
    
 
void UserFile::saveAllUsersToFile(vector <User> users, int loggedInUserId, int i){
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    
    if (fileExists){
        xml.FindElem();
        xml.IntoElem();
        while (xml.FindElem("User")){
            xml.FindChildElem("UserId");
            if (stoi(xml.GetChildData()) == loggedInUserId ) {
       
                for (i = 0; i < users.size(); i++){
           
                xml.AddElem("User");
                xml.IntoElem();
                xml.AddElem("UserId", users[i].getUserId());
                xml.AddElem("Username", users[i].getUsername());
                xml.AddElem("Name", users[i].getName());
                xml.AddElem("Surname", users[i].getSurname());
                xml.AddElem("Password", users[i].getPassword());
                xml.AddElem("/User");
            }
            }
            xml.RemoveElem();
        }
}
    xml.Save(getFilename());
}




   
    
    
