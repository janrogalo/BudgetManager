#ifndef IncomeFile_hpp
#define IncomeFile_hpp

#include <stdio.h>
#include <vector>
#include <iomanip>
#include "Income.hpp"
#include "XMLFile.hpp"
#include "SupportingMethods.hpp"

class IncomeFile : public XMLFile {
    
    int lastIncomeOperationId;
    int loggedInUserId;
    SupportingMethods supportinMethods;
    Income getIncomeData();
    
public:
    IncomeFile(string filename) : XMLFile(filename)
    {
        lastIncomeOperationId = getlastIncomeOperationId();
   
    };
    
    bool saveIncomeOperationToFile(Income income);
    vector <Income> readIncomeOperationsFromFile (int loggedInUserId);
    int getlastIncomeOperationId();
    
};


#endif /* IncomeFile_hpp */
