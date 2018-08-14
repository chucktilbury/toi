
#include <string>
#include "toi.h"

bool Statements::parse() {
    MARK("ENTER");
    lexer_token_t tok;
    bool retv = false;
    bool finished = false;

    tok = parser->get_token();
    if(tok != OCURLY) {
        SYNTAX_ERR("beginning of a block");
        retv = true;
    }
    else {
        while(!finished) {
            tok = parser->get_token();
            switch(tok) {  
                // Reference to a function or an assignment, or could be a 
                // definition of an instance of a user-defined type. If the 
                // string has a format of symbol:symbol then it's a definition
                // of a var of a user defined type. If it has a format of 
                // symbol()() then it's a reference to a function.
                case SYMBOL:
                    break;

                // Local var definitions. These must have an approprate 
                // assignment or it's a syntax error. Var definitions do not
                // go into the instruction stream. They only exist in the 
                // symbol table, however, things like numerical and boolean 
                // expressions do go into the instruction stream.
                case NUM: // Var definition of an instance of a number
                    break;
                case STRG: // Var definition of an instance of a string
                    break;
                case BOOL: // Var definition of an instance of a boolean
                    break;

                // Control statements. 
                case IF: // Introduction to an if() statement
                    break;
                case FOR: // Introduction to a for() statement
                    break;
                case WHILE: // Introduction to a while() statement
                    break;
                case SWITCH: // introduction to a switch/case statement
                    break;

                // Finish
                case CCURLY:
                    finished = true;
                    break;

                // errors
                case END_INPUT: // this is a syntax error
                    //Logging(DEBUG) << "end of input: context: " << parser->get_context();
                    UNEXPECTED_EOF();
                    finished = true;
                    break;
                default:
                    //Logging(DEBUG) << "token is: " << parser->get_token_str();
                    SYNTAX_ERR("function statement");
                    finished = true;
                    break;
            }
        }
    }

    MARK("RETURN");
    return retv; 
}
