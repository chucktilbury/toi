#ifndef _SYMTABLE_H_
#define _SYMTABLE_H_

#include <iostream>
#include <unordered_map>
#include <string>
#include "toi.h"

using namespace std;

typedef enum {
    INVALID_ATTR = 1,
    FUNC_DEF = 2000,    // funcion call definition
    CONTEXT,            // context of the symbol
    USER_DEF_TYPE,      // User defined type
    NUM_DEF,            // definition of a numeric value
    STRING_DEF,         // definition of a string value
    BOOL_DEF,           // definition of a boolean value
    OUTVAL_DEF,         // symtable object is a out value of a function definition
    INVAL_DEF,          // symtable object is a in of a function value definition
    EXEC_LIST,          // list of executable statements
    TYPE_NAME,          // name of a user defined type 
} sym_attr_type_t;


class SymTable {

public:
    SymTable() {} // nothing to do.
    ~SymTable() {
        // destroy the allocated data in the table.
        // TODO: figure out how to deal with the data pointers.
        for(auto& key: symtable) {
            for(auto& name: symtable[key.first]->attr) {
                if(name.second)
                    delete name.second;
            }
        }
    }

    void add_symbol(string name) {
        if(!check_symbol(name))
            symtable[name] = new attr_map;
    }

    bool check_symbol(string name) {
        return (symtable.find(name) != symtable.end());
    }

    // makes the assumption that the data has already been "new"ed.
    void add_attrib(string key, string name, void* data, sym_attr_type_t type) {
        if(check_symbol(key))
            symtable[key]->attr[name] = new (struct attr){data, type, 0};
    }

    void* find_attr(string key, string name, sym_attr_type_t* type) {
        if(!check_attr(key, name)) 
            return nullptr;
        else {
            *type = symtable[key]->attr[name]->type;
            return symtable[key]->attr[name]->data;
        }
    }

    bool check_attr(string key, string name) {
        if(symtable.find(key) == symtable.end() 
                || (symtable[key]->attr.find(name) == symtable[key]->attr.end()))
            return false;
        else 
            return true;
    }

    void dump() {
        // ToDo: function to iterate the symbol table and print out the results.
        // This should not be present at run time, if possible.
        cout << "Dump SymbolTable\n";
        for(auto& key: symtable) {
            cout << "  symbol: " << key.first << endl;
            for(auto& name: symtable[key.first]->attr) {
                cout << "    " << name.first << " type: " << symtable[key.first]->attr[name.first]->type;
                if(name.second)
                    cout << " data is present\n";
                else 
                    cout << " no data";
            }
        }
    }

private:

    struct attr {
        void* data;
        sym_attr_type_t type;
        size_t size;
    };

    struct attr_map {
        unordered_map<string, struct attr*> attr;
    };

    unordered_map<string, struct attr_map*> symtable;
};

#endif /* _SYMTABLE_H_ */
