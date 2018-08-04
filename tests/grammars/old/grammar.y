/*
    This file contains the official grammar for Simple. It is not used in the 
    system. It is here to clarify and illustate only. It is in the form of a 
    compilable Bison grammar.

    Build as: "bison -dtr all  grammar.y"

    TODO:
        * Add list and dict syntax
        * Add class syntax
*/
%{

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

%}

    /* list all terminals */
%token NUM STRG BOOL IMPORT RETURN BREAK CONT IF ELSE WHILE FOR SWITCH CASE
%token OR AND NOT EQ NEQ MORE LESS TRUE FALSE OPAREN CPAREN OCURLY CCURLY
%token OBOX CBOX COMMA SCOLON DOT COLON PLUS MINUS MULT DIV MODULO ASSIGN
%token SYMBOL NUMBER STRING TILDE PIPE AMPER CARAT END_CONTEXT END_INPUT STRUCT
    /* todo: class */

%%

module
    : module_element
    | module module_element
    ;

module_element
    : import_directive
    | var_definition
    | function_definition
    | struct_definition
    ;

struct_definition
    : STRUCT SYMBOL OCURLY struct_body_list CCURLY SCOLON   
    ;

struct_body_list
    : struct_body
    | struct_body struct_body_list
    ;

struct_body
    : NUM COLON SYMBOL SCOLON
    | STRG COLON SYMBOL SCOLON
    | BOOL COLON SYMBOL SCOLON
    ;

import_directive
    : IMPORT STRING SCOLON
    ;

var_definition
    : NUM COLON SYMBOL ASSIGN NUMBER SCOLON
    | STRG COLON SYMBOL ASSIGN STRING SCOLON
    | BOOL COLON SYMBOL ASSIGN TRUE SCOLON
    | BOOL COLON SYMBOL ASSIGN FALSE SCOLON
    ;

function_definition
    : SYMBOL function_def_parameters statement_group
    ;

function_def_parameters
    : OPAREN fd_parameter_list CPAREN OPAREN fd_parameter_list CPAREN
    ;

fd_parameter
    : /* could be blank */
    | NUM COLON SYMBOL
    | STRG COLON SYMBOL
    | BOOL COLON SYMBOL
    | STRUCT COLON SYMBOL
    ;

fd_parameter_list
    : fd_parameter
    | fd_parameter COMMA fd_parameter_list
    ;

statement_group
    : OCURLY statement_list CCURLY
    ;

statement_list
    : statement
    | statement statement_list
    ;

statement
    : var_definition
    | var_assignment
    | function_call
    | if_statement
    | while_statement
    | for_statement
    | switch_statement
    | struct_definition
    | RETURN SCOLON
    | statement_group
    ;

var_assignment
    : SYMBOL ASSIGN expression SCOLON
    ;

function_call
    : SYMBOL function_call_parameters SCOLON
    ;

function_call_parameters
    : OPAREN fc_parameter_list CPAREN OPAREN fc_parameter_list CPAREN
    ;

fc_parameter_list
    : /* parameter list could be blank */
    | fc_parameter
    | fc_parameter COMMA fc_parameter_list
    ;

fc_parameter
    : SYMBOL
    | arith_expression
    | string_expression
    | TRUE
    | FALSE
    /* | boolean_expression */ /* adding this creates 3 reduce/reduce conflicts */
    ;   /* needs to find a way to add bool expressions here */

expression
    : boolean_expression
    | arith_expression
    | string_expression
    ;

string_expression
    : STRING
    | STRING PLUS string_element_list
    ;

string_element_list
    : string_element
    | string_element PLUS string_element_list
    ;

string_element
    : STRING
    | SYMBOL
    | NUMBER
    | TRUE
    | FALSE
    ;

    /* rework this */
boolean_expression
    : /* empty expression is taken as true */
    | TRUE
    | FALSE
    | boolean_function OPAREN boolean_factor COMMA boolean_factor CPAREN
    | NOT OPAREN boolean_factor CPAREN
    ;

boolean_factor
    : boolean_expression
    | arith_expression
    | STRING
    | SYMBOL
    ;

boolean_function
    : EQ
    | NEQ
    | MORE
    | LESS
    | OR
    | AND
    ;

    /* 
        This is a normal arithmetic expression with all of the normal
        rules or precidence.

        Note the left recursion. 
    */
arith_expression
    : arith_expression PLUS arith_term
    | arith_expression MINUS arith_term
    | arith_term
    ;

arith_term  
    : arith_term MULT arith_factor
    | arith_term DIV arith_factor
    | arith_term MODULO arith_factor
    | arith_factor
    ;

arith_factor
    : MINUS arith_factor
    | OPAREN arith_expression CPAREN
    | NUMBER
    | SYMBOL    /* this creates 2 reduce/reduce conflicts */
    ;

    /*
        This is similar to the if clause in other languages except that
        an empty expression is taken as true, so the last else should have 
        an empty expression if you want that to be taken in any case.
        For example:
        if(eq(1,2)) {}
        else(eq(1,3)) {}
        else(){} # This one is taken.
    */
if_statement
    : IF OPAREN boolean_expression CPAREN statement_group else_clause_list
    | IF OPAREN boolean_expression CPAREN statement_group
    ;

else_clause_list
    : else_clause
    | else_clause else_clause_list
    ;

else_clause
    : ELSE OPAREN boolean_expression CPAREN statement_group
    ;

    /* 
        List of loop_statement with the curly braces added.
    */
loop_statement_group
    : OCURLY loop_statement_list CCURLY
    ;

    /* 
        List of loop_statement.
    */
loop_statement_list
    : loop_statement
    | loop_statement loop_statement_list
    ;

    /* 
        Same as a statement above but with the additions of the break
        and continue keywords.
    */
loop_statement
    : statement
    | CONT SCOLON
    | BREAK SCOLON
    ;

    /*
        This is similar to a while() in other languages. For example:
        num:val = 0;
        while(less(val, 10)) {val = val + 1;}

        Remember that an empty boolean expression is taken as true, so
        the statements while(1){} and while(){} are equivalent.
    */
while_statement
    : WHILE OPAREN boolean_expression CPAREN loop_statement_group
    ;

    /*
        This is similar to a for() in C, for example:
        for(num:val=0; less(val, 10); val = val + 1) {}
    */
for_statement
    : FOR OPAREN var_assignment SCOLON boolean_expression SCOLON arith_expression CPAREN loop_statement_group 
    ;

    /*
        Switch/case works a little differently than other languages. It's really
        a form of an if clause where the case statements are tested for equality
        to the parameter to switch. The first one that matches is taken. An optional
        else clause can be added to the end that serves are a "default:" case in
        the C language. The else is evaluated as a stand-alone boolean expression.
        For example:
        switch(1) {
            case(0) {}
            case(1) {} # This is the one
            case(2) {}
        }
        else() { # This is not taken, even though an empty boolean expression is
                 # taken as true becasue one of the case(s) was taken.
        }
    */
switch_statement
    : SWITCH OPAREN SYMBOL CPAREN OCURLY case_clause_list CCURLY
    | SWITCH OPAREN SYMBOL CPAREN OCURLY case_clause_list CCURLY else_clause
    ;

case_clause_list
    : case_clause
    | case_clause case_clause_list
    ;

case_clause
    : CASE OPAREN SYMBOL CPAREN statement_group   
    | CASE OPAREN NUMBER CPAREN statement_group   
    | CASE OPAREN STRING CPAREN statement_group   
    | CASE OPAREN TRUE CPAREN statement_group   
    | CASE OPAREN FALSE CPAREN statement_group   
    ;

%%
