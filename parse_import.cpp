
#include "toi.h"

bool ParseImport::parse() {
    MARK("ENTER");
    lexer_token_t tok;
    bool retv = false;

    tok = parser->get_token();
    if(tok == SYMBOL) {
        retv = import_file(parser->get_token_str());
    }
    else {
        SYNTAX_ERR("symbol"); 
        retv = true;
    }

    MARK("RETURN");
    return retv; 
}

bool ParseImport::import_file(const string fname) {
    MARK("ENTER");
    lexer_token_t tok;
    bool retv = false;

    Logging(DEBUG) << "importing file: " << fname; 
    // import the file here
    parser->push_context(fname);
    parser->pop_context();

    tok = parser->get_token();
    if(tok != SCOLON) {
        SYNTAX_ERR("semicolon");
        retv = true;
    }

    MARK("RETURN");
    return retv;
}