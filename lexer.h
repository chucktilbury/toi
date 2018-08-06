#ifndef _LEXER_H_
#define _LEXER_H_

#include <string>
#include "toi.h"

using namespace std;

typedef enum
{
    ILLEGAL = -1,
    NUMERIC,    // [0-9\.] Note that the dot depends on the state
    SYMCHARS,   // [_$@?!A-Za-z]
    SQUOTE,     // \'
    DQUOTE,     // \"
    HASH,       // # comment char
    SINGLES,    // [\(\)\{\}\[\]\,\;\:\.]
    WHITESP,     // ' ', '\t', '\n', '\r'
    END_OF_INPUT,
    END_OF_CONTEXT
} character_types_t;

typedef enum  
{
    ERROR_TOKEN = -1,

    // type name tokens
    NUM = 1000, // num
    STRG,   // strg
    BOOL,   // bool
    IMPORT, // import

    // flow control tokens
    RETURN, // return
    BREAK,  // break
    CONT,   // continue
    IF,     // if
    ELSE,   // else
    WHILE,  // while
    FOR,    // for
    SWITCH, // switch
    CASE,   // case
    STRUCT, // struct
    // NOTHING,// nothing // no such thing as nothing?

    // boolean builtin function names
    OR,     // or
    AND,    // and
    NOT,    // not
    EQ,     // eq
    NEQ,    // neq
    MORE,   // more
    LESS,   // less

    // boolean values
    TRUE,   // true or yes
    FALSE,  // false or no

    // syntax tokens
    OPAREN,     // (
    CPAREN,     // )
    OCURLY,     // {
    CCURLY,     // }
    OBOX,       // [
    CBOX,       // ]
    COMMA,      // ,
    SCOLON,     // ;
    DOT,        // .    
    COLON,      // :

    // arithmetic tokens
    PLUS,       // +
    MINUS,      // -
    MULT,       // *
    DIV,        // /
    MODULO,     // %
    ASSIGN,     // =

    // constructed tokens
    SYMBOL, // [_$@?!A-Za-z]+[_$@?!A-Za-z0-9]*
    NUMBER, // [0-9]+|[0-9]+\.[0-9]+|0x[0-9A-Fa-f]+
    STRING, // \'\.\'|\"\.\"

    // unused tokens for now.
    // will be bitwise operators
    TILDE,      // ~ negate
    PIPE,       // | or 
    AMPER,      // & and
    CARAT,      // ^ xor

    // These will always be illegal
    BANG,       // !    
    GRAVE,      // `
    BACKSLASH,  // "\"

    // Signal the end of all input
    END_CONTEXT,
    END_INPUT,

} lexer_token_t;

#define MAX_TOK_LEN (1024*64)

class Lexer {

public:
    Lexer();
    ~Lexer();
    lexer_token_t get_token(void);
    const char* token_string(void) { return token_buffer; }
    string tok_to_string(lexer_token_t tok);
    int expect_token(string& str, lexer_token_t exp, lexer_token_t tok);
    string file_name(void) { return file_stack->file_name(); }
    int line_number(void) { return line_no; }
    void open_file(string name) { file_stack->file_open(name); }

private:
    struct singles_table {
        int ch;
        lexer_token_t tok;
    } singles_table[22] = {
        {'(', OPAREN},
        {')', CPAREN},
        {'{', OCURLY},
        {'}', CCURLY},
        {'[', OBOX},
        {']', CBOX},
        {',', COMMA},
        {';', SCOLON},
        {'.', DOT},
        {':', COLON},
        {'+', PLUS},
        {'-', MINUS},
        {'*', MULT},
        {'/', DIV},
        {'%', MODULO},
        {'=', ASSIGN},
        {'~', TILDE},
        {'|', PIPE},
        {'&', AMPER},
        {'^', CARAT},
        {0, ERROR_TOKEN}
    };

    struct symtok_table {
        string sym;
        lexer_token_t tok;
    } symtok_table[30] = {
        {"num", NUM},
        {"strg", STRG},
        {"bool", BOOL},
        {"return", RETURN},
        {"break", BREAK},
        {"continue", CONT},
        {"if", IF},
        {"else", ELSE},
        {"while", WHILE},
        {"for", FOR},
        {"switch", SWITCH},
        {"case", CASE},
        {"struct", STRUCT},
        {"or", OR},
        {"and", AND},
        {"not", NOT},
        {"eq", EQ},
        {"neq", NEQ},
        {"more", MORE},
        {"less", LESS},
        {"import", IMPORT},
        {"YES", TRUE},
        {"TRUE", TRUE},
        {"NO", FALSE},
        {"FALSE", FALSE},
        {"yes", TRUE},
        {"true", TRUE},
        {"no", FALSE},
        {"false", FALSE},
        {"", ERROR_TOKEN}
    }; 

    character_types_t char_type_table[256];
    char token_buffer[MAX_TOK_LEN];
    int token_buffer_index = 0;
    FileStack* file_stack;
    int line_no;

    int add_token_char(const char ch);
    void get_comment(void);
    lexer_token_t get_sstrg(void);
    int convert_hex(void);
    int transform_escape(void);
    lexer_token_t get_dstrg(void);
    lexer_token_t get_single(int ch);
    lexer_token_t get_hex_number(void);
    lexer_token_t get_dec_number(int ch);
    lexer_token_t get_numeric(int ch);
    lexer_token_t get_symchar(int ch);

};

#endif /* _LEXER_H_ */