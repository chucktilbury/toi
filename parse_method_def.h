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
    ParseMethodDef() {
        MARK("ENTER");
        parser = Parser::get_instance();
        MARK("RETURN");
    }

    ~ParseMethodDef() {
        MARK("ENTER");
        MARK("RETURN");
    }

    bool parse();

private: 
    Parser* parser;

    bool read_input_parameters();
    bool read_output_parameters();
    bool read_parameter_list();

};


#endif /* _PARSE_METHOD_H_ */