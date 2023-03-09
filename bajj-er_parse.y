%{
#include "CodeNode.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "y.tab.h"

extern FILE* yyin;
extern int yylex(void);
void yyerror(const char *msg);
extern int yyparse();
//extern int currline;
extern int linenum;

char *identToken;
int numberToken;
%}

%union {
 struct{
  char *op_val;
 };
  struct CodeNode *codenode;
}

%define parse.error verbose
%start prog_start
%token RETURN INPUT OUTPUT NUMBER NUM WHILE IF ELIF ELSE FUNC PLUS MINUS MULTI DIVISION LESS GREATER EQUAL NOT_EQUAL LE_EQ GE_EQ COMMENT L_BRACKET R_BRACKET L_C_BRACKET R_C_BRACKET L_PAREN R_PAREN ASSIGN SEMICOLON COMMA FOR

%token <op_val> ID
%type <codenode> function
%type <codenode> functions
%type <codenode> declaration
%type <codenode> statement
%type <codenode> statements
%type <codenode> factor
%type <codenode> args
%type <codenode> exp
%type <op_val> NUMBER

%%
prog_start : %empty {
//printf("prog_start->epsilon\n");
	printf("/n");
}

| functions {
//printf("prog_start->functions\n");
CodeNode *code_node = $1;
printf("%s\n", code_node->code.c_str());

}   
;

functions: function{printf("function -> function\n");}
| function functions {printf("function -> function functions\n");}
;

function: FUNC ID L_PAREN args R_PAREN L_C_BRACKET statements R_C_BRACKET SEMICOLON {printf("function-> FUNC ID L_PAREN args R_PAREN L_C_BRACKET statments R_C_BRACKET SEMICOLON  \n");};

args: arg COMMA args {printf("arguments -> COMMA arguments\n");}
| arg {printf("arguments -> argument\n");}
;

arg: %empty /*epsilon*/ {printf("argument -> epsilon\n");}
| NUM ID {printf("argument -> NUM ID\n");}
;

statements: statement SEMICOLON {printf("statements -> statement SEMICOLON\n");}
| statement SEMICOLON statements {printf("statements -> statement SEMICOLON statement\n");}
;

statement: declaration {printf("statment -> declaration\n");}
| function_call {printf("statement-> function_call\n");}
| num {printf("statement->num\n");}
| if {printf("statement->if\n");}
| while {printf("statement->while\n");}
| for {printf("statement->for\n");}
| input {printf("statement->input\n");}
| output {printf("statement->output\n");}
| return {printf("statement->return\n");}
| ID ASSIGN exp  
{
printf("statement->ID ASSIGN exp\n");
}   
;

return: RETURN ID {printf("return->RETURN ID\n");}     
| RETURN exp {printf("return->RETURN EXP\n");} 
;

num: NUM ID ASSIGN exp{printf("num -> NUM ID ASSIGN exp\n");}
| NUM ID ASSIGN NUMBER {printf("num -> NUM ID ASSIGN NUMBER\n");}
| NUM ID ASSIGN function_call {printf("num -> NUM ID ASSIGN function_call\n");}
;

if: IF bool_exp L_C_BRACKET statements elsify R_C_BRACKET {printf("if -> IF bool_exp L_C_BRACKET statements R_C_BRACKET elsify\n");}
;

elsify: elif SEMICOLON elsify {printf("elsify -> elif SEMICOLON elsify\n");}
| else SEMICOLON{printf("elsify -> else SEMICOLON\n");}
| %empty {printf("elsify->epsilon\n");}
;

elif: ELIF bool_exp L_C_BRACKET statements R_C_BRACKET {printf("elif -> elif bool_exp L_C_BRACKET statements R_C_BRACKET\n");}
;

else: ELSE L_C_BRACKET statements R_C_BRACKET {printf("else -> else L_C_BRACKET statements R_C_BRACKET\n");}
;

while: WHILE bool_exp L_C_BRACKET statements R_C_BRACKET {printf("while -> WHILE bool_exp L_C_BRACKET statement R_C_BRACKET\n");}
;

for: FOR num SEMICOLON bool_exp ID ASSIGN exp L_C_BRACKET statements R_C_BRACKET{printf("for -> FOR num ASSIGN NUMBER SEMICOLON bool_exp SEMICOLON num ASSIGN exp L_C_BRACKET statements R_C_BRACKET\n");}
;

input: INPUT L_PAREN exp R_PAREN {printf("input -> INPUT L_PAREN num_list R_PAREN\n");}
; 

output: OUTPUT L_PAREN exp R_PAREN {printf("output -> OUTPUT L_PAREN num_list R_PAREN\n");}
;


exp: exp add_op term
|term {printf("exp -> term\n");}
;

bool_exp: L_PAREN exp comp exp R_PAREN {printf("bool_exp -> L_PAREN exp comp exp R_PAREN\n");}
;

comp: LESS {printf("comp -> LESS\n");}
| GREATER {printf("comp -> GREATER\n");}
| EQUAL {printf("comp -> EQUAL\n");}
| LE_EQ {printf("comp -> LE_EQ\n");}
| GE_EQ {printf("comp -> GE_EQ\n");}
| NOT_EQUAL {printf("comp -> NOT_EQUAL\n");}
;

add_op: PLUS 
| MINUS
;

term: term mulop factor {printf("term -> term mulop factor\n");}
| factor {printf("term -> factor\n");}
;

mulop: MULTI {printf("mulop -> MULTI\n");}
| DIVISION {printf("mulop -> DIVISION\n");}
;

factor: L_PAREN exp R_PAREN  {printf("factor->L_PAREN exp R_PAREN\n");}
| NUMBER {printf("factor->NUMBER\n");}
| ID {printf("factor -> ID\n");}
| function_call {printf("factor -> function_call\n");}   
;

declaration: NUM ID {
//printf("declaration -> NUM ID\n");
std::string var_name = $2;
//std::cout << var_name << std::endl;
CodeNode *numDec = new CodeNode;
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
$$ = numDec;
}
;

function_call: ID L_PAREN exp R_PAREN {printf("function_call -> ID L_PAREN exp R_PAREN\n");}
;

%%

int  main() {
yyin = stdin;
do{
  yyparse();
}
while(!feof(yyin));
return 0;
}
 void yyerror (char const *s) {
   //fprintf (stderr, "This is an error: %s at line %d \n", s, linenum);
	
   printf("** Line %d: %s\n", linenum,s);
 }
