#ifndef _PARSE_METHOD_H_
#define _PARSE_METHOD_H_

#include "toi.h"

// A method definition has the syntax of:
// SYMBOL ( parameter_def_list ) ( parameter_def_list ) { method_body }
//  The SYMBOL is the name of the method and so the name of the context.
//  The first PDL are zero or more input parameters
//  The second PDL are zero or more output parameters
//  The method body is the statement list associated with the method.
class ParseMethodDef {

public:
    ParseMethodDef();
    ~ParseMethodDef();

    bool parse();

private: 
    Parser* parser;
};


#endif /* _PARSE_METHOD_H_ */