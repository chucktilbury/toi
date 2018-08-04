
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
        context = string("@");
    }
    ~Context() {}

    void push_context(string name) {
        context += "@";
        context += name;
    }

    void pop_context() {
        context.erase(context.find_last_of("@"), context.length());
    }

    string get_context() {
        return context;
    }

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