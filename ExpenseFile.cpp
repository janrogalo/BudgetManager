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
