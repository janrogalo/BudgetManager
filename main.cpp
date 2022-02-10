#include <iostream>
//#include <cmath>
//#include<ctime>
//#include <cstdlib>
//#include "Markup.h"
#include "BudgetManager.hpp"

using namespace std;

int main(){
    BudgetManager budgetManager ("user.xml");

    budgetManager.printAllUsers();

    int loggedInUserId = 0;
    
    do{
        char menuChoice;
        if (loggedInUserId == 0){
            budgetManager.mainMenu();
            menuChoice = getchar();
            switch (menuChoice)
            {
                case '1':
                    budgetManager.registerUser();
                    break;
                case '2':
                    budgetManager.logInUser();
                    loggedInUserId = budgetManager.getLoggedInUserId();
                    break;
                case '9':
                    exit(0);
                    break;
                default:
                    cout << endl << "Please make another choice." << endl << endl;
                    break;
            }
            if (loggedInUserId != 0){cout << "USER MENU";}
        }
       
}
  
    while (true);
}
    











/*
// Data powinna być oddzielną klasą  - z dwoma obiektami - data terazniejsza (która może być const?)

int ileDniWMiesiacu(int miesiac, int rok)
{
    int ileDni;
    if ( miesiac == 1 || miesiac == 3 || miesiac == 5 || miesiac == 7 || miesiac == 8 || miesiac == 10 || miesiac == 21 ) {
        ileDni = 31;
        return ileDni;
    }
    else if ( miesiac == 2 && rok%4 == 0 ){
        ileDni = 29;
        return ileDni;
    }
    else if ( miesiac == 2 && rok%4 != 0){
        ileDni =28;
        return ileDni;
    }
    else{ ileDni = 30;
        return ileDni;
    }
}

int ileDniOdPoczatku(int podanyRok, int podanyMiesiac, int podanyDzien){

int ileDniOdPoczatkuPodanyRok = 0;
for (int i = 2000; i < podanyRok; i++){
    if(i%4== 0){
        ileDniOdPoczatkuPodanyRok += 366;
    }
    else{
        ileDniOdPoczatkuPodanyRok += 365;
    }
}
for ( int i = 1; i < podanyMiesiac; i++){
    ileDniOdPoczatkuPodanyRok += ileDniWMiesiacu(i, podanyRok);
}
ileDniOdPoczatkuPodanyRok += podanyDzien ;
return  ileDniOdPoczatkuPodanyRok;
}

int main()
{
    
    time_t t = time(NULL);
    tm* tPtr = localtime(&t);
    
    int miesiac = (tPtr->tm_mon)+1;
    int rok = (tPtr->tm_year)+1900;
    int dzien = (tPtr->tm_mday);
    
    cout << "Aktualna data: " <<rok<<"-"<< miesiac <<"-"<< dzien<< "." << endl;
    cout << "Aktualny miesiąc ma " << ileDniWMiesiacu(miesiac, rok) << " dni." << endl;
    
    int podanyRok = 2021, podanyMiesiac = 12, podanyDzien = 24;
    cout << "Podana data: " << podanyRok << "-" << podanyMiesiac <<"-" << podanyDzien << "." <<endl;
    
    int ileDniMiedzyDatami = ileDniOdPoczatku(rok, miesiac, dzien) - ileDniOdPoczatku(podanyRok, podanyMiesiac, podanyDzien)+1;

cout << " Ilość dni między datami to: " << ileDniMiedzyDatami << endl;
    
    CMarkup xml;
    bool fileExists = xml.Load("dates.xml");
    
if (!fileExists){
    xml.AddElem("Dates");
}
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Date");
    xml.IntoElem();
    xml.AddElem("Year", rok);
    xml.AddElem("Month", miesiac);
    xml.AddElem("Day", dzien);
    xml.Save("dates.xml");
    
    
    xml.ResetPos(); //
    xml.FindElem(); //
    xml.IntoElem(); //
    while ( xml.FindElem("Date") )
    {
        xml.FindChildElem( "Year" );
       string year = xml.GetChildData();
        xml.FindChildElem( "Month" );
        string month = xml.GetChildData();
        xml.FindChildElem( "Day" );
        string day = xml.GetChildData();

        cout << stoi(year) << "-" << stoi(month) << "-" << stoi(day) << endl;
    }
   */

