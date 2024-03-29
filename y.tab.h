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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    MOD = 258,
    RETURN = 259,
    INPUT = 260,
    OUTPUT = 261,
    NUMBER = 262,
    NUM = 263,
    WHILE = 264,
    IF = 265,
    ELIF = 266,
    ELSE = 267,
    FUNC = 268,
    PLUS = 269,
    MINUS = 270,
    MULTI = 271,
    DIVISION = 272,
    LESS = 273,
    GREATER = 274,
    EQUAL = 275,
    NOT_EQUAL = 276,
    LE_EQ = 277,
    GE_EQ = 278,
    COMMENT = 279,
    L_BRACKET = 280,
    R_BRACKET = 281,
    L_C_BRACKET = 282,
    R_C_BRACKET = 283,
    L_PAREN = 284,
    R_PAREN = 285,
    ASSIGN = 286,
    SEMICOLON = 287,
    COMMA = 288,
    FOR = 289,
    BREAK = 290,
    CONTINUE = 291,
    ID = 292
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 102 "bajj-er_parse.y" /* yacc.c:1909  */

  char* op_val;
  struct CodeNode *codenode;

#line 97 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
