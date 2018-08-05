#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
#include "simple.h"

using namespace std;

// This class is a singleton because it is the nexus of the lexer, the symbol 
// table, and the parsing context, all of which have a global state. The other
// classes in the parser implement a recursive decent parser that yields the
// complete program in the symbol table.
class Parser {

public:
    Parser();
    ~Parser();

    void init_parser(const string fname);
    void destroy_parser();
    SymTable* load_program();

    // interface to the lexer
    string file_name(void) { return lexer->file_name(); }
    int line_number(void) { return lexer->line_number(); }
    void open_file(string name) { lexer->open_file(name); }

    // interface to the parsing context
    void push_context(string name) { context-> push_context(name); }
    void pop_context() { context->pop_context(); }
    string get_context() { return context->get_context(); }

    // interface to the symbol table
    void save_symbol(string name) { symtable->add_symbol(name); }
    bool find_symbol(string name) { return symtable->check_symbol(name); }
    void save_symbol_attribute(string sym_name, 
                        string attr_name, 
                        sym_attr_type_t type, void* data) {
        symtable->add_attrib(sym_name, attr_name, data, type);
    }
    void* get_symbol_attribute(const string sym_name, 
                        const string attr_name, 
                        sym_attr_type_t* type) {
        return symtable->find_attr(sym_name, attr_name, type);
    }

    static Parser* get_instance() {
        if(instance == nullptr) {
            instance = new Parser();
        }
        return instance;
    }

private:
    Lexer* lexer;
    Context* context;
    SymTable* symtable;

    static Parser* instance;

};

#endif /* _PARSER_H_ */