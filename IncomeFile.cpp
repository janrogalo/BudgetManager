#include "IncomeFile.hpp"

bool IncomeFile::saveIncomeOperationToFile(Income income){
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    
    if (!fileExists){
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("IncomeOperationId", income.getIncomeOperationId());
    xml.AddElem("UserId", income.getUserId());
    xml.AddElem("Type", income.getType());
    xml.AddElem("Amount", SupportingMethods::convertComaToDot(SupportingMethods::setPrecisionforXml(income.getAmount())));
    xml.AddElem("Date", income.getDate());
    
    xml.Save(getFilename());
    lastIncomeOperationId++;
    return true;
}

vector <Income> IncomeFile::readIncomeOperationsFromFile(int loggedInUserId){
    Income income;
    vector <Income> incomes;
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (fileExists){
        xml.FindElem();
        xml.IntoElem();
        
        while (xml.FindElem("Income"))
        {
            xml.FindChildElem("IncomeOperationId");
            income.setIncomeOperationId(stoi(xml.GetChildData()));
            xml.FindChildElem("UserId");
            income.setUserId(stoi(xml.GetChildData()));
            xml.FindChildElem("Type");
            income.setType(xml.GetChildData());
            xml.FindChildElem("Amount");
            income.setAmount(stod(xml.GetChildData()));
            xml.FindChildElem("Date");
            income.setDate(xml.GetChildData());
            if (income.getUserId() == loggedInUserId){
                incomes.push_back(income);
                
            }
        }
    }
    return incomes;
}

int IncomeFile::getlastIncomeOperationId(){
    Income income;
    int lastId=0;
    
    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (fileExists){
        xml.FindElem();
        xml.IntoElem();
        
        while (xml.FindElem("Income"))
        {
            xml.FindChildElem("IncomeOperationId");
            income.setIncomeOperationId(stoi(xml.GetChildData()));
        }
        lastId = income.getIncomeOperationId();
    }
    return lastId;
}
