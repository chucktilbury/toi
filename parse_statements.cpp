
#include <string>
#include "toi.h"

bool Statements::parse(const string name) {
    MARK("ENTER");
    lexer_token_t tok;
    bool retv = false;
    bool finished = false;

    tok = parser->get_token();
    if(tok != OCURLY) {
        SYNTAX_ERR("a {");
        retv = true;
    }
    else {
        while(!finished) {
            tok = parser->get_token();
            switch(tok) { 
                case END_INPUT:
                    Logging(DEBUG) << "end of input: context: " << parser->get_context();
                    finished = true;
                    break;
                case CCURLY:
                    finished = true;
                    break;
                default:
                    Logging(DEBUG) << "token is: " << parser->get_token_str();
            }
        }
    }

    MARK("RETURN");
    return retv; 
}
