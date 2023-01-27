%{
#include <stdio.h>
int linenum = 1;
int colnum = 1;
%}

DIGIT [0-9]
ALPHA [a-zA-Z]
ID {ALPHA}+
NUM {DIGIT}+("."{DIGIT}+)?

%%
"return"    {colnum+= yyleng; printf("RETURN %s\n", yytext);}
"intput"    {colnum+= yyleng; printf("INPUT %s\n", yytext);}
"output"    {colnum+= yyleng; printf("OUTPUT %s\n", yytext);}
"num" {colnum+= yyleng; printf("NUM %s\n", yytext);}
"while" {colnum+= yyleng; printf("WHILE %s\n", yytext);}
"if" {colnum+= yyleng; printf("IF %s\n", yytext);}
"elif" {colnum+= yyleng; printf("ELIF %s\n", yytext);}
"else" {colnum+= yyleng; printf("ELSE %s\n", yytext);}
"function" {colnum+= yyleng; printf("FUNC %s\n", yytext);} 
{NUM} {colnum+= yyleng; printf("NUMBER %s\n", yytext);}
{ID} {colnum+= yyleng; printf("ID %s\n", yytext);}
"+"  {colnum+= yyleng; printf("PLUS  %s\n", yytext);}
"-" {colnum+= yyleng; printf("MINUS  %s\n", yytext);}
"*" {colnum+= yyleng; printf("MULTI  %s\n", yytext);}
"/" {colnum+= yyleng; printf("DIVISION  %s\n", yytext);}
"<" {colnum+= yyleng; printf("LESS  %s\n", yytext);}
">"     {colnum+= yyleng; printf("GREATER %s\n", yytext);}
"=="    {colnum+= yyleng; printf("EQUAL %s\n", yytext);}
"!="    {colnum+= yyleng; printf("NOT_EQUAL %s\n", yytext);}
"<="    {colnum+= yyleng; printf("LE_EQ %s\n", yytext);}
">="    {colnum+= yyleng; printf("GE_EQ %s\n", yytext);}
"#" {colnum+= yyleng; printf("COMMENT %s\n", yytext);}
"["    {colnum+= yyleng; printf("L_BRACKET %s\n", yytext);}
"]"    {colnum+= yyleng; printf("R_BRACKET %s\n", yytext);}
"{"    {colnum+= yyleng; printf("L_C_BRACKET %s\n", yytext);}
"}"    {colnum+= yyleng; printf("R_C_BRACKET %s\n", yytext);}
"("    {colnum+= yyleng; printf("L_PAREN %s\n", yytext);}
")"    {colnum+= yyleng; printf("R_PAREN %s\n", yytext);}
"="    {colnum+= yyleng; printf("ASSIGN %s\n", yytext);}
";"    {colnum+= yyleng; printf("SEMICOLON %s\n", yytext);}
","    {colnum+= yyleng; printf("COMMA %s\n", yytext);}

[\n] {colnum = 1; linenum++;}
[ \t] {colnum+= yyleng;}
. printf( "Unrecognized character: %s at Line: %d Column: %d \n", yytext, linenum, colnum);
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
