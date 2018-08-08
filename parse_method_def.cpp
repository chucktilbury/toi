
#include "toi.h"


bool ParseMethodDef::parse() {
    MARK("ENTER");
    lexer_token_t tok;
    bool retv = false;
    const string name = parser->get_token_str();

    Logging(DEBUG) << "parsing method: " << name; 
    // store the name in the symbol table
    parser->save_symbol(name);
    parser->save_symbol_attribute(name, "TYPE", FUNC_DEF, nullptr);
    parser->save_symbol_attribute(name, "CONTEXT", CONTEXT, new string(parser->get_context()));

    parser->push_context(name);
    if(true == (retv = read_input_parameters()))
        return retv;

    if(true == (retv = read_output_parameters()))
        return retv;

    Statements* stats = new Statements();
    if(true == (retv = stats->parse(name)))
        return retv;

    parser->pop_context();
    parser->save_symbol_attribute(name, "EXEC_LIST", EXEC_LIST, (void*)stats);

    MARK("RETURN");
    return retv;
}

// Input and output parameters have different attributes but the same parsing rules.
// Method parameters are accessible in the scope of the method, but they must have
// references outside that scope 
bool ParseMethodDef::read_input_parameters() {
    MARK("ENTER");
    lexer_token_t tok;
    bool retv = false;

    MARK("RETURN");
    return retv;
}

bool ParseMethodDef::read_output_parameters() {
    MARK("ENTER");
    lexer_token_t tok; 
    bool retv = false;

    MARK("RETURN");
    return retv;
}

bool ParseMethodDef::read_parameter_list() {
    MARK("ENTER");
    lexer_token_t tok; 
    bool retv = false;

    MARK("RETURN");
    return retv;
}
