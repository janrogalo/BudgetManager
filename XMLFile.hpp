#ifndef XMLFile_hpp
#define XMLFile_hpp

#include <stdio.h>
#include <iostream>
#include "Markup.h"
 
using namespace std;
 
class XMLFile {
 
    const string FILENAME;
 
public:
 
    XMLFile(string filename) : FILENAME(filename) {
    }
 
    string getFilename();
    bool fileEmpty();
    
};


#endif /* XMLFile_hpp */
