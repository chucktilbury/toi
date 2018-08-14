#ifndef _STATEMENT_TREE_H_
#define _STATEMENT_TREE_H_

#include "toi.h"

/*
    This class implements the strategy and methods used to actually execute
    statements in the interpreter. A statement tree is attached to a method
    definition and it contains entries that can be converted to instructions
    that the machine can use. 

    The statement tree is a binary tree that is roughly analogous to a parse
    tree. It can contain an expression tree as well, but the main use is to
    virtualize the concept of a branch. A series of statements that have no 
    branches would become a simple linked list. Branches appear when the 
    series of statments has a branch that can be taken as false. The default
    side is true. 
*/
class StatementTree {

public:
    StatementTree() {
        
    }

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
};

#endif /* _STATEMENT_TREE_H_ */