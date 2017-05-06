#ifndef __GENCODE__
#define __GENCODE__

#include "defs.h"

void gen_code_end_main(FILE *out);
void gen_code_main(FILE *out, char *entry_name);

void gen_code_func_begin1(FILE *out, char *name);
void gen_code_func_begin2(FILE *out);
void gen_code_func_end(FILE *out);

void gen_code_variable_decl(FILE *out, id_list_t *list);
void gen_code_identifier_list(FILE *out, id_list_t *list);

void gen_code_exp(FILE *out, exp_tree_t *tree);

void gen_code_stmt(FILE *out, stmt_t *stmt);
void gen_code_if_stmt(FILE *out, stmt_t *stmt);
void gen_code_assign_stmt(FILE *out, stmt_t *stmt);
void gen_code_while_stmt(FILE *out, stmt_t *stmt);
void gen_code_for_stmt(FILE *out, stmt_t *stmt);
void gen_code_proc_stmt(FILE *out, stmt_t *stmt);

void gen_code_read(FILE *out);
void gen_code_write(FILE *out);


#endif