%{

#include "sym_table.h"
#include "exp_tree.h"
#include "defs.h"
#include "wumbo_utils.h"
#include "stmt.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "y.tab.h"

long int LINE_COUNT = 1;
%}


whitespace	[ \t]
id [a-zA-Z]+[a-zA-Z0-9]*
inum [0-9]+
rnum [0-9]+\.[0-9]+

relop		 "<"|">"|"<="|">="|"="|"<>"
addop		 "+"|"-"|"or"
mulop		 "*"|"/"|"and"

%%
"program"		{
					wprintf("[PROGRAM]");
					return PROGRAM;
				}
"var"			{
					wprintf("[VAR]");
					return VAR;
				}
"array"			{
					wprintf("[ARRAY]");
					return ARRAY;
				}
"of"			{
					wprintf("[OF]");
					return OF;
				}
"integer"		{
					wprintf("[INTEGER]");
					return INTEGER;
				}
"real"			{
					wprintf("[REAL]");
					return REAL;
				}
"function"		{
					wprintf("[FUNCTION]");
					return FUNCTION;
				}
"procedure"		{
					wprintf("[PROCEDURE]");
					return PROCEDURE;
				}
"begin"			{
					wprintf("[BEGIN]");
					return BBEGIN;
				}
"end"			{
					wprintf("[END]");
					return END;
				}
":="			{
					wprintf("[ASSIGNOP]");
					return ASSIGNOP;
				}
"if"			{
					wprintf("[IF]");
					return IF;
				}
"then"			{
					wprintf("[THEN]");
					return THEN;
				}
"else"			{
					wprintf("[ELSE]");
					return ELSE;
				}
"while"			{
					wprintf("[WHILE]");
					return WHILE;
				}
"for"			{
					wprintf("[FOR]");
					return FOR;
				}
"do"			{
					wprintf("[DO]");
					return DO;
				}
"to"			{
					wprintf("[TO]");
					return TO;
				}
"not"			{
					wprintf("[NOT]");
					yylval.opval = str2optype(yytext);
					return NOT;
				}
".."			{
					wprintf("[DOTDOT]");
					return DOTDOT;
				}
{relop}			{
					wprintf("[RELOP:%s]", yytext);
					yylval.opval = str2optype(yytext);
					return RELOP;
				}
{addop}			{
					wprintf("[ADDOP:%s]", yytext);
					yylval.opval = str2optype(yytext);
					return ADDOP;
				}
{mulop}			{
					wprintf("[MULOP:%s]", yytext);
					yylval.opval = str2optype(yytext);
					return MULOP;
				}
{id}            { 
					wprintf("[ID:%s]", yytext); 
					yylval.sval = yytext;
					return ID;
				}
{whitespace}    { ; }
{inum}          { 
					wprintf("[INUM:%s]", yytext); 
					yylval.ival = atoi(yytext);
					return INUM;
				}
{rnum}          { 
					wprintf("[RNUM:%s]", yytext); 
					yylval.fval = atof(yytext);
					return RNUM;
				}
[(][*][^*]*[*]+([^*/][^*]*[*]+)*[)]       {;}
[//]			{;}
\n              { 
					LINE_COUNT++; 
					wprintf("[EOL]\n" ); 
				}
"."|","|"("|")"|";"|":"|"["|"]" { 	
					wprintf("[TOK:%s]", yytext);
					return yytext[0];
				}
%%

int yywrap()
{
	return 1;
}