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
  char* op_val;
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
%type <codenode> arg
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

functions: function{
//printf("function -> function\n");
//TODO
CodeNode *function = $1;
$$ = function;
}
| function functions {
//printf("function -> function functions\n");
//Should be done?
CodeNode *func1 = $1;
CodeNode *funcs = $2;
CodeNode *node = new CodeNode;
node->code = func1->code + funcs->code;
$$ = node;
}
;

function: FUNC ID L_PAREN args R_PAREN L_C_BRACKET statements R_C_BRACKET SEMICOLON {
//printf("function-> FUNC ID L_PAREN args R_PAREN L_C_BRACKET statments R_C_BRACKET SEMICOLON  \n");
CodeNode *node = new CodeNode;
std::string func_name = $2;
node->code ="";

// ADD Function NAME
node->code += std::string("func ") + func_name;

//add args
CodeNode *args = $4;
node->code += args->code;

//add statments
CodeNode *statements = $7;
node->code += statements->code;
$$ = node;
};

args: arg COMMA args {
//printf("arguments -> COMMA arguments\n");
//TODO
}
| arg {
//printf("arguments -> argument\n");
//TODO
CodeNode *arg = $1;
$$ = arg;
}
;

arg: %empty /*epsilon*/ {
//printf("argument -> epsilon\n");
CodeNode *ar = new CodeNode;
ar->code = std::string("\n");
$$ = ar;
}
| NUM ID {
//printf("argument -> NUM ID\n");
//TODO
}
;

statements: statement SEMICOLON {
//printf("statements -> statement SEMICOLON\n");
//SHOULD BE DONE
CodeNode *node = new CodeNode;
node->code = $1->code;
$$ = node;
}
| statement SEMICOLON statements {
//printf("statements -> statement SEMICOLON statement\n");
//SHOULD BE DONE
CodeNode *node = new CodeNode;
node->code = $1->code + $3->code;
$$ = node;
}
;

statement: declaration {
//printf("statment -> declaration\n");
//TODO
CodeNode *dec = $1;
$$ = dec;
}
| function_call {
//printf("statement-> function_call\n");
//TODO
}
| num {
//printf("statement->num\n");
//TODO
}
| if {
//printf("statement->if\n");
//TODO
}
| while {
//printf("statement->while\n");
//TODO
}
| for {printf("statement->for\n");}
| input {printf("statement->input\n");}
| output {printf("statement->output\n");}
| return {printf("statement->return\n");}
| ID ASSIGN exp  
{
//printf("statement->ID ASSIGN exp\n");
//TODO
std::string var_name = $1;

CodeNode *node = new CodeNode;
node->code = $3->code;
node->code += std::string("= ") + var_name + std::string(", ") + $3->name + std::string("\n");
$$ = node;
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
