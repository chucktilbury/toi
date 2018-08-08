
#ifndef _PARSE_IMPORT_H_
#define _PARSE_IMPORT_H_

#include "toi.h"

// An import has the syntax of:
// import SYMBOL ;
// Where, SYMBOL is the processed name of the file to import.
class ParseImport {

public:
    ParseImport() {
        MARK("ENTER");
        parser = Parser::get_instance();
        MARK("RETURN");
    }

    ~ParseImport() {
        MARK("ENTER");
        MARK("RETURN");
    }

    bool parse();

private: 
    Parser* parser;
    bool import_file(const string fname);
};

#endif /* _PARSE_IMPORT_H_ */ 