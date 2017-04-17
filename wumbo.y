/* Context-free grammar for a pseudo Pascal language 
   grammar G = (Alphabet, Variables, Rules, StartSymbol)
 */
%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <assert.h>
  #include <string.h>


  #include "sym_table.h"
  #include "exp_tree.h"
  #include "defs.h"
  #include "stmt.h"
  #include "decl.h"


  extern FILE *yyin;
  extern long int LINE_COUNT;
  sym_stack_t *sym_table;
  long int label;
  FILE *wout;
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
	id_list_t *id_list;
	data_type_t *data_type;
	data_type_list_t *data_type_list;
	simple_type stype;
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


%type <sym_stack_val> program;
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
%type <id_list> identifier_list;
%type <data_type> type;
%type <stype> standard_type;
%type <data_type_list> arguments;
%type <data_type_list> parameter_list;
//%type <stmt_list_val> statement_list;

%%
program:
	{
		label = 0;
		sym_table = init_sym_stack(init_sym_table());
	}
	PROGRAM ID '(' identifier_list ')' ';'
	{
		char *name;
		if (strcmp($3, "main")) {
			name = "main1";
		} else {
			name = $3;
		}
		proc_type_t *main = init_proc_type(init_data_type_list(init_data_type(SIMPLE_SYM, (void *)NULL)));
		sym_node_t *node = init_sym_node(name, PROC_NODE, main, 0);
		table_put(sym_table->scope, node);
		id_list_t *id_list = $5;
		int in, out = 0;
		while (id_list) {
			if (!in && strcmp(id_list->id, "input")) {
				in = !in;
				proc_type_t *input = init_proc_type(init_data_type_list(init_data_type(SIMPLE_SYM, (void *)INTEGER_TYPE)));
				sym_node_t *node = init_sym_node("read", PROC_NODE, input, 0);
				table_put(sym_table->scope, node);
			} else if (!out && strcmp(id_list->id, "output")) {
				out = !out;
				proc_type_t *output = init_proc_type(init_data_type_list(init_data_type(SIMPLE_SYM, (void *)INTEGER_TYPE)));
				sym_node_t *node = init_sym_node("output", PROC_NODE, output, 0);
				table_put(sym_table->scope, node);
			}
			id_list = id_list->next;
		}
	}
	declarations 
	subprogram_declarations 
	compound_statement 
	'.'
	{ 
		$$ = sym_table;
		wprintf("\n");
		print_stmt_tree($11, 0);
		stack_pop(sym_table);
	}
	;

identifier_list: ID 
	{
		$$ = init_id_list($1);
	}
	| identifier_list ',' ID
	{
		id_list_t *tmp = init_id_list($3);
		tmp->next = $1;
		$$ = tmp;
	}
	;

declarations: declarations VAR identifier_list ':' type ';' 
	{
		data_type_t *type = $5;
		id_list_t *list = $3;

		while (list) {
			sym_node_t *node = init_sym_node(strdup(list->id), PRIM_NODE, $5, sym_table->scope->offset);
			sym_table->scope->offset+=4;
			table_put(sym_table->scope, node);
			list = list->next;
		}
	}
	| empty 
	;

type: standard_type
	{
		$$ = init_data_type(SIMPLE_SYM, (void *)$1);
	}
	| ARRAY '[' INUM DOTDOT INUM ']' OF standard_type
	{
		data_array_t *tmp = init_data_array($3, $5, $8);
		$$ = init_data_type(ARRAY_SYM, (void *)tmp);
	}
	;
	
standard_type: INTEGER
	{
		$$ = INTEGER_TYPE;
	}
	| REAL
	{
		$$ = REAL_TYPE;
	}
	;

subprogram_declarations: subprogram_declarations subprogram_declaration ';'
	| empty
	;

subprogram_declaration: subprogram_head declarations subprogram_declarations compound_statement
	{
		print_stmt_tree($4, 0);
		stack_pop(sym_table);
	};

subprogram_head: FUNCTION ID 
	{
			sym_table = stack_push(sym_table, init_sym_table());
	} 
	arguments ':' standard_type ';'
	{
		sym_stack_t *tmp = stack_pop(sym_table);
		func_type_t *func = init_func_type($4, $6);
		sym_node_t *node = init_sym_node(strdup($2), FUNC_NODE, func, sym_table->scope->offset);
		sym_table->scope->offset+=4;
		table_put(sym_table->scope, node);
		stack_push(sym_table, tmp->scope);
	}
	| PROCEDURE ID arguments ';'
	{
		sym_stack_t *tmp = stack_pop(sym_table);
		proc_type_t *proc = init_proc_type($3);
		sym_node_t *node = init_sym_node(strdup($2), PROC_NODE, proc, sym_table->scope->offset);
		sym_table->scope->offset+=4;
		table_put(sym_table->scope, node);
		stack_push(sym_table, tmp->scope);
	}
	;

arguments: '(' parameter_list ')'
	{
		$$ = $2;
	}
	| empty
	{
		$$ = NULL;
	}
	;

parameter_list: identifier_list ':' type
	{
		data_type_t *type = $3;
		id_list_t *list = $1;
		while (list) {
			sym_table->scope->offset-=4;
			sym_node_t *node = init_sym_node(strdup(list->id), PRIM_NODE, type, sym_table->scope->offset);
			table_put(sym_table->scope, node);
			list = list->next;
		}

		list = $1;
		data_type_list_t *tmp = init_data_type_list(type);
		data_type_list_t *cur = tmp;
		cur = tmp;
		list = list->next;
		while (list) {
			cur->next = init_data_type_list(type);
			cur = cur->next;
			list = list->next;
		}
		$$ = tmp;
	}
	| parameter_list ';' identifier_list ':' type
	{
		data_type_t *type = $5;
		id_list_t *list = $3;
		while (list) {
			sym_table->scope->offset-=4;
			sym_node_t *node = init_sym_node(strdup(list->id), PRIM_NODE, type, sym_table->scope->offset);
			table_put(sym_table->scope, node);
			list = list->next;
		}

		list = $3;
		data_type_list_t *tmp = init_data_type_list(type);
		data_type_list_t *cur = tmp;
		cur = tmp;
		list = list->next;
		while (list) {
			cur->next = init_data_type_list(type);
			cur = cur->next;
			list = list->next;
		}
		$$ = tmp;
	}
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
		exp_list_t *tmp = init_exp_list($3);
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
	}
	| simple_expression RELOP simple_expression
	{
		exp_node_t *node = init_exp_node(OP_EXP, (void *)$2);
		$$ = init_exp_tree(node);
		$$->right = $1;
		$$->left = $3;
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
	if (argc < 2) {
		fprintf(stderr, "USAGE: ./wumbo <inputfile>");
		return -1;
	}
	
	FILE *input_file = fopen(argv[1], "r");

	if (!input_file) {
		fprintf(stderr, "Can't open input file: %s\n", argv[1]);
		return -1;
	}

	if (argc == 3) {
		wout = fopen(argv[2], "w");
	} else {
		wout = fopen("org.asm", "w");
	}

	yyin = input_file;

	do {
		yyparse();
	} while (!feof(yyin));
	return 0;
}