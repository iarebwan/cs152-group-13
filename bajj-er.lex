%{
#include <stdio.h>
int linenum = 1;
int colnum = 1;
%}

DIGIT [0-9]
ALPHA [a-zA-Z]
NUM {DIGIT}+("."{DIGIT}+)?
ID ({ALPHA}+{DIGIT}+)+
NUMERROR ({NUM}{ALPHA}+{NUM}?)+

%%
"return"    {colnum+= yyleng; printf("RETURN %s\n", yytext);return RETURN;}
"intput"    {colnum+= yyleng; printf("INPUT %s\n", yytext);return INPUT;}
"output"    {colnum+= yyleng; printf("OUTPUT %s\n", yytext);return OUTPUT;}
"for"	{colnum+= yyleng; printf("FOR %s\n", yytext);return FOR;}
"num" {colnum+= yyleng; printf("NUM %s\n", yytext);return NUM;}
"while" {colnum+= yyleng; printf("WHILE %s\n", yytext);return WHILE;}
"if" {colnum+= yyleng; printf("IF %s\n", yytext);return IF;}
"elif" {colnum+= yyleng; printf("ELIF %s\n", yytext);return ELIF;}
"else" {colnum+= yyleng; printf("ELSE %s\n", yytext);return ELSE;}
"function" {colnum+= yyleng; printf("FUNC %s\n", yytext);return FUNC;} 
{NUMERROR} {printf("Unrecognized character: %s at Line: %d Column: %d \n", yytext,linenum, colnum);} 
{NUM} {colnum+= yyleng; printf("NUMBER %s\n", yytext);return NUMBER;}
{ID} {colnum+= yyleng; printf("ID %s\n", yytext);return ID;}
"+"  {colnum+= yyleng; printf("PLUS  %s\n", yytext);return PLUS;}
"-" {colnum+= yyleng; printf("MINUS  %s\n", yytext);return MINUS;}
"*" {colnum+= yyleng; printf("MULTI  %s\n", yytext);return MULTI;}
"/" {colnum+= yyleng; printf("DIVISION  %s\n", yytext);return DIVISION;}
"<" {colnum+= yyleng; printf("LESS  %s\n", yytext);return LESS;}
">"     {colnum+= yyleng; printf("GREATER %s\n", yytext);return GREATER;}
"=="    {colnum+= yyleng; printf("EQUAL %s\n", yytext);return EQUAL;}
"!="    {colnum+= yyleng; printf("NOT_EQUAL %s\n", yytext);return NOT_EQUAL;}
"<="    {colnum+= yyleng; printf("LE_EQ %s\n", yytext);return LE_EQ;}
">="    {colnum+= yyleng; printf("GE_EQ %s\n", yytext);return GE_EQ;}
"#".* {colnum+= yyleng; printf("COMMENT %s\n", yytext);return COMMENT;}
"["    {colnum+= yyleng; printf("L_BRACKET %s\n", yytext);return L_BRACKET;}
"]"    {colnum+= yyleng; printf("R_BRACKET %s\n", yytext);return R_BRACKET;}
"{"    {colnum+= yyleng; printf("L_C_BRACKET %s\n", yytext);return L_C_BRACKET;}
"}"    {colnum+= yyleng; printf("R_C_BRACKET %s\n", yytext);return R_C_BRACKET;}
"("    {colnum+= yyleng; printf("L_PAREN %s\n", yytext);return L_PAREN;}
")"    {colnum+= yyleng; printf("R_PAREN %s\n", yytext);return R_PAREN;}
"="    {colnum+= yyleng; printf("ASSIGN %s\n", yytext);return ASSIGN;}
";"    {colnum+= yyleng; printf("SEMICOLON %s\n", yytext);return SEMICOLON;}
","    {colnum+= yyleng; printf("COMMA %s\n", yytext);return COMMA;}

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
