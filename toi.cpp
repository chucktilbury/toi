

#include "toi.h"

using namespace std;


int main(void) {

    Parser* parser = Parser::get_instance();
    SymTable* symtab;

    parser->init_parser("tests/test1.t");
    symtab = parser->load_program();
    symtab->dump();
    return 0;
}
 