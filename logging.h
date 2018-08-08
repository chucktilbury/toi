#ifndef _LOGGING_H_
#define _LOGGING_H_

#include <iostream>
#include <cstdlib>
#include <cstdint>

// for line numbers in error messages
#include "toi.h"

using namespace std;

typedef enum {
    DEBUG,
    INFO,
    WARN,
    ERROR,
    SYNTAX,
    INTERNAL,
    FATAL,
} typelog_t;

class Logging {
public:
    Logging() {}
    Logging(typelog_t type) {
        msglevel = type;
        if(msglevel == WARN || msglevel == SYNTAX) {
            Parser* psr = Parser::get_instance();
            operator << (getLabel(type)) << psr->file_name() << ": " << psr->line_number() << ": ";
        }
        else {
            operator << (getLabel(type));
        }
    }
    
    ~Logging() {
        if(opened) {
            cerr << endl;
        }
        opened = false;
        if(fatal)
            exit(1);
    }

    template<class T>
    Logging &operator<<(const T &msg) {
        if(msglevel >= max_logging) {
            cerr << msg;
            opened = true;
        }
        return *this;
    }

    int get_warnings(void) { return warnings; }
    int get_errors(void) { return errors; }
    int get_syntax_errors(void) { return syntax_errors; }
    void set_loglevel(typelog_t level) {max_logging = level; }

private:
    bool opened = false;
    typelog_t msglevel = DEBUG;
    bool fatal = false;

    inline string getLabel(typelog_t type) {
        string label;
        switch(type) {
            case DEBUG: 
                label = "Debug: "; 
                break;
            
            case INFO:  
                label = "Info:  "; 
                break;
            
            case WARN:  
                label = "Warning: "; 
                warnings++;
                break;
            
            case SYNTAX: 
                label = "Syntax Error: "; 
                syntax_errors++;
                break;
            
            case ERROR: 
                label = "Sys Error: "; 
                errors++;
                break;
            
            case INTERNAL: 
                label = "Internal Error: "; 
                fatal = true;
                break;

            case FATAL: 
                label = "Fatal Error: "; 
                fatal = true;
                break;
        }
        return label;
    }

    // these retain their value across instances.
    static uint32_t warnings;
    static uint32_t syntax_errors;
    static uint32_t errors;
    static typelog_t max_logging;
};

#endif /* _LOGGING_H_ */