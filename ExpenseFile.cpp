//
//  ExpenseFile.cpp
//  XML_Proby
//
//  Created by Jan Rogalo on 11/02/2022.
//

#include "ExpenseFile.hpp"
 
 
bool ExpenseFile::saveExpenseOperationToFile(Expense expense){

        CMarkup xml;
        bool fileExists = xml.Load(getFilename());

    if (!fileExists){
        xml.AddElem("Expenses");
    }
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("Expense");
        xml.IntoElem();
        xml.AddElem("ExpenseOperationId", expense.getExpenseOperationId());
        xml.AddElem("UserId", expense.getUserId());
        xml.AddElem("Type", expense.getType());
        xml.AddElem("Amount", expense.getAmount());
        xml.AddElem("Date", expense.getDate());
 
        xml.Save(getFilename());
        lastExpenseOperationId++;
        return true;
    }

vector <Expense> ExpenseFile::readExpenseOperationsFromFile(int loggedInUserId){
    Expense expense;
    vector <Expense> expenses;
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (fileExists){
    xml.FindElem();
    xml.IntoElem();
        
    while (xml.FindElem("Expense"))
    {
        xml.FindChildElem("ExpenseOperationId");
        expense.setExpenseOperationId(stoi(xml.GetChildData()));
        xml.FindChildElem("UserId");
        expense.setUserId(stoi(xml.GetChildData()));
        xml.FindChildElem("Type");
        expense.setType(xml.GetChildData());
        xml.FindChildElem("Amount");
        expense.setAmount(stoi(xml.GetChildData()));
        xml.FindChildElem("Date");
        expense.setDate(xml.GetChildData());
        if (expense.getUserId() == loggedInUserId){
        expenses.push_back(expense);
        }
    }
    }
    return expenses;
}
    
int ExpenseFile::getlastExpenseOperationId(){
    Expense expense;
    int lastId=0;
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (fileExists){
    xml.FindElem();
    xml.IntoElem();
        
    while (xml.FindElem("Expense"))
    {
    
        xml.FindChildElem("ExpenseOperationId");
        expense.setExpenseOperationId(stoi(xml.GetChildData()));
        }
        
 lastId = expense.getExpenseOperationId();
    }
return lastId;
}
    

