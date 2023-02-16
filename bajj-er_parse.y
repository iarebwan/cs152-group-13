%{
#include <stdio.h>
extern FILE* yyin;
%}
%start prog_start
%token RETURN INPUT OUTPUT NUMBER NUM WHILE IF ELIF ELSE FUNC ID PLUS MINUS MULTI DIVISION LESS GREATER EQUAL NOT_EQUAL LE_EQ GE_EQ COMMENT L_BRACKET R_BRACKET L_C_BRACKET R_C_BRACKET L_PAREN R_PAREN ASSIGN SEMICOLON COMMA FOR

%%
prog_start : %empty {printf("prog_start->epsilon");}
| functions {printf("prog_start->functions");}   
;

functions: function{printf("function -> function");}
| function functions {printf("function -> function functions\n");}
;

function: FUNC ID L_PAREN args R_PAREN L_C_BRACKET statements R_C_BRACKET SEMICOLON {printf("function-> FUNC ID L_PAREN args R_PAREN L_C_BRACKET statments R_C_BRACKET SEMICOLON  ");};

args: arg COMMA args {printf("arguments -> COMMA arguments\n");}
| arg {printf("arguments -> argument\n");}
;

arg: %empty /*epsilon*/ {printf("argument -> epsilon\n");}
| NUM ID {printf("argument -> NUM ID\n");}
;

statements: statement SEMICOLON {printf("statements -> statement SEMICOLON\n");}
| statement SEMICOLON statements {printf("statements -> statement SEMICOLON statement\n");}
;

statement: 	declaration 
		{printf("statment -> declaration\n");}
		| function_call
		  {printf("statement-> function_call\n");}
		| num
	  	  {printf("statement->num\n");}
	  	| if
		  {printf("statement->if\n");}
		| while
		  {printf("statement->while\n");}
		| for
		  {printf("statement->for\n");}
		| input
		  {printf("statement->input\n");}
		| output
		  {printf("statement->output\n");}
;

num: NUM ID ASSIGN exp{printf("num -> NUM ID ASSIGN exp\n");}
| NUM ID ASSIGN NUMBER {printf("num -> NUM ID ASSIGN NUMBER\n");}
| NUM ID ASSIGN function_call {printf("num -> NUM ID ASSIGN function_call\n");}
;

if: IF bool_exp L_C_BRACKET statements R_C_BRACKET {printf("if -> IF bool_exp L_C_BRACKET statements R_C_BRACKET\n");}
;

while: WHILE bool_exp L_C_BRACKET statements R_C_BRACKET {printf("while -> WHILE bool_exp L_C_BRACKET statement R_C_BRACKET\n");}
;

for: FOR num ASSIGN NUMBER SEMICOLON bool_exp SEMICOLON num ASSIGN exp L_C_BRACKET statements R_C_BRACKET{printf("for -> FOR num ASSIGN NUMBER SEMICOLON bool_exp SEMICOLON num ASSIGN exp L_C_BRACKET statements R_C_BRACKET\n");}
;

input: INPUT L_PAREN num_list R_PAREN {printf("input -> INPUT L_PAREN num_list R_PAREN");}
; 

output: OUTPUT L_PAREN num_list R_PAREN {printf("output -> OUTPUT L_PAREN num_list R_PAREN\n");}
;

num_list: %empty /*epsilon*/ {printf("num_list -> epsilon\n");}
| COMMA num num_list {printf("num_list -> COMMA num num_list\n");}
;

exp: exp add_op term
|term {printf("exp -> term\n");}
;

bool_exp: bool_exp
;

add_op: PLUS 
| MINUS
;

term: term mulop factor {printf("term -> term mulop factor\n");}
| factor {printf("term -> factor\n");}
;

mulop: MULTI {printf("mulop -> MULTI");}
| DIVISION {printf("mulop -> DIVISION");}
;

factor: L_PAREN exp R_PAREN  {printf("factor->L_PAREN exp R_PAREN");}
| NUMBER {printf("factor->NUMBER");}
;

declaration: NUM ID {printf("declaration -> NUM ID\n");}
;

function_call: ID L_PAREN args R_PAREN {printf("function_call -> ID L_PAREN args R_PAREN\n");}
;

args: %empty {printf("args -> epsilon\n");}
;
%%

void main(int argc, char** argv) {
  if (argc >=2) {
    yyin = fopen(argv[1],"r");
      if (yyin == NULL) {
	yyin = stdin;
      }
  }
  else {
    yyin = stdin;
  }
  yyparse();
  return;
}
 void yyerror (char const *s) {
   fprintf (stderr, "%s\n", s);
 }
