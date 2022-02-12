#include "SupportingMethods.hpp"

string SupportingMethods::inputLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

int SupportingMethods::convertDateToInt(string date){
  
       int temp, digit, sum = 0;
        for(int i = 0; i < date.length(); i++){
            if(isdigit(date[i])){
               temp = date[i];
               digit = temp - 48;
               sum = sum*10 + digit;
            }
        }
        return sum;
    }

string SupportingMethods::convertDateToString(int date){
  
    string dateString;

        int day = date%100;
        date= (date - day)/100 ;
        int month = date%100;
        int year= (date - month)/100;
        
        dateString = to_string(year) + "-" + to_string(month) + "-" + to_string(day);
    return dateString;
    }
