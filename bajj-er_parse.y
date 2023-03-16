%{
#include "CodeNode.h"
#include <iostream>
#include <sstream>
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
int cur_arg = 0;
int temp = 0;
char *identToken;
int numberToken;
int labelNum = 0;
int numTemp = 0;

std::string create_temp() {
  std::stringstream ssm;
  ssm << std::string("_temp") << numTemp++;
  return ssm.str();
}
std::string decl_temp_code(std::string &temp){
  CodeNode *node = new CodeNode;
  node->name = temp;
  node->code = "";
  node->code = std::string(". ") + temp + std::string("\n");
  return node->code;
}
%}

%union {
  char* op_val;
  struct CodeNode *codenode;
}

%define parse.error verbose
%start prog_start
%token RETURN INPUT OUTPUT NUMBER NUM WHILE IF ELIF ELSE FUNC PLUS MINUS MULTI DIVISION LESS GREATER EQUAL NOT_EQUAL LE_EQ GE_EQ COMMENT L_BRACKET R_BRACKET L_C_BRACKET R_C_BRACKET L_PAREN R_PAREN ASSIGN SEMICOLON COMMA FOR

%token <op_val> ID
%type <codenode> num
%type <codenode> bool_exp
%type <codenode> elsify
%type <codenode> function
%type <codenode> functions
%type <codenode> function_call
%type <codenode> declaration
%type <codenode> statement
%type <codenode> statements
%type <codenode> factor
%type <codenode> args
%type <codenode> parameters
%type <codenode> exp
%type <codenode> return
%type <op_val> NUMBER
%type <codenode> input
%type <codenode> output
%type <codenode> term
%type <codenode> if
%type <codenode> while
%type <codenode> else

%%
prog_start : %empty {
//printf("prog_start->epsilon\n");
	printf("/n");
}

| functions {
//printf("we be parsing \n");
//printf("prog_start->functions\n");
CodeNode *code_node = $1;
printf("%s\n", code_node->code.c_str());

}   
;

functions: function{
//printf("function -> function\n");
//Should be good?
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
node->code += std::string("func ") + func_name + std::string("\n");

//add args
CodeNode *args = $4;
node->code += args->code;

//add statments
CodeNode *statements = $7;
node->code += statements->code;
//endfunc
node->code += std::string("endfunc\n");
$$ = node;
cur_arg = 0;
};

args: declaration COMMA args {
//printf("arguments -> COMMA arguments\n");
//Should be done?
CodeNode *node = new CodeNode;
std::stringstream arg_nums;
arg_nums << std::string("$") << cur_arg++;
CodeNode *dec = $1;
CodeNode *args = $3;
node->code = dec->code;
node->code += std::string("= ") + dec->name + std::string(", ") + arg_nums.str() + std::string("\n");
node->code += args->code;
$$ = node;
}
| declaration {
//printf("arguments -> argument\n");
//Should be done?
CodeNode *node = new CodeNode;
std::stringstream arg_nums;
arg_nums << std::string("$") << cur_arg++;
CodeNode *dec = $1;
node->code = dec->code;
node->code += std::string("= ") + dec->name + std::string(", ") + arg_nums.str() + std::string("\n");
$$ = node;
}
| %empty {
//should be done
CodeNode *node = new CodeNode;
cur_arg = 0;
$$ = node;
}
;



statements: statement SEMICOLON {
//printf("statements -> statement SEMICOLON\n");
//SHOULD BE DONE
CodeNode *node = new CodeNode;
//printf("going into statement SEMICOLON\n");
node->code = $1->code;
//printf("we are out from statement\n");
$$ = node;
}
| statement SEMICOLON statements {
//printf("statements -> statement SEMICOLON statement\n");
//SHOULD BE DONE
CodeNode *node = new CodeNode;
node->code = $1->code + $3->code;
$$ = node;
}
|%empty{
CodeNode *node = new CodeNode;
$$ = node;
}
;

statement: declaration {
//printf("statment -> declaration\n");
//Done i think?
CodeNode *dec = $1;
$$ = dec;
}
| function_call {
//printf("statement-> function_call\n");
// Place holder but probs shouldnt do function_call as it does nothing by itself (need to assign)
CodeNode *node = new CodeNode;
$$ = node;
}
| num {
//Done?
CodeNode *num = $1;
$$ = num;
}
| if {
//printf("statement->if\n");
CodeNode *node = $1;
$$ = node;
}
| while {
//printf("statement->while\n");
//TODO PHASE 4
}
| for {printf("statement->for\n");}
| input {
    CodeNode *input = $1;
    $$ = input;
}
| output {
    CodeNode *output = $1;
    $$ = output;
}
| return {
//printf("statement->return\n");
CodeNode *node = $1;
//std::cout << std::string("our ret code: ") << node->code << std::endl;
$$ = node;
}
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
| ID ASSIGN function_call {
CodeNode *node = new CodeNode;
node->name = $1;
//std::cout << "func_call code: " << $3->code << std::endl;
node->code += $3->code;
node->code += std::string("= ") + $1 + std::string(", ") + $3->name + std::string("\n");
$$ = node;
}
;

return: RETURN ID {
//printf("return->RETURN ID\n");
CodeNode *node = new CodeNode;
node->name = $2;
node->code = std::string("ret ") + $2 + std::string("\n");
$$ = node;
}     
| RETURN exp {
//printf("return->RETURN EXP\n");
CodeNode *node = $2;
//std::cout << std::string("exp name: ") << node->name  << std::endl;
node->code += std::string("ret ") + $2->name + std::string("\n");
//std::cout << std::string("we coming outta return exp") << std::endl;
$$ = node;
} 
;

num: NUM ID ASSIGN exp{
CodeNode *numDec = new CodeNode;
std::string var_name = $2;
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
numDec->code += $4->code;
numDec->code += std::string("= ") + var_name + std::string(", ") + $4->name + std::string("\n");
$$ = numDec;
}
| NUM ID ASSIGN NUMBER {
//printf("num -> NUM ID ASSIGN NUMBER\n");
std::string var_name = $2;
CodeNode *numDec = new CodeNode;
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
numDec->code += std::string("= ") + var_name + std::string(", ") + $4 + std::string("\n");
$$ = numDec;
}
| NUM ID ASSIGN function_call {
//printf("num -> NUM ID ASSIGN function_call\n");
CodeNode *node = new CodeNode;
node->name = $2;
node->code += std::string(". ") + $2 + std::string("\n");
node->code += $4->code;
node->code += std::string("= ") + $2 + std::string(", ") + $4->name + std::string("\n");
$$ = node;
}
;

if: IF bool_exp L_C_BRACKET statements R_C_BRACKET elsify{
//printf("if -> IF bool_exp L_C_BRACKET statements R_C_BRACKET elsify\n");
CodeNode *node = new CodeNode;
std::stringstream ifState;
std::stringstream skip;
ifState << std::string("label") << labelNum++;
skip << std::string("label") << labelNum++;
//std::cout << std::string("going into bool: ") << std::endl;
CodeNode * boolExp =  $2;
node->code += std::string("?:= ") + ifState.str() + std::string(", ") + boolExp->name + std::string("\n");
node->code += std::string(":= ") + skip.str() + std::string("\n"); 
node->code +=  std::string(": ") + ifState.str() + std::string("\n");
//std::cout << std::string("going into statments: ") << std::endl;
node->code += $4->code;
node->code += std::string(": ") + skip.str() + std::string("\n");
node->code += $6->code;
$$ = node;
}
;

elsify: elif  elsify {printf("elsify -> elif SEMICOLON elsify\n");}
| else {
//printf("elsify -> else SEMICOLON\n");
CodeNode *node = $1;
$$ = node;
}
| %empty {
//printf("elsify->epsilon\n");
CodeNode *node = new CodeNode;
$$ = node;
}
;

elif: ELIF bool_exp L_C_BRACKET statements R_C_BRACKET {printf("elif -> elif bool_exp L_C_BRACKET statements R_C_BRACKET\n");}
;

else: ELSE L_C_BRACKET statements R_C_BRACKET {
//printf("else -> else L_C_BRACKET statements R_C_BRACKET\n");
//should just push up the code since it is else statement (must be run if no other options)
CodeNode *node = $3;
$$ = node;
}
;

while: WHILE bool_exp L_C_BRACKET statements R_C_BRACKET {
//printf("while -> WHILE bool_exp L_C_BRACKET statement R_C_BRACKET\n");
CodeNode *node = new CodeNode;
std::stringstream ifState;
std::stringstream skip;
std::stringstream start;
CodeNode * boolExp =  $2;
ifState << std::string("label") << labelNum++;
skip << std::string("label") << labelNum++;
start << std::string("label") << labelNum++;
node->code += std::string(": ") + start.str();
node->code += std::string("?:= ") + ifState.str() + std::string(", ") + boolExp->name + std::string("\n");
node->code += std::string(":= ") + skip.str() + std::string("\n");
node->code +=  std::string(": ") + ifState.str() + std::string("\n");
node->code += $4->code;
node->code += std::string(":= ") + start.str() + std::string("\n");
node->code += std::string(": ") + skip.str() + std::string("\n");
}
;

for: FOR num SEMICOLON bool_exp ID ASSIGN exp L_C_BRACKET statements R_C_BRACKET{printf("for -> FOR num ASSIGN NUMBER SEMICOLON bool_exp SEMICOLON num ASSIGN exp L_C_BRACKET statements R_C_BRACKET\n");}
;

input: INPUT L_PAREN ID R_PAREN {
//printf("input -> INPUT L_PAREN num_list R_PAREN\n");
  CodeNode *exp = new CodeNode;
  std::string id = $3;
  exp->code = std::string(".< ") + id + std::string("\n");
  $$ = exp;
}
; 

output: OUTPUT L_PAREN exp R_PAREN {
//printf("output -> OUTPUT L_PAREN num_list R_PAREN\n");
  CodeNode *exp = new CodeNode;
  exp->code = $3->code;
  exp->code += std::string(".> ") + $3->name + std::string("\n");
  $$ = exp;
}
;


exp: exp PLUS term{
   CodeNode *node = new CodeNode;
   CodeNode *num1 = $1;
   CodeNode *num2 = $3;
   std::string temp = create_temp();
   node->code = $1->code + $3->code + decl_temp_code(temp);
   node->code += std::string("+ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
   node->name = temp;
   $$ = node;
}
|exp MINUS term {
   CodeNode *node = new CodeNode;
   CodeNode *num1 = $1;
   CodeNode *num2 = $3;
   std::string temp = create_temp();
   node->code = $1->code + $3->code + decl_temp_code(temp);
   node->code += std::string("- ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
   node->name = temp;
   $$ = node;
}
|term {
   CodeNode *term = $1;
   $$ = term;
}
;



bool_exp: L_PAREN exp GREATER exp R_PAREN {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = $2->code + $4->code + decl_temp_code(temp);
  node->code += std::string("> ") + temp + std::string(", ") + $2->name + std::string(", ") + $4->name + std::string("\n");
  node->name = temp;
  $$ = node;
}
| L_PAREN exp LESS exp R_PAREN {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = $2->code + $4->code + decl_temp_code(temp);
  node->code += std::string("< ") + temp + std::string(", ") + $2->name + std::string(", ") + $4->name + std::string("\n");
  node->name = temp;
  $$ = node;
}
| L_PAREN exp EQUAL exp R_PAREN {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = $2->code + $4->code + decl_temp_code(temp);
  node->code += std::string("== ") + temp + std::string(", ") + $2->name + std::string(", ") + $4->name + std::string("\n");
  node->name = temp;
  $$ = node;
}
| L_PAREN exp LE_EQ exp R_PAREN {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = $2->code + $4->code + decl_temp_code(temp);
  node->code += std::string("<= ") + temp + std::string(", ") + $2->name + std::string(", ") + $4->name + std::string("\n");
  node->name = temp;
  $$ = node;
}
| L_PAREN exp GE_EQ exp R_PAREN {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = $2->code + $4->code + decl_temp_code(temp);
  node->code += std::string(">= ") + temp + std::string(", ") + $2->name + std::string(", ") + $4->name + std::string("\n");
  node->name = temp;
  $$ = node;
}
| L_PAREN exp NOT_EQUAL exp R_PAREN {
  CodeNode *node = new CodeNode;
  std::string temp = create_temp();
  node->code = $2->code + $4->code + decl_temp_code(temp);
  node->code += std::string("!= ") + temp + std::string(", ") + $2->name + std::string(", ") + $4->name + std::string("\n");
  node->name = temp;
  $$ = node;
}
| L_PAREN exp R_PAREN {
CodeNode *node = $2;
$$ = node;
}
;

term: term MULTI factor {
// printf("term -> term MULTI factor\n");
   CodeNode *node = new CodeNode;
   CodeNode *num1 = $1;
   CodeNode *num2 = $3;
   std::string temp = create_temp();
   node->code = $1->code + $3->code + decl_temp_code(temp);
   node->code += std::string("* ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
   node->name = temp;
   $$ = node;
}
| term DIVISION factor {
// printf("term -> term DIVISION factor\n");
   CodeNode *node = new CodeNode;
   CodeNode *num1 = $1;
   CodeNode *num2 = $3;
   std::string temp = create_temp();
   node->code = $1->code + $3->code + decl_temp_code(temp);
   node->code += std::string("/ ") + temp + std::string(", ") + $1->name + std::string(", ") + $3->name + std::string("\n");
   node->name = temp;
   $$ = node;
}
| factor {
   CodeNode *factor = $1;
   $$ = factor;
}
;


factor: L_PAREN exp R_PAREN  {
//printf("factor->L_PAREN exp R_PAREN\n");
}
| NUMBER {
  CodeNode *node = new CodeNode;
  node->name = $1;
  node->code = "";
  $$ = node;
}
| ID {
  CodeNode *node = new CodeNode;
  node->name = $1;
  node->code = "";
  $$ = node;
}
| function_call {
//printf("factor -> function_call\n");
 CodeNode *node = $1;
 $$ = node;
}   
;

declaration: NUM ID {
//Done?
//printf("declaration -> NUM ID\n");
std::string var_name = $2;
CodeNode *numDec = new CodeNode;
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
$$ = numDec;
}
;


parameters: exp{
//Done?
CodeNode *node = new CodeNode;
CodeNode *expr = $1;
node->code = std::string("param ") + expr->name + std::string("\n");
node->code += expr->code;
$$ = node;
}
| exp COMMA parameters{
//Done?
CodeNode *node = new CodeNode;
CodeNode *expr = $1;
CodeNode *nParam = $3;
node->code = std::string("param ") + expr->name + std::string("\n");
node->code += expr->code  + nParam->code; 
$$ = node;
}
| %empty {
//should be empty
CodeNode *node = new CodeNode;
$$ = node;
}
;


function_call: ID L_PAREN parameters R_PAREN {
//printf("function_call -> ID L_PAREN exp R_PAREN\n");
//CHECK TODO
CodeNode *node = new CodeNode;
std::string func = $1;
CodeNode *params = $3;

std::string temp = create_temp();

//code
node->code = params->code + decl_temp_code(temp);
node->code += std::string("call ") + func + std::string(", ") + temp + std::string("\n");
node->name = temp;
//std::cout << "code from func: " << node->code << std::endl;
$$ = node;
}
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
