// TODO: detect and flag unterminated quotes.
// TODO: struct

#include <iomanip>

#include <string>
#include <cstring>

#include "toi.h"

// convert the case of a letter, but leave other characters unchanged
#define TOUPPER(c) (((c)>='a'&&(c)<='z')?(c)-('a'-'A'):(c))
#define TOLOWER(c) (((c)>='A'&&(c)<='Z')?(c)+('a'-'A')):(c))
// 1 if the char fits in a hex number
#define ISXCHAR(c) (((c)>='0'&&(c)<='9')||((c)>='a'&&(c)<='f')||((c)>='A'&&(c)<='F')?1:0)
// convert the hex digit to binary value
#define XCHARVAL(c) (((c)>='0'&&(c)<='9')?(c)-'0':(TOUPPER(c)-('A'-10)))
// convert a 2 digit hex number to its binary value
// Need to add logic to validate the string before converting.
#define CONV2DIGIT(s) (XCHARVAL((s)[0])<<4|XCHARVAL((s)[1]))
// format a char so that we can print it in hex


static string uchar2hex(unsigned char inchar)
{
  ostringstream oss (ostringstream::out);
  oss << setw(2) << setfill('0') << hex << (int)(inchar);
  return oss.str();
}

/*
    Public interface
*/


Lexer::Lexer() { 

    int i;
    const char* singles = "(){}[],;.:=+-/*%%";
    const char* symchars = "_?!";
    const char* whitesp = " \t\n\r";

    for(i = 0; i < 256; i++)
        char_type_table[i] = ILLEGAL;
    
    for(i = '0'; i <= '9'; i++)
        char_type_table[i] = NUMERIC;
    
    for(i = 0; singles[i] != 0; i++)
        char_type_table[(int)singles[i]] = SINGLES;

    for(i = 0; whitesp[i] != 0; i++)
        char_type_table[(int)whitesp[i]] = WHITESP;

    for(i = 0; symchars[i] != 0; i++)
        char_type_table[(int)symchars[i]] = SYMCHARS;

    for(i = 'a'; i <= 'z'; i++)
        char_type_table[i] = SYMCHARS;
    
    for(i = 'A'; i <= 'Z'; i++)
        char_type_table[i] = SYMCHARS;

    char_type_table['#'] = HASH;
    char_type_table['\''] = SQUOTE;
    char_type_table['\"'] = DQUOTE;
    char_type_table[0] = END_OF_INPUT;
    char_type_table[1] = END_OF_CONTEXT;

    file_stack = new FileStack();
}

Lexer::~Lexer() {
    delete file_stack;
}

lexer_token_t Lexer::get_token(void) {

    int ch;
    bool finished = false;
    lexer_token_t retv = ERROR_TOKEN;


    memset(token_buffer, 0, sizeof(token_buffer));
    token_buffer_index = 0;
    // line number of the token, not the character
    line_no = file_stack->line_number(); 
    while(!finished)
    {
        ch = file_stack->read_character();
        finished = true;
        switch(char_type_table[ch])
        {
            case WHITESP:   
                finished = false;
                break;  // ignore all white space

            case HASH:      
                get_comment();  
                finished = false;
                break;  // ignore comments

            case SQUOTE:    
                retv = get_sstrg();     // return a string with no interpretation
                break;

            case DQUOTE:    
                retv = get_dstrg();     // return a string with escapes
                break;

            case SINGLES:   
                retv = get_single(ch);  // return a single 
                // bug fix where line number was not appearing correctly when a 
                // single was the first token on the line.
                line_no = file_stack->line_number(); 
                break;

            case NUMERIC:   
                retv = get_numeric(ch); // return a numeric
                break;

            case SYMCHARS:  
                retv = get_symchar(ch); // return a keyword or a symbol
                break;

            case END_OF_CONTEXT: 
                retv = END_CONTEXT;
                break;

            case END_OF_INPUT: 
                retv = END_INPUT;
                break;

            default:
                Logging(WARN) << "illegal character in input file: 0x" << uchar2hex(ch) << ": IGNORED";
                // eat the character and move on
        }
    }

    Logging(DEBUG) << "token returned: " << token_buffer;
    return retv;
}

int Lexer::expect_token(string& str, lexer_token_t exp, lexer_token_t tok) {
    
    if(tok != exp)
    {
        Logging(SYNTAX) << "Expected a \"" << str << "\" but got a \"" << token_string() << "\"";
        return 1;
    }
    return 0;
}

static struct
{
    lexer_token_t tok;
    string strg;
} tok_to_str_table[] = {
    {ERROR_TOKEN, "ERROR_TOKEN"},
    {NUM, "NUM"},
    {STRG, "STRG"},
    {BOOL, "BOOL"},
    {RETURN, "RETURN"},
    {BREAK, "BREAK"},
    {CONT, "CONT"},
    {IF, "IF"},
    {ELSE, "ELSE"},
    {WHILE, "WHILE"},
    {FOR, "FOR"},
    {SWITCH, "SWITCH"},
    {CASE, "CASE"},
    {STRUCT, "STRUCT"},
    {OR, "OR"},
    {AND, "AND"},
    {NOT, "NOT"},
    {EQ, "EQ"},
    {NEQ, "NEQ"},
    {MORE, "MORE"},
    {LESS, "LESS"},
    {TRUE, "TRUE"},
    {FALSE, "FALSE"},
    {IMPORT, "IMPORT"},
    {OPAREN, "OPAREN"},
    {CPAREN, "CPAREN"},
    {OCURLY, "OCURLY"},
    {CCURLY, "CCURLY"},
    {OBOX, "OBOX"},
    {CBOX, "CBOX"},
    {COMMA, "COMMA"},
    {SCOLON, "SCOLON"},
    {DOT, "DOT"},
    {COLON, "COLON"},
    {PLUS, "PLUS"},
    {MINUS, "MINUS"},
    {MULT, "MULT"},
    {DIV, "DIV"},
    {MODULO, "MODULO"},
    {ASSIGN, "ASSIGN"},
    {SYMBOL, "SYMBOL"},
    {NUMBER, "NUMBER"},
    {STRING, "STRING"},
    {TILDE, "TILDE"},
    {PIPE, "PIPE"},
    {AMPER, "AMPER"},
    {CARAT, "CARAT"},
    {BANG, "BANG"},
    {GRAVE, "GRAVE"},
    {BACKSLASH, "BACKSLASH"},
    {END_CONTEXT, "END_CONTEXT"},
    {END_INPUT, "END_INPUT"},
    {ERROR_TOKEN, ""}
};

string Lexer::tok_to_string(lexer_token_t tok)
{
    
    int i;

    for(i = 0; tok_to_str_table[i].tok != 0; i++)
    {
        if(tok == tok_to_str_table[i].tok)
            return tok_to_str_table[i].strg;
    }
    
    return "Unknown";
}


/*
    Private methods 
*/

int Lexer::add_token_char(const char ch)
{
    int retv = 1;
    if((size_t)(token_buffer_index+2) > sizeof(token_buffer)/sizeof(int))
    {
        Logging(FATAL) << "token size has overrun the token buffer";
        retv = 0;
    }
    else
    {
        token_buffer[token_buffer_index] = ch;
        token_buffer_index++;
    }

    return retv;
}

void Lexer::get_comment(void)
{
    // when this is entered, there has been a '#' read. read until the next 
    // '#' or until a newline is found.
    int ch;

    do 
    {
        ch = file_stack->read_character();
    } while(ch != '#');    // BEWARE OF THE MAC USERS!
}

lexer_token_t Lexer::get_sstrg(void)
{
    // When this is entered, there was a '\'' read. Simply copy the characters
    // that are found into the new string with no checking at all, including for 
    // new lines.
    int ch;

    do
    {
        ch = file_stack->read_character();
        if(ch == '\'')
            break;
    } while(add_token_char(ch));

    return STRING;
}

int Lexer::convert_hex(void)
{
    // When this is entered, the string "\x" has been read and now we will 
    // convert exactly 2 hex digits to a character and return the character.
    int ch;
    char tbuf[3] = {0, 0, 0};

    ch = file_stack->read_character();
    if(ISXCHAR(ch))
        tbuf[0] = ch;
    else 
        return -1;

    ch = file_stack->read_character();
    if(ISXCHAR(ch))
        tbuf[1] = ch;
    else 
        return -1;

    return CONV2DIGIT(tbuf);
}

int Lexer::transform_escape(void)
{
    // When this is entered, a string escape has been found. This state machine
    // handles it and copies the correct thing to the output. All of the standard
    // C escapes are handled plus ones with the format "\xnn" where nn is a hex
    // number.
    int ch;

    ch = file_stack->read_character();
    switch(ch)
    {
        case 'a':   return '\a';
        case 'b':   return '\b';
        case 'f':   return '\f';
        case 'n':   return '\n';
        case 'r':   return '\r';
        case 't':   return '\t';
        case 'v':   return '\v';
        case 'x':   
        case 'X':   return convert_hex();
        default:    return ch;
    }
    return 0;   // keep dumb compilers happy
}

lexer_token_t Lexer::get_dstrg(void)
{
    // When this is entered, a '\"' has been read. Copy the string into the token
    // buffer, transforming the normal escapes as required. Newlines and spaces are 
    // read and stored as any other character.
    int ch;

    do
    {
        ch = file_stack->read_character();
        if(ch == '\\') 
            ch = transform_escape();
        else if(ch == '\"')
            break;
    } while(add_token_char(ch));

    return STRING;
}

lexer_token_t Lexer::get_single(int ch)
{
    int i;

    // find the token in the list
    for(i = 0; singles_table[i].ch != 0; i++)
        if(ch == singles_table[i].ch) 
        {
            add_token_char(ch);
            return singles_table[i].tok;
        }
    
    // should never happen
    file_stack->unread_character(ch);
    return ERROR_TOKEN;
}

lexer_token_t Lexer::get_hex_number(void)
{
    // read a hex number
    int ch;

    add_token_char('0');
    add_token_char('x');
    do
    {
        ch = file_stack->read_character();
        if(!ISXCHAR(ch))
        {   // note that there is no limit to the size of the token. That
            // is the domain of the parser.
            file_stack->unread_character(ch);
            break;
        }

    } while(add_token_char(TOUPPER(ch)));

    return NUMBER;
}

lexer_token_t Lexer::get_dec_number(int ch)
{
    int nch;
    int dot_seen = 0;

    add_token_char(ch);
    do
    {
        nch = file_stack->read_character();
        if(char_type_table[nch] != NUMERIC)
        {
            if(nch == '.')
            {
                if(0 != dot_seen)
                {
                    file_stack->unread_character(nch);
                    Logging(SYNTAX) << "floating point number may have only one decimal point.";
                    return ERROR_TOKEN;
                }
                else
                    dot_seen++;
            }
            else
            {
                // finished
                file_stack->unread_character(nch);
                break;
            }
        }

    } while(add_token_char(nch));

    return NUMBER;
}

lexer_token_t Lexer::get_numeric(int ch)
{
    // when this is entered, a NUMERIC has been read. If the numberic was a zero
    // then scan ahead to see if it's a hex number and read a hex if it is. 
    // Otherwise, read a decimal number.
    int nch;

    if(ch == '0')
    {
        nch = file_stack->read_character();
        if(nch == 'x' || nch == 'X')
        {
            return get_hex_number();
        }
        else
        {
            file_stack->unread_character(ch);
            return get_dec_number(ch);
        }
    }
    else
        return get_dec_number(ch);
}

lexer_token_t Lexer::get_symchar(int ch)
{
    // when this is entered, a character that is acceptable for a symbol has 
    // been scanned. The thing could be a reserved word, or it could be a 
    // name of a user-defined symbol. 
    int nch, i;

    add_token_char(ch);
    do
    {
        nch = file_stack->read_character();
        if(char_type_table[nch] != SYMCHARS && char_type_table[nch] != NUMERIC)
        {
            file_stack->unread_character(nch);
            break;
        }
    } while(add_token_char(nch));

    for(i = 0; symtok_table[i].tok != ERROR_TOKEN; i++)
    {
        if(!strcmp((const char*)token_buffer, symtok_table[i].sym.c_str()))
            return symtok_table[i].tok;
    }

    return SYMBOL;
}
