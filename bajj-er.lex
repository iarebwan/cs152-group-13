%{
#include <stdio.h>
%}

DIGIT [0-9]

%%
">"     {printf("GREATER %s\n", yytext);}
"=="    {printf("EQUAL %s\n", yytext);}
"!="    {printf("NOT_EQUAL %s\n", yytext);}
"<="    {printf("LE_EQ %s\n", yytext);}
">="    {printf("GE_EQ %s\n", yytext);}
%%

main(void) {
  printf("Ctrl+D to quit\n");
  yylex();
}

