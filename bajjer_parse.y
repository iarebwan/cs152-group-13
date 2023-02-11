%{
#include <stdio.h>
extern FILE* yyin;
%}
%start exp
%token PLUS MINUS DIV MULT NUMBER L_PAREN R_PAREN EQUAL ERROR

%%
exp: exp addop term {prinf("exp->exp addop term\n");}
| term  {prinf("exp->term\n");}
;

addop: PLUS  {prinf("addop->PLUS\n");} 
| MINUS {prinf("addop->MINUS\n");}
;

term: term mulop factor  {prinf("term->term mulop factor\n");}
| factor  {prinf("exp->factor\n");}

;

mulop: DIV {prinf("mulop->DIV\n");} 
| MULTI;

factor: NUMBER EQ 
| L_PAREN exp R_PAREN;


%%
