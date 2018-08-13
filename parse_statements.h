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
        MARK("RETURN");
    }
    ~Statements() {
        MARK("ENTER");
        MARK("RETURN");
    } 

    bool parse(const string name);

private:
    struct attr {
        void* data;
        sym_attr_type_t type;
    };

    struct stat_map {
        unordered_map<string, struct attr*> attr;
        struct stat_map_t* true_br;
        struct stat_map_t* false_br;
    };

    struct stat_map* root;
    struct stat_map* last_true;
    struct stat_map* last_false;

    Parser* parser;
};

#endif /* _PARSE_STATEMENTS_H_ */