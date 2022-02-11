//
//  OperationFile.cpp
//  XML_Proby
//
//  Created by Jan Rogalo on 11/02/2022.
//

#include "OperationFile.hpp"

/*
void OperationFile::saveOperationToFile(Operation operation){
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    
if (!fileExists){
    xml.AddElem("Operations");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Operation");
    xml.IntoElem();
    xml.AddElem("OperationId", operation.getOperationId());
    xml.AddElem("UserId", operation.getUserId());
    xml.AddElem("Expense", operation.getExpense());
    xml.AddElem("Type", operation.getType());
    xml.AddElem("Amount", operation.getAmount());
    xml.AddElem("Date", operation.getDate());
    
    xml.Save(getFilename());
}


vector <Operation> OperationFile::getOperationData(int loggedInUserId){
   
    Operation operation;
    vector <Operation> operations;
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (fileExists){
    xml.FindElem();
    xml.IntoElem();
    while (xml.FindElem("Operation"))
    {
        xml.FindChildElem("OperationId");
        operation.setOperationId(stoi(xml.GetChildData()));
        xml.FindChildElem("UserId");
       operation.setUserId(stoi(xml.GetChildData()));
        xml.FindChildElem("Expense");
        operation.setExpense(stoi(xml.GetChildData()));
        xml.FindChildElem("Type");
        operation.setType(xml.GetChildData());
        xml.FindChildElem("Amount");
    operation.setAmount(stoi(xml.GetChildData()));
        xml.FindChildElem("Date");
        operation.setDate(xml.GetChildData());
        
    
      
        operations.push_back(operation);
        }
    }
    return operations;
}

*/
