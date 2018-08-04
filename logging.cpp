
#include <stdint.h>
#include "simple.h"

uint32_t Logging::warnings = 0;       // syntax warnings
uint32_t Logging::syntax_errors = 0;  // syntax errors
uint32_t Logging::errors = 0;         // system errors
typelog_t Logging::max_logging = DEBUG;  // change this to set the default
