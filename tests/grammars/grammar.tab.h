/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_GRAMMAR_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NUM = 258,
    STRG = 259,
    BOOL = 260,
    IMPORT = 261,
    RETURN = 262,
    BREAK = 263,
    CONT = 264,
    IF = 265,
    ELSE = 266,
    WHILE = 267,
    FOR = 268,
    SWITCH = 269,
    CASE = 270,
    OR = 271,
    AND = 272,
    NOT = 273,
    EQ = 274,
    NEQ = 275,
    MORE = 276,
    LESS = 277,
    TRUE = 278,
    FALSE = 279,
    OPAREN = 280,
    CPAREN = 281,
    OCURLY = 282,
    CCURLY = 283,
    OBOX = 284,
    CBOX = 285,
    COMMA = 286,
    SCOLON = 287,
    DOT = 288,
    COLON = 289,
    PLUS = 290,
    MINUS = 291,
    MULT = 292,
    DIV = 293,
    MODULO = 294,
    ASSIGN = 295,
    SYMBOL = 296,
    NUMBER = 297,
    STRING = 298,
    TILDE = 299,
    PIPE = 300,
    AMPER = 301,
    CARAT = 302,
    END_CONTEXT = 303,
    END_INPUT = 304
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_GRAMMAR_TAB_H_INCLUDED  */
