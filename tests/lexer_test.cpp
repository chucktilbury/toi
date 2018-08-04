#include <stdio.h>
//#include "../file_stack.h"
#include "../lexer.h"
#include "../logging.h"

// Build from this directory as 
// g++ -Wall -Wextra -g -o ltest lexer_test.cpp ../file_stack.cpp ../logging.cpp ../lexer.cpp
// basic happy path test
int main(void) {

    Logging().set_loglevel(DEBUG);
    Logging(INFO) << "**** BEGIN test";

    Lexer* lexer = new Lexer();
    //FileStack* fstack = FileStack::get_instance();

    lexer_token_t tok;
    lexer->open_file("empty_file.txt");
    lexer->open_file("scanner_test1.txt");
    for(int i = 0; i < 10; i++) {
        tok = lexer->get_token();
        Logging(INFO) << "file: \"" << lexer->file_name() 
                        << "\" line: " << lexer->line_number()
                        << " token: " << lexer->tok_to_string(tok)
                        << " (" << tok << "): "
                        << lexer->token_string();
    }

    lexer->open_file("test1.simp");

    bool finished = false;
    while(!finished) {
        lexer_token_t tok;

        tok = lexer->get_token();
        Logging(INFO) << "file: \"" << lexer->file_name() 
                        << "\" line: " << lexer->line_number()
                        << " token: " << lexer->tok_to_string(tok)
                        << " (" << tok << "): "
                        << lexer->token_string();

        if(tok == END_INPUT)
            finished = true;
    }


    Logging(INFO) << "**** END test";

    return 0;
}

