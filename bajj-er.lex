%{
#include <string>
#include <iostream>
#include <stdio.h>
#include "y.tab.h"
int linenum = 1;
int colnum = 1;
int loopCount = -1;
%}

DIGIT [0-9]
ALPHA [a-zA-Z]
NUM {DIGIT}+("."{DIGIT}+)?
ID ({ALPHA}+_*+{DIGIT}*)+
NUMERROR ({NUM}{ALPHA}+{NUM}?)+

%%
"break"     {colnum+= yyleng; return BREAK;}
"continue"     {colnum+= yyleng; return CONTINUE;}
"return"    {colnum+= yyleng; return RETURN;}
"input"    {colnum+= yyleng; return INPUT;}
"output"    {colnum+= yyleng; return OUTPUT;}
"for"	{colnum+= yyleng; return FOR;}
"num" {colnum+= yyleng; return NUM;}
"while" {colnum+= yyleng; loopCount++; return WHILE;}
"if" {colnum+= yyleng; return IF;}
"elif" {colnum+= yyleng; return ELIF;}
"else" {colnum+= yyleng; return ELSE;}
"function" {colnum+= yyleng; return FUNC;} 
{NUMERROR} {printf("Unrecognized character: %s at Line: %d Column: %d \n", yytext,linenum, colnum);} 
{NUM} {yylval.op_val = new char[yyleng+1];strcpy(yylval.op_val,yytext); colnum+= yyleng; return NUMBER;}
{ID} {yylval.op_val = new char[yyleng+1]; strcpy(yylval.op_val,yytext); colnum+= yyleng; return ID;}
"+"  {colnum+= yyleng; return PLUS;}
"-" {colnum+= yyleng; return MINUS;}
"*" {colnum+= yyleng; return MULTI;}
"/" {colnum+= yyleng; return DIVISION;}
"%" {colnum+= yyleng; return MOD;}
"<" {colnum+= yyleng; return LESS;}
">"     {colnum+= yyleng; return GREATER;}
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
