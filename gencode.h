#ifndef __GENCODE__
#define __GENCODE__

#include "defs.h"

void gen_code_begin(FILE *out, char *file_name);
void gen_code_end(FILE *out);
void gen_code_main(FILE *out, char *entry_name);

void gen_code_func_begin(FILE *out, char *func_name);
void gen_code_func_end(FILE *out);
void gen_code_prelude(FILE *out, char *func_name);
void gen_code_prologue(FILE *out, char *func_name);

void gen_code_exp(FILE *out, exp_tree_t *tree);

void gen_code_stmt(FILE *out, stmt_t *stmt);
void gen_code_if_stmt(FILE *out, stmt_t *stmt);
void gen_code_assign_stmt(FILE *out, stmt_t *stmt);
void gen_code_while_stmt(FILE *out, stmt_t *stmt);
void gen_code_for_stmt(FILE *out, stmt_t *stmt);
void gen_code_compound_stmt(FILE *out, stmt_t *stmt);
void gen_code_proc_stmt(FILE *out, stmt_t *stmt);

void gen_code_read(FILE *out, sym_node_t *var);
void gen_code_write(FILE *out);

void gen_code_read_label(FILE *out);
void gen_code_write_label(FILE *out);

#endif