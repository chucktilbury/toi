#ifndef _PARSE_STATEMENTS_H_
#define _PARSE_STATEMENTS_H_

#include <unordered_map>
#include "toi.h"

using namespace std;

typedef enum {
    VAR_DEF,
    VAR_REF,
    METHOD_REF,
    BRANCH,
} state_map_attr_t;

class Statements {

public:
    Statements() {
        MARK("ENTER");
        parser = Parser::get_instance();
        context = parser->get_context();
        MARK("RETURN");
    }
    ~Statements() {
        MARK("ENTER");
        MARK("RETURN");
    } 

    bool parse();

private:
    Parser* parser;
    string context;
};

#endif /* _PARSE_STATEMENTS_H_ */