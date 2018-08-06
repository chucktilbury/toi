
#include "toi.h"

ParseImport::ParseImport() {
    ENTER();
    parser = Parser::get_instance();

}

ParseImport::~ParseImport() {
    ENTER();
}

bool ParseImport::parse() {
    ENTER();
    return false; 
}

