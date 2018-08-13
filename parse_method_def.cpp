
#include "toi.h"


bool ParseMethodDef::parse() {
    MARK("ENTER");
    bool retv = false;
    string name;

    Logging(DEBUG) << "parsing method: " << name; 
    // store the name in the symbol table
    parser->push_context(parser->get_token_str());
    name = parser->get_context(); 
    parser->save_symbol(name);
    parser->save_symbol_attribute(name, "TYPE", FUNC_DEF, nullptr);
    parser->save_symbol_attribute(name, "CONTEXT", CONTEXT, new string(parser->get_context()));

    if(true == (retv = read_parameters(INVAL_DEF)))
        return retv;

    if(true == (retv = read_parameters(OUTVAL_DEF)))
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
bool ParseMethodDef::read_parameters(sym_attr_type_t use) {
    MARK("ENTER");
    lexer_token_t tok;
    bool retv = false;
    bool finished = false;
    bool comma_lock = true;

    tok = parser->get_token();
    if(tok == OPAREN) {
        while(!finished) {
            tok = parser->get_token();
            switch(tok) {
                case CPAREN:    // empty tuple 
                    MARK("empty tuple");
                    finished = true;
                    break;
                case COMMA:
                    if(comma_lock) {
                        Logging(SYNTAX) << "extra commas are not allowed in a tuple";
                        finished = true;
                        retv = true;
                    }
                    comma_lock = true;
                    break;
                case NUM:
                    {
                        comma_lock = false;
                        string name;
                        if(0 == ((name = read_param_name()).length())) {
                            finished = true;
                            retv = true;
                        }
                        else {
                            string cont_name = parser->make_context(name);
                            parser->save_symbol(cont_name);
                            parser->save_symbol_attribute(cont_name, "TYPE", NUM_DEF);
                            parser->save_symbol_attribute(cont_name, "USE", use);
                        }
                    }
                    break;
                case STRG:
                    {
                        comma_lock = false;
                        string name;
                        if(0 == ((name = read_param_name()).length())) {
                            finished = true;
                            retv = true;
                        }
                        else {
                            string cont_name = parser->make_context(name);
                            parser->save_symbol(cont_name);
                            parser->save_symbol_attribute(cont_name, "TYPE", STRING_DEF);
                            parser->save_symbol_attribute(cont_name, "USE", use);
                        }
                    }
                    break;
                case BOOL:
                    {
                        comma_lock = false;
                        string name;
                        if(0 == ((name = read_param_name()).length())) {
                            finished = true;
                            retv = true;
                        }
                        else {
                            string cont_name = parser->make_context(name);
                            parser->save_symbol(cont_name);
                            parser->save_symbol_attribute(cont_name, "TYPE", BOOL_DEF);
                            parser->save_symbol_attribute(cont_name, "USE", use);
                        }
                    }
                    break;
                case SYMBOL:
                    {
                        comma_lock = false;
                        string name;
                        if(0 == ((name = read_param_name()).length())) {
                            finished = true;
                            retv = true;
                        }
                        else {
                            string cont_name = parser->make_context(name);
                            parser->save_symbol(cont_name);
                            parser->save_symbol_attribute(cont_name, "TYPE", USER_DEF_TYPE);
                            parser->save_symbol_attribute(cont_name, "USE", use);
                            parser->save_symbol_attribute(cont_name, "NAME", TYPE_NAME, &cont_name);
                        }
                    }
                    break;
                case END_CONTEXT:
                case END_INPUT:
                    Logging(SYNTAX) << "unexpected end of input";
                    retv = true;
                    break;
                default:
                    SYNTAX_ERR("parameter list");
                    retv = true;
            }
        }
    }
    else {
        SYNTAX_ERR("open paren");
        retv = true;
    }

    MARK("RETURN");
    return retv;
}

string ParseMethodDef::read_param_name() {
    MARK("ENTER");
    lexer_token_t tok;
    string retv = "";

    tok = parser->get_token();
    if(tok != COLON) {
        SYNTAX_ERR(":");
        return retv;
    }

    tok = parser->get_token();
    if(tok != SYMBOL) {
        SYNTAX_ERR("a symbol");
        return retv;
    }
    else {
        retv = parser->get_token_str();
    }

    MARK("RETURN");
    return retv;
}

