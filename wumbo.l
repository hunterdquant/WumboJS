%{
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
%}


whitespace	[ \t]
id [a-zA-Z]+[a-zA-Z0-9]*
inum [0-9]+
rnum [0-9]+\.[0-9]+

program 	 "program"
var 		 "var"
array 		 "array"
of			 `"of"
integer 	 "integer"
real 		 "real"
function	 "function"
procedure	 "procedure"
begin		 "begin"
end			 "end"
assignop	 ":="
if			 "if"
then		 "then"
else		 "else"
while		 "while"
for		 "for"
do			 "do"
to			 "to"
relop		 "<" | ">" | "<=" | ">=" | "=" | "<>"
addop		 "+" | "-" | "or"
mulop		 "*" | "/" | "and"
not			 "not"
dotdot		 ".."

%%
{id}            { fprintf( stderr, "[ID:%s]", yytext); }
{whitespace}    { ; }
{inum}          { fprintf( stderr, "[INUM:%s]", yytext); }
{rnum}          { fprintf( stderr, "[RNUM:%s]", yytext); }
[(][*][^*]*[*]+([^*/][^*]*[*]+)*[)]       { ; }
\n              { fprintf( stderr, "[EOL]\n" ); return yytext[0]; }
.				{ fprintf( stderr, "[TOK:%s]", yytext ); }
%%

int yywrap()
{
	return 1;
}