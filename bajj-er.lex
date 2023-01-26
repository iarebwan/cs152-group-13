%{
#include <stdio.h>
%}

DIGIT [0-9]
ALPHA [a-zA-Z]
ID {ALPHA}+
NUM {DIGIT}+("."{DIGIT}+)?

%%
"return"    {printf("RETURN %s\n", yytext);}
"intput"    {printf("INPUT %s\n", yytext);}
"output"    {printf("OUTPUT %s\n", yytext);}
{NUM} {printf("NUMBER %s\n", yytext);}
{ID} {printf("ID %s\n", yytext);}
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

"["    {printf("L_BRACKET %s\n", yytext);}
"]"    {printf("R_BRACKET %s\n", yytext);}
"{"    {printf("L_C_BRACKET %s\n", yytext);}
"}"    {printf("R_C_BRACKET %s\n", yytext);}
"="    {printf("ASSIGN %s\n", yytext);}
";"    {printf("SEMICOLON %s\n", yytext);}

%%


main( argc, argv)
int argc;
char **argv;
{
    ++argv, --argc; 
    if ( argc > 0 )
            yyin = fopen( argv[0], "r" );
    else
            yyin = stdin;

    printf("Ctrl+D to quit\n");
    
    yylex();
    
}
