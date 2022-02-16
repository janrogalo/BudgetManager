//
//  DateManagement.cpp
//  XML_Proby
//
//  Created by Jan Rogalo on 13/02/2022.
//

#include "DateManagement.hpp"


int DateManagement::currentDate(){
    
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    
    int month = (tPtr->tm_mon)+1;
    int year = (tPtr->tm_year)+1900;
    int day = (tPtr->tm_mday);
    
    int currentDate = year*10000 + month *100 + day;
    return currentDate;
}

int DateManagement::currentMonthBegining(){
    
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    
    int month = (tPtr->tm_mon)+1;
    int year = (tPtr->tm_year)+1900;
    
    
    int currentMonthBeginning = year*10000 + month *100;
    return currentMonthBeginning;
}

int DateManagement::howManyDaysInMonth(int year, int month){
    
    {
        
        int numberOfDays;
        if ( month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ) {
            numberOfDays = 31;
            return numberOfDays;
        }
        else if ( month == 2 && year%4 == 0  && year%400 == 0 && !(year%100 == 0)){
            numberOfDays = 29;
            return numberOfDays;
        }
        else if ( month == 2 && year%4 != 0 && year%100 == 0  && !(year%400 == 0)){
            numberOfDays=28;
            return numberOfDays;
        }
        else{ numberOfDays = 30;
            return numberOfDays;
        }
    }
}

int DateManagement::previousMonthBeginning(){
    
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    
    int month = (tPtr->tm_mon);
    int year = (tPtr->tm_year)+1900;
    
    int previousMonthBeginning = year*10000 + month *100 + 1;
    
    return previousMonthBeginning;
}


int DateManagement::previousMonthEnd(){
    
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    
    int month = (tPtr->tm_mon);
    int year = (tPtr->tm_year)+1900;
    
    int previousMonthEnd = year*10000 + month *100 + howManyDaysInMonth(year, month);
    return previousMonthEnd;
}

int DateManagement::howManyDaysSinceFirstDate(int year, int month, int day){
    
    int daysSinceFirstDate = 0;
    for (int i = getBeginningYear(); i < year; i++){
        if(i%4== 0 && year%400 == 0 && !(year%100 == 0)){
            daysSinceFirstDate += 366;
        }
        else{
            daysSinceFirstDate += 365;
        }
    }
    for ( int i = 1; i < month; i++){
        daysSinceFirstDate += howManyDaysInMonth(year, month);
    }
    daysSinceFirstDate += day ;
    return  daysSinceFirstDate;
}

int DateManagement::getBeginningYear(){
    return beginingYear;
}

bool DateManagement::dateValidation(string date){
    
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    int year = (tPtr->tm_year)+1900;
    

    
    int dateInput = stoi(date);

    int dayInput = dateInput%100;
    int monthInput = (dateInput  / 100) % 100;
    int yearInput = dateInput / 10000;
    
    if(yearInput >= 2000 && yearInput <= year){
        if (monthInput >= 1 && monthInput <= 12){
            if (dayInput <= howManyDaysInMonth(yearInput, monthInput) ){
                return true;
            }
            return false;
        }
        return false;
    }
    else;
    return false;
}
