/* Context-free grammar for a pseudo Pascal language 
   grammar G = (Alphabet, Variables, Rules, StartSymbol)
 */
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <assert.h>

  #include "sym_table.h"
%}

%union {
	stack_t *stkval;
	char *sval;
	int ival;
	float fval;
}

%token PROGRAM
%token VAR
%token ARRAY 
%token OF	
%token INTEGER
%token REAL
%token FUNCTION
%token PROCEDURE
%token BEGIN
%token END
%token ASSIGNOP
%token IF
%token THEN
%token ELSE
%token WHILE
%token FOR
%token DO
%token TO
%token RELOP
%token ADDOP
%token MULOP
%token NOT
%token DOTDOT

%token <sval> ID
%token <ival> INUM
%token <fval> RNUM

%type <stkval> program

%%
program:
	PROGRAM ID '(' identifier_list ')' ';'
	declarations 
	subprogram_declarations 
	compound_statement 
	'.'
	{ $$ = init_stack(init_table()); fprintf(stderr, "TEST");}
	;

identifier_list: ID 
	| identifier_list ',' ID
	;

declarations: declarations VAR identifier_list ':' type ';' 
	| empty 
	;

type: standard_type 
	| ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
	;
	
standard_type: INTEGER | REAL;

subprogram_declarations: subprogram_declarations subprogram_declaration ';'
	| empty
	;

subprogram_declaration: subprogram_head declarations subprogram_declarations compound_statement;

subprogram_head: FUNCTION ID arguments ':' standard_type ';'
	| PROCEDURE ID arguments ';'
	;

arguments: 
	| '(' parameter_list ')'
	| empty
	;

parameter_list: identifier_list ':' type
	| parameter_list ';' identifier_list ':' type
	;

compound_statement: BEGIN optional_statements END;

optional_statements: statement_list
	| empty
	;

statement_list: statement
	| statement_list ';' statement
	;

statement: variable ASSIGNOP expression
	| procedure_statement
	| compound_statement
	| IF expression THEN statement ELSE statement
	| WHILE expression DO statement
	| FOR variable ASSIGNOP expression TO expression DO statement
	;

variable: ID
	| ID '[' expression ']'
	;

procedure_statement: ID
	| ID '(' expression_list ')'
	;

expression_list: expression
	| expression_list ',' expression
	;

expression: simple_expression
	| simple_expression RELOP simple_expression
	;

simple_expression: term
	| ADDOP term
	| simple_expression ADDOP term
	;

term: factor
	| term MULOP factor
	;

factor: ID
	| ID '(' expression_list ')'
	| ID '[' expression ']'
	| INUM
	| RNUM
	| '(' expression ')'
	| NOT factor
	;

empty:  ;