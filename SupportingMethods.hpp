#ifndef SupportingMethods_hpp
#define SupportingMethods_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "User.hpp"

using namespace std;

class SupportingMethods{
    
public:

static string inputLine();
static string convertDateToDigits(string date);
static string convertDateToFormat(string date);
static string convertComaToDot(string amount);
static string setPrecisionforXml(double number);

};

#endif /* SupportingMethods_hpp */
