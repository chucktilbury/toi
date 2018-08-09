
#ifndef _CONTEXT_H_
#define _CONTEXT_H_

#include <string> 
using namespace std;

// This class manipulates a string that describes the current context that
// is being parsed. There can be only one contexxt in a parser, It is intended
// to be used where the parser class is a singleton that has this as a member.
class Context {

public:
    Context() {
        //context = string("@");
    }
    ~Context() {}

    // This is called when a class or method is entered. When a "{"
    // that is connected with a name is seen.
    void push_context(string name) {
        context += "@";
        context += name;
    }

    void push_anonymous_context() {
        // todo: Find a criteria to create a number that can be replicated by 
        // the runner. An anonymous context is needed when an if() or a for() 
        // is encountered. This could just be a serial number, but the order
        // in which items are encountered will not be the same at parse time
        // as it is at run time. Maybe this just needs to be stored in the 
        // symbol table, but I want to also allow ananymous contexts that 
        // have no anchor to an if() or while().

        // NOTE that anonymous contexts will always appear in the execution 
        // stream and not in a symbol table.
    }

    // This is called when a "}" is encountered.
    void pop_context() {
        context.erase(context.find_last_of("@"), context.length());
    }

    // Called when the parser needs to see the current context.
    string get_context() {
        return context;
    }

    // This is called when the parser needs the actual name of a variable. For
    // example to store it in the symbol table.
    string make_context(string name) {
        temp_cont = context;
        temp_cont += "@";
        temp_cont += name;
        return temp_cont;
    }

private:
    string context;
    string temp_cont;
};

#endif /* _CONTEXT_H_ */