#include <stdio.h>

#include "exp_tree.h"
#include "stmt.h"
#include "defs.h"

long int label = 0;

int sp = 0;
int rstack[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
char *regs[] = {"%rax", "%rbx", "%rcx", "%rdx", "%r8", "%r9", "%r10", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

void gen_code_begin(FILE *out, char *file_name) {
    wfprintf(out, "\t.file\t\"%s\"\n", file_name);
    wfprintf(out, "\t.text\n");
}

void gen_code_end(FILE *out) {
    wfprintf(out, "\t.ident\t\"GCC: (Ubuntu 4.8.5-2ubuntu1-14.04.1) 4.8.5\"\n");
    wfprintf(out, "\t.section\t.note.GNU-stack,\"\",@progbits\n");
}

void gen_code_main(FILE *out, char *entry_name) {
    wfprintf(out, "main:\n");
    wfprintf(out, "\tpushq\t%%rbp\n");
    wfprintf(out, "\tmovq\t%%rsp, %%rbp\n");
    wfprintf(out, "\tmovl\t$0, %%eax\n");
    wfprintf(out, "\tcall\t%s\n", entry_name);
    wfprintf(out, "\tpopq\t%%rbp\n");
    wfprintf(out, "\tret\n");
}

void gen_code_func_begin(FILE *out, char *func_name) {
    wfprintf(out, "%s:\n", func_name);
    wfprintf(out, "\tpushq\t%%rbp\n");
    wfprintf(out, "\tmovq\t%%rsp, %%rbp\n");
}

void gen_code_func_end(FILE *out) {
    wfprintf(out, "\tpopq\t%%rbp\n");
    wfprintf(out, "\tret\n");
}

void gen_code_prelude(FILE *out, char *func_name) {
    wfprintf(out, "\t.globl\t%s\n", func_name);
    wfprintf(out, "\t.type\t%s, @function\n", func_name);
}

void gen_code_prologue(FILE *out, char *func_name) {
    wfprintf(out, "\t.size\t%s, .-%s\n", func_name, func_name);
}


void gen_code_exp(FILE *out, exp_tree_t *tree) {

}

void gen_code_stmt(FILE *out, stmt_t *stmt) {

}
void gen_code_if_stmt(FILE *out, stmt_t *stmt) {

}

void gen_code_assign_stmt(FILE *out, stmt_t *stmt) {

}

void gen_code_while_stmt(FILE *out, stmt_t *stmt) {

}

void gen_code_for_stmt(FILE *out, stmt_t *stmt) {

}

void gen_code_compound_stmt(FILE *out, stmt_t *stmt) {

}

void gen_code_proc_stmt(FILE *out, stmt_t *stmt) {

}

void gen_code_read(FILE *out) {

}

void gen_code_write(FILE *out) {

}

void gen_code_read_label(FILE *out) {
    wfprintf(out, ".LC0:\n");
    wfprintf(out, "\t.string \"%%d\"\n");
}

void gen_code_write_label(FILE *out) {
    wfprintf(out, ".LC0:\n");
    wfprintf(out, "\t.string \"%%d\"\n");
}