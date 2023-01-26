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
">"     {printf("GREATER %s\n", yytext);}
"=="    {printf("EQUAL %s\n", yytext);}
"!="    {printf("NOT_EQUAL %s\n", yytext);}
"<="    {printf("LE_EQ %s\n", yytext);}
">="    {printf("GE_EQ %s\n", yytext);}
%%


main(void){
  printf("Ctrl+D to quit\n");
  yylex();
}
