%{
#include <stdio.h>
extern FILE* yyin;
%}
%start prog_start
%token RETURN INPUT OUTPUT NUMBER NUM WHILE IF ELIF ELSE FUNC ID PLUS MINUS MULTI DIVISION LESS GREATER EQUAL NOT_EQUAL LE_EQ GE_EQ COMMENT L_BRACKET R_BRACKET L_C_BRACKET R_C_BRACKET L_PAREN R_PAREN ASSIGN SEMICOLON COMMA

%%
prog_start : %empty {printf("prog_start->epsilon");}
| functions {printf("prog_start->functions");}   
;

functions: function
| function functions
;

function: FUNC ID L_PARENT args R_PARENT L_C_BRACKET statments R_C_BRACKET SEMICOLON {printf("function-> FUNC ID L_PARENT args R_PARENT L_C_BRACKET statments R_C_BRACKET SEMICOLON  ");};

args: arg COMMA args
| arg
;

arg: %empty
| NUM ID
;
%%
