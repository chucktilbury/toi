

#include "toi.h"

Parser* Parser::instance = nullptr;

Parser::Parser() {}

Parser::~Parser() {
    destroy_parser();
}

void Parser::init_parser(const string fname) {
    lexer = new Lexer();
    context = new Context();
    symtable = new SymTable();
    lexer->open_file(fname);
}

void Parser::destroy_parser() {
    delete lexer;
    delete context;
    delete symtable;
}

// Items that may appear in the root context of a file are parsed here.
SymTable* Parser::load_program() {

    bool finished = false;
    lexer_token_t tok;

    while(!finished) {
        tok = lexer->get_token();
        switch(tok) {
            case IMPORT:
                finished = ParseImport().parse(); 
                break;
            case SYMBOL:
                finished = ParseMethodDef().parse();
                break;
            case END_INPUT:
                Logging(DEBUG) << "end of input: context: " << get_context();
                finished = true;
                break;
            default:
                Logging(SYNTAX) << "expected a import or method definition but got \"" << lexer->token_string() << "\"";
                finished = true;
        }
    }

    return symtable; 
}

