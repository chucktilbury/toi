

#include "simple.h"

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

SymTable* Parser::load_program() {

    return symtable;
}
 