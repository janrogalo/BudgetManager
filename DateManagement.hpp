//
//  DateManagement.hpp
//  XML_Proby
//
//  Created by Jan Rogalo on 13/02/2022.
//

#ifndef DateManagement_hpp
#define DateManagement_hpp

#include <stdio.h>
#include <cmath>
#include<ctime>
#include<iostream>

using namespace std;

class DateManagement{
    
    int beginingYear = 2000;

    
public:
    int static currentDate();
    int static currentMonthBegining();
    int static howManyDaysInMonth(int year, int month);
    int static previousMonthBeginning();
    int static previousMonthEnd();
    int  howManyDaysSinceFirstDate(int year, int month, int day);
    
    int getBeginningYear();
    
};


#endif /* DateManagement_hpp */
