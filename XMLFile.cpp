#include "XMLFile.hpp"

bool XMLFile::fileEmpty()
{
    bool empty = true;

    CMarkup xml;
    bool fileExists = xml.Load(getFilename());
    if (!fileExists){
        cout << "File not found.";
    }
    if (xml.IsWellFormed()){
            empty = false;
    }
    return empty;
}

string XMLFile::getFilename()
{
    return FILENAME;
}
