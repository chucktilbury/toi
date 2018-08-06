
#ifndef _PARSE_IMPORT_H_
#define _PARSE_IMPORT_H_

#include "toi.h"

// An import has the syntax of:
// import SYMBOL ;
// Where, SYMBOL is the processed name of the file to import.
class ParseImport {

public:
    ParseImport();
    ~ParseImport();

    bool parse();

private: 
    Parser* parser;
};

#endif /* _PARSE_IMPORT_H_ */ 