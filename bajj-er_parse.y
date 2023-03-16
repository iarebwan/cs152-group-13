%{
#include "CodeNode.h"
#include "SymNode.h"

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
int numTemp = 0;
int symNum = -1;
std::vector<std::vector<SymNode*> > symTable;
bool lock = false;


bool check_table(SymNode *Check){
printf("Vec size %d", symTable.size());
  for(int i = 0; i < symTable.at(symNum).size(); i++){
    
    if(symTable.at(symNum).at(i)->name == Check->name && symTable.at(symNum).at(i)->type == Check->type){
      return true;
    }
  }
std::string temp = Check->name.c_str();
printf("VarName: %s Does not exist or has been declared as a different type\n", temp.c_str());
return false;
}
bool check_decl(SymNode *Check){
printf("Vec size %d", symTable.size());
  for(int i = 0; i < symTable.at(symNum).size(); i++){
    if(symTable.at(symNum).at(i)->name == Check->name){
      std::string temp = Check->name.c_str();
      printf("VarName: %s already exists with variable %s \n", temp.c_str(), symTable.at(symNum).at(i)->name.c_str());
      return false;
    }
 
  }
return true;
}

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
%type <codenode> bool_exp

%%
prog_start : %empty {
//printf("prog_start->epsilon\n");
	printf("/n");
}

| functions {
printf("we be parsing \n");
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
lock = false;
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
printf("going into statement SEMICOLON\n");
node->code = $1->code;
printf("we are out from statement\n");
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
//TODO
CodeNode *dec = $1;
$$ = dec;
}
| function_call {
//printf("statement-> function_call\n");
//TODO
}
| num {
//Done?
CodeNode *num = $1;
$$ = num;
}
| if {
//printf("statement->if\n");
//TODO PHASE 4
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
$$ = node;
}
| ID L_BRACKET NUMBER R_BRACKET ASSIGN exp  //sttem
{
std::string var_name = $1;
std::string ind = $3;

CodeNode *node = new CodeNode;
node->code = $6->code;
node->code += std::string("[]= ") + var_name + std::string(", ") + ind + std::string(", ") + $6->name + std::string("\n");
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
std::cout << "func_call code: " << $3->code << std::endl;
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
| RETURN exp {printf("return->RETURN EXP\n");} 
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

input: INPUT L_PAREN ID R_PAREN {
//printf("input -> INPUT L_PAREN num_list R_PAREN\n");
  CodeNode *exp = new CodeNode;
  std::string id = $3;
  exp->code = std::string(".< ") + id + std::string("\n");
  $$ = exp;
}
| INPUT L_PAREN ID L_BRACKET NUMBER R_BRACKET R_PAREN {
//printf("input -> INPUT L_PAREN num_list R_PAREN\n");
  CodeNode *exp = new CodeNode;
  std::string id = $3;
  std::string index = $5;
  exp->code = std::string(".[]< ") + id + std::string(", ") + index + std::string("\n");
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
| OUTPUT L_PAREN ID L_BRACKET NUMBER R_BRACKET R_PAREN {
//printf("input -> INPUT L_PAREN num_list R_PAREN\n");
  CodeNode *exp = new CodeNode;
  std::string id = $3;
  std::string index = $5;
  exp->code = std::string(".[]> ") + id + std::string(", ") + index + std::string("\n");
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
CodeNode *fact = $2;
   $$ = fact;
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
  SymNode* symTemp = new SymNode;
  symTemp->name = $1;
  symTemp->type = "num";

  if(check_table(symTemp) == false){

  printf("Variable has not been declared");
  exit(0);
}


}
| function_call {
//printf("factor -> function_call\n");
 CodeNode *node = $1;
 $$ = node;
}   
| ID L_BRACKET NUMBER R_BRACKET { //factor

std::string myTemp = create_temp();
CodeNode *node = new CodeNode;

std::string var_name = $1;
std::string ind = $3;
node->name = myTemp;
node->code = decl_temp_code(myTemp);
node->code += std::string("=[] ") + myTemp + std::string(", ") + var_name + std::string(", ") + ind + std::string("\n");
$$ = node;

SymNode* symTemp = new SymNode;
symTemp->name = $1;
symTemp->type = "arr";

  if(check_table(symTemp) == false){

  printf("Array has not been declared");
  exit(0);
}
}   
;

declaration: NUM ID L_BRACKET NUMBER R_BRACKET {
printf("declaration -> NUM ID L_BRACKET R_BRACKET\n");
if(lock == false){
  symNum++;
  std::vector<SymNode*> tempVec;
  symTable.push_back(tempVec);
  lock = true;
}
std::string var_name = $2;
std::string size = $4;
CodeNode *arrDec = new CodeNode;
arrDec->name = var_name;
arrDec->code = std::string(".[] ") + var_name + std::string(", ") + size + std::string("\n");
$$ = arrDec;

SymNode* symTemp = new SymNode;
symTemp->name = $2;
symTemp->type = "arr";

if(check_decl(symTemp) == false){

  printf("Variable already declared");
  exit(0);
}
printf("Vec size %d", symNum);
symTable.at(symNum).push_back(symTemp);

}
| NUM ID {
//Done?
//printf("declaration -> NUM ID\n");
if(lock == false){
  symNum++;
  std::vector<SymNode*> tempVec;
  symTable.push_back(tempVec);
  lock = true;
}
std::string var_name = $2;
CodeNode *numDec = new CodeNode;
numDec->name = var_name;
numDec->code = std::string(". ") + var_name + std::string("\n");
$$ = numDec;

SymNode* symTemp = new SymNode;
symTemp->name = $2;
symTemp->type = "num";

if(check_decl(symTemp) == false){

  printf("Variable already declared");
  exit(0);
}
printf("Vec size %d", symTable.size());
symTable.at(symNum).push_back(symTemp);

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

std::cout << "param code: " << params->code << std::endl;
//temp
std::stringstream tempB;
tempB << std::string("_temp") << temp++;

//tempDec
CodeNode *tempNode = new CodeNode;
tempNode->name = tempB.str();
tempNode->code += std::string(". ") + tempB.str() + std::string("\n");

//code
node->code = params->code + tempNode->code;
node->code += std::string("call ") + func + std::string(", ") + tempB.str() + std::string("\n");
node->name = tempB.str();
std::cout << "code from func: " << node->code << std::endl;
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
