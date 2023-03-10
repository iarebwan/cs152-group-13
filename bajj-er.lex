%{
#include <string>
#include <iostream>
#include <stdio.h>
#include "y.tab.h"
int linenum = 1;
int colnum = 1;
%}

DIGIT [0-9]
ALPHA [a-zA-Z]
NUM {DIGIT}+("."{DIGIT}+)?
ID ({ALPHA}+{DIGIT}*)+
NUMERROR ({NUM}{ALPHA}+{NUM}?)+

%%
"return"    {colnum+= yyleng; return RETURN;}
"intput"    {colnum+= yyleng; printf("INPUT %s\n", yytext);return INPUT;}
"output"    {colnum+= yyleng; printf("OUTPUT %s\n", yytext);return OUTPUT;}
"for"	{colnum+= yyleng; return FOR;}
"num" {colnum+= yyleng; return NUM;}
"while" {colnum+= yyleng; printf("WHILE %s\n", yytext);return WHILE;}
"if" {colnum+= yyleng; printf("IF %s\n", yytext);return IF;}
"elif" {colnum+= yyleng; printf("ELIF %s\n", yytext);return ELIF;}
"else" {colnum+= yyleng; printf("ELSE %s\n", yytext);return ELSE;}
"function" {colnum+= yyleng; return FUNC;} 
{NUMERROR} {printf("Unrecognized character: %s at Line: %d Column: %d \n", yytext,linenum, colnum);} 
{NUM} {yylval.op_val = new char[yyleng+1];strcpy(yylval.op_val,yytext); colnum+= yyleng; return NUMBER;}
{ID} {yylval.op_val = new char[yyleng+1]; strcpy(yylval.op_val,yytext); colnum+= yyleng; return ID;}
"+"  {colnum+= yyleng; printf("PLUS  %s\n", yytext);return PLUS;}
"-" {colnum+= yyleng; printf("MINUS  %s\n", yytext);return MINUS;}
"*" {colnum+= yyleng; printf("MULTI  %s\n", yytext);return MULTI;}
"/" {colnum+= yyleng; printf("DIVISION  %s\n", yytext);return DIVISION;}
"<" {colnum+= yyleng; printf("LESS  %s\n", yytext);return LESS;}
">"     {colnum+= yyleng; printf("GREATER %s\n", yytext);return GREATER;}
"=="    {colnum+= yyleng; return EQUAL;}
"!="    {colnum+= yyleng; return NOT_EQUAL;}
"<="    {colnum+= yyleng; return LE_EQ;}
">="    {colnum+= yyleng; return GE_EQ;}
"#".* {colnum+= yyleng; return COMMENT;}
"["    {colnum+= yyleng; return L_BRACKET;}
"]"    {colnum+= yyleng; return R_BRACKET;}
"{"    {colnum+= yyleng; return L_C_BRACKET;}
"}"    {colnum+= yyleng; return R_C_BRACKET;}
"("    {colnum+= yyleng; return L_PAREN;}
")"    {colnum+= yyleng; return R_PAREN;}
"="    {colnum+= yyleng; return ASSIGN;}
";"    {colnum+= yyleng; return SEMICOLON;}
","    {colnum+= yyleng; return COMMA;}

[\n] {colnum = 1; linenum++;}
[ \t] {colnum+= yyleng;}
. printf( "Unrecognized character: %s at Line: %d Column: %d \n", yytext, linenum, colnum);
%%


/*main( argc, argv)
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
    
}*/
