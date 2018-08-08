#ifndef _TOI_H_
#define _TOI_H_

#include "file_stack.h"
#include "lexer.h"
#include "context.h"
#include "sym_table.h"

#include "parser.h"
#include "logging.h"

#define MARK(s) Logging(DEBUG) << "Mark: " << __FILE__ << ", " << __LINE__ << ", " << __func__ << " " << s
#define SYNTAX_ERR(e) Logging(SYNTAX) << "Expected a " << e << " but got a \"" << parser->get_token_str() << "\""
#define UNEXPECTED_EOF() Logging(SYNTAX) << "Unexpected end of file"

#include "parse_method_def.h"
#include "parse_import.h"
#include "parse_statements.h"

#endif /* _TOI_H_ */