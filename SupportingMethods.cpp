#include "SupportingMethods.hpp"

string SupportingMethods::inputLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

string SupportingMethods::convertDateToDigits(string date){
    
    int temp, digit, sum = 0;
    for(int i = 0; i < date.length(); i++){
        if(isdigit(date[i])){
            temp = date[i];
            digit = temp - 48;
            sum = sum*10 + digit;
        }
    }
    
    return to_string(sum);
}

string SupportingMethods::convertDateToFormat(string dateStr){
    
    string dateString;
    int date = stoi(dateStr);
    int day = date%100;
    date= (date - day)/100 ;
    int month = date%100;
    int year= (date - month)/100;
    
    
    dateString = to_string(year) + "-";
    
    if(month < 10){
        dateString += ("0" + to_string(month) + "-");}
    
    else dateString +=(to_string(month) + "-");
    
    if(day < 10){
        dateString += ("0" + to_string(day));}
    else dateString += to_string(day);
    
    return dateString;
}

string SupportingMethods::convertComaToDot(string amount){
    
    for( int i=0; i < amount.length(); i++){
        if (amount[i] == ','){
            amount[i] = '.';
        }
    }
    return amount;
}
