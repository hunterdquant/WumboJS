/* Context-free grammar for a pseudo Pascal language 
   grammar G = (Alphabet, Variables, Rules, StartSymbol)
 */
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <assert.h>


  #include "sym_table.h"
  #include "exp_tree.h"
  #include "defs.h"
  #include "stmt.h"


  extern FILE *yyin;
  extern long int LINE_COUNT;
  sym_stack_t *sym_table;
%}

%union {
	char *sval;
	int ival;
	float fval;
	op_type opval;
	sym_stack_t *sym_stack_val;
	sym_node_t *sym_ref;
	stmt_t *stmt_val;
	exp_tree_t *exp_val;
	exp_list_t *exp_list_val;
	stmt_list_t *stmt_list_val;
}

%token PROGRAM
%token VAR
%token ARRAY 
%token OF	
%token INTEGER
%token REAL
%token FUNCTION
%token PROCEDURE
%token BBEGIN
%token END
%token ASSIGNOP
%token IF
%token THEN
%token ELSE
%token WHILE
%token FOR
%token DO
%token TO
%token DOTDOT

%token <sval> ID
%token <ival> INUM
%token <fval> RNUM
%token <opval> ADDOP
%token <opval> MULOP
%token <opval> RELOP
%token <opval> NOT


%type <sym_stack_val> program
%type <stmt_val> statement;
%type <stmt_val> procedure_statement;
%type <stmt_val> compound_statement;
%type <stmt_list_val> optional_statements;
%type <stmt_list_val> statement_list;
%type <exp_val> expression;
%type <exp_val> factor;
%type <exp_val> term;
%type <exp_val> simple_expression;
%type <exp_list_val> expression_list;
%type <sym_ref> variable;
//%type <stmt_list_val> statement_list;


%%
program:
	{
		sym_table = init_stack(init_table());
	}
	PROGRAM ID '(' identifier_list ')' ';'
	declarations 
	subprogram_declarations 
	compound_statement 
	'.'
	{ 
		$$ = sym_table;
		wprintf("\n");
		print_stmt_tree($10, 0);
	}
	;

identifier_list: ID 
	{
		table_put(sym_table->scope, $1);
	}
	| identifier_list ',' ID
	{
		table_put(sym_table->scope, $3);
	}
	;

declarations: declarations VAR identifier_list ':' type ';' 
	{

	}
	| empty 
	;

type: standard_type
	| ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
	;
	
standard_type: INTEGER
	| REAL

subprogram_declarations: subprogram_declarations subprogram_declaration ';'
	| empty
	;

subprogram_declaration: subprogram_head declarations subprogram_declarations compound_statement;

subprogram_head: FUNCTION ID arguments ':' standard_type ';'
	{
		table_put(sym_table->scope, $2);
	}
	| PROCEDURE ID arguments ';'
	{
		table_put(sym_table->scope, $2);
	}
	;

arguments: '(' parameter_list ')'
	| empty
	;

parameter_list: identifier_list ':' type
	| parameter_list ';' identifier_list ':' type
	;

compound_statement: BBEGIN optional_statements END
	{
		stmt_t *tmp = init_stmt(COMPOUND_STMT);
		tmp->stmt.compound_stmt.body_stmt = $2;
		$$ = tmp;
	}
	;

optional_statements: statement_list
	{
		$$ = $1;
	}
	| empty
	{
		$$ = NULL;
	}
	;

statement_list: statement 
	{
		$$ = init_stmt_list($1);
	}
	| statement_list ';' statement {
		stmt_list_t *tmp = init_stmt_list($3);
		tmp->next = $1;
		$$ = tmp;
	}
	;

statement: procedure_statement 
	{
		$$ = $1;
	}
	| variable ASSIGNOP expression
	{
		stmt_t *tmp = init_stmt(ASSIGNMENT_STMT);
		tmp->stmt.assn_stmt.sym_ref = $1;
		tmp->stmt.assn_stmt.exp = $3;
		$$ = tmp;
	}
	| compound_statement
	{
		$$ = $1;
	}
	| IF expression THEN statement ELSE statement
	{
		stmt_t *tmp = init_stmt(IF_STMT);
		tmp->stmt.if_stmt.exp = $2;
		tmp->stmt.if_stmt.true_stmt = $4;
		tmp->stmt.if_stmt.false_stmt = $6;
		$$ = tmp;
	}
	| WHILE expression DO statement
	{
		stmt_t *tmp = init_stmt(WHILE_STMT);
		tmp->stmt.while_stmt.exp = $2;
		tmp->stmt.while_stmt.body_stmt = $4;
		$$ = tmp;
	}
	| FOR variable ASSIGNOP expression TO expression DO statement
	{
		stmt_t *assn = init_stmt(ASSIGNMENT_STMT);
		assn->stmt.assn_stmt.sym_ref = $2;
		assn->stmt.assn_stmt.exp = $4;
		stmt_t *tmp = init_stmt(FOR_STMT);
		tmp->stmt.for_stmt.exp_bound = $6;
		tmp->stmt.for_stmt.body_stmt = $8;
		tmp->stmt.for_stmt.assign_stmt = assn;
		$$ = tmp;
	}
	;

variable: ID
	{
		$$ = search_stack(sym_table, $1);
	}
	| ID '[' expression ']'
	{
		$$ = search_stack(sym_table, $1);
	}
	;

procedure_statement: ID 
	{
		stmt_t *tmp = init_stmt(PROCEDURE_STMT);
		tmp->stmt.proc_stmt.sym_ref = search_stack(sym_table, $1);
		tmp->stmt.proc_stmt.exp_list = NULL;
		$$ = tmp;
	}
	| ID '(' expression_list ')'
	{
		stmt_t *tmp = init_stmt(PROCEDURE_STMT);
		tmp->stmt.proc_stmt.sym_ref = search_stack(sym_table, $1);
		tmp->stmt.proc_stmt.exp_list = $3;
		$$ = tmp;
	}
	;

expression_list: expression
	{
		$$ = init_exp_list($1);
	}
	| expression_list ',' expression
	{
		exp_list_t *tmp = init_exp_list(init_exp_tree(NULL));
		tmp->next = $1;
		$$ = tmp;
	}
	| empty
	{
		$$ = NULL;
	}
	;

expression: simple_expression
	{
		$$ = $1;
		wprintf("\n");
		print_exp_tree($$, 0);
	}
	| simple_expression RELOP simple_expression
	{
		$$ = init_exp_tree(NULL);
	}
	;

simple_expression: term
	{
		$$ = $1;
	}
	| ADDOP term {
		exp_node_t *node = init_exp_node(OP_EXP, (void *)$1);
		$$ = init_exp_tree(node);
		$$->right = $2;
	}
	| simple_expression ADDOP term
	{
		exp_node_t *node = init_exp_node(OP_EXP, (void *)$2);
		$$ = init_exp_tree(node);
		$$->right = $1;
		$$->left = $3;
	}
	;

term: factor
	{
		$$ = $1;
	}
	| term MULOP factor
	{
		exp_node_t *node = init_exp_node(OP_EXP, (void *)$2);
		$$ = init_exp_tree(node);
		$$->right = $1;
		$$->left = $3;
	}
	;

factor: ID
	{
		sym_node_t *ref = search_stack(sym_table, $1);
		exp_node_t *node = init_exp_node(VAR_EXP, (void *)ref);
		$$ = init_exp_tree(node);
	}
	| ID '(' expression_list ')' 
	{
		sym_node_t *ref = search_stack(sym_table, $1);
		func_exp_t *func = init_func_exp(ref, $3);
		exp_node_t *node = init_exp_node(FUNC_EXP, (void *)func);
		$$ = init_exp_tree(node);
	}
	| ID '[' expression ']'
	{
		sym_node_t *ref = search_stack(sym_table, $1);
		array_exp_t *array = init_array_exp(ref, $3);
		exp_node_t *node = init_exp_node(ARRAY_EXP, (void *)array);
		$$ = init_exp_tree(node);
	}
	| INUM
	{
		int *val = &$1;
		exp_node_t *node = init_exp_node(INTEGER_EXP, (void *)val);
		$$ = init_exp_tree(node);
	}
	| RNUM
	{
		float *val = &$1;
		exp_node_t *node = init_exp_node(REAL_EXP, (void *)val);
		$$ = init_exp_tree(node);
	}
	| '(' expression ')'
	{
		$$ = $2;
	}
	| NOT factor
	{
		exp_node_t *node = init_exp_node(OP_EXP, (void *)$1);
		$$ = init_exp_tree(node);
		$$->right = $2;
	}
	;

empty:  ;


%%

int main(int argc, char ** argv) {
	if (argc != 2) {
		fprintf(stderr, "USAGE: ./wumbo <inputfile>");
		return -1;
	}
	
	FILE *input_file = fopen(argv[1], "r");

	if (!input_file) {
		fprintf(stderr, "Can't open input file: %s\n", argv[1]);
		return -1;
	}

	yyin = input_file;


	do {
		yyparse();
	} while (!feof(yyin));
	return 0;
}