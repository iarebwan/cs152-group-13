%{
#include <stdio.h>
%}

DIGIT [0-9]
%%
"num" {printf("NUMBER %s\n", yytext);}
"+"  {printf("PLUS  %s\n", yytext);}
"-" {printf("MINUS  %s\n", yytext);}
"*" {printf("MULTI  %s\n", yytext);}
"/" {printf("DIVISION  %s\n", yytext);}
"<" {printf("LESS  %s\n", yytext);}
%%


main(void){
  printf("Ctrl+D to quit\n");
  yylex();
}
