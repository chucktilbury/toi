
#include "toi.h"

ParseMethodDef::ParseMethodDef() {
    ENTER();
    parser = Parser::get_instance();
}

ParseMethodDef::~ParseMethodDef() {
    ENTER();
}

bool ParseMethodDef::parse() {
    ENTER();
    return false;
}
 