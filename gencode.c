#include <stdio.h>

#include "exp_tree.h"
#include "stmt.h"
#include "defs.h"

#include "gencode.h"

long int label = 0;
extern long int LINE_COUNT;
extern sym_stack_t *sym_table;
int sp = 0;
int rstack[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
char *regs[] = {"%rax", "%rbx", "%rcx", "%rdx", "%r8", "%r9", "%r10", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15"};

void gen_code_end_main(FILE *out) {
    wfprintf(out, "}\n");
}

void gen_code_main(FILE *out, char *name) {
    wfprintf(out, "function %s() {\n", name);
}

void gen_code_func_begin1(FILE *out, char *name) {
    wfprintf(out, "function %s(", name);
}

void gen_code_func_begin2(FILE *out) {
    wfprintf(out, ") {\n");
}

void gen_code_func_end(FILE *out) {
    wfprintf(out, "}\n");
}

void gen_code_variable_decl(FILE *out, id_list_t *list) {
    wfprintf(out, "let ");
    gen_code_identifier_list(out, list);
    wfprintf(out, ";\n");
}

void gen_code_identifier_list(FILE *out, id_list_t *list) {
    if (!list) {
        return;
    }
    wfprintf(out, "%s", list->id);
    list = list->next;
    while (list) {
        wfprintf(out, ", %s", list->id);
        list = list->next;
    }
}

void gen_code_exp(FILE *out, exp_tree_t *tree) {
    if (!tree) {
        return;
    }
    exp_node_t *node = tree->node;
    if (node->type == OP_EXP && node->op == DIV_OP) {
        wfprintf(out, "Math.floor(");
    }
    gen_code_exp(out, tree->left);
    switch (node->type) {
        case OP_EXP:
            switch (node->op) {
                case ADD_OP:
                    wfprintf(out, "+");
                    break;
                case SUB_OP:
                    wfprintf(out, "-");
                    break;
                case MUL_OP:
                    wfprintf(out, "*");
                    break;
                case DIV_OP:
                    wfprintf(out, "/");
                    break;
                case EQ_OP:
                    wfprintf(out, "==");
                    break;
                case L_OP:
                    wfprintf(out, "<");
                    break;
                case G_OP:
                    wfprintf(out, ">");
                    break;
                case LE_OP:
                    wfprintf(out, "<=");
                    break;
                case GE_OP:
                    wfprintf(out, ">=");
                    break;
                case NEQ_OP:
                    wfprintf(out, "!=");
                    break;
                case NOT_OP:
                    wfprintf(out, "!");
                    break;
                default:
                    panic("\nUnrecognized operator, line %d\n", LINE_COUNT);
            }
            break;
        case INTEGER_EXP:
            wfprintf(out, "%d", node->ival);
            break;
        case REAL_EXP:
            wfprintf(out, "%f", node->fval);
            break;
        case VAR_EXP:
            if (!node->sym_ref) {
                panic("\nUndeclared variable. Line %d\n", LINE_COUNT);
            }
            wfprintf(out, "%s", node->sym_ref->sym);
            break;
        case FUNC_EXP: {
            exp_list_t *tmp = node->func_exp->args;
            if (!node->func_exp->sym_ref) {
                panic("\nUndeclared function. Line %d\n", LINE_COUNT);
            }
            wfprintf(out, "%s(", node->func_exp->sym_ref->sym);
            if (!tmp) {
                wfprintf(out, ")");
                break;
            }
            gen_code_exp(out, tmp->exp);
            tmp = tmp->next;
            while (tmp) {
                wfprintf(out, ", ");
                gen_code_exp(out, tmp->exp);
                tmp = tmp->next;
            }
            wfprintf(out, ")");
            break;
        }
        case ARRAY_EXP: {
            if (!node->array_exp->sym_ref) {
                panic("\nUndeclared array. Line:%d\n", LINE_COUNT);
            }
            wfprintf(out, "%s[", node->array_exp->sym_ref->sym);
            gen_code_exp(out, node->array_exp->arg);
            wfprintf(out, "]");
            break;
        }
        default:
            panic("\nUnrecognizable expression, line %d\n", LINE_COUNT);
    }
    gen_code_exp(out, tree->right);
    if (node->type == OP_EXP && node->op == DIV_OP) {
        wfprintf(out, ")");
    }
}

void gen_code_stmt(FILE *out, stmt_t *stmt) {
    if (!stmt) {
        return;
    }
    switch (stmt->type) {
        case COMPOUND_STMT: {
            stmt_list_t *temp = stmt->stmt.compound_stmt.body_stmt;
            while (temp) {
                gen_code_stmt(out, temp->stmt);
                temp = temp->next;
            }
            break;
        }
        case ASSIGNMENT_STMT:
            gen_code_assign_stmt(out, stmt);
            break;
        case PROCEDURE_STMT:
            gen_code_proc_stmt(out, stmt);
            break;
        case IF_STMT:
            gen_code_if_stmt(out, stmt);
            break;
        case WHILE_STMT:
            gen_code_while_stmt(out, stmt);
            break;
        case FOR_STMT:
            gen_code_for_stmt(out, stmt);
            break;
        default:
            panic("Unrecognized stmt type\n");
    }
}

void gen_code_if_stmt(FILE *out, stmt_t *stmt) {
            wfprintf(out, "if (");
            gen_code_exp(out, stmt->stmt.if_stmt.exp);
            wfprintf(out, ") {\n");
            gen_code_stmt(out, stmt->stmt.if_stmt.true_stmt);
            if (!stmt->stmt.if_stmt.false_stmt) {
                wfprintf(out, "}\n");
                return;
            }
            wfprintf(out, "} else {\n");
            gen_code_stmt(out, stmt->stmt.if_stmt.false_stmt);
            wfprintf(out, "}\n");
}

void gen_code_assign_stmt(FILE *out, stmt_t *stmt) {
    if (stmt->stmt.assn_stmt.sym_ref->dtype->type == ARRAY_SYM) {
        panic("\nNo arrays for you.\n");
    }
    if (stmt->stmt.assn_stmt.sym_ref->ntype == FUNC_NODE) {
        wfprintf(out, "return ");
        gen_code_exp(out, stmt->stmt.assn_stmt.exp);
        wfprintf(out, ";\n");
    } else {
        wfprintf(out, "%s = ", stmt->stmt.assn_stmt.sym_ref->sym);
        gen_code_exp(out, stmt->stmt.assn_stmt.exp);
        wfprintf(out, ";\n");
   }
}

void gen_code_while_stmt(FILE *out, stmt_t *stmt) {
    wfprintf(out, "while (");
    gen_code_exp(out, stmt->stmt.while_stmt.exp);
    wfprintf(out, ") {\n");
    gen_code_stmt(out, stmt->stmt.while_stmt.body_stmt);
    wfprintf(out, "}\n");
}

void gen_code_for_stmt(FILE *out, stmt_t *stmt) {
    wfprintf(out, "for (");
    wfprintf(out, "%s = ", stmt->stmt.for_stmt.assign_stmt->stmt.assn_stmt.sym_ref->sym);
    gen_code_exp(out, stmt->stmt.for_stmt.assign_stmt->stmt.assn_stmt.exp);
    wfprintf(out, "; %s < ", stmt->stmt.for_stmt.assign_stmt->stmt.assn_stmt.sym_ref->sym);
    gen_code_exp(out, stmt->stmt.for_stmt.exp_bound);
    wfprintf(out, "; %s++) {\n");
    gen_code_stmt(out, stmt->stmt.for_stmt.body_stmt);
}

void gen_code_proc_stmt(FILE *out, stmt_t *stmt) {
    if (strcmp(stmt->stmt.proc_stmt.sym_ref->sym, "write") == 0) {
        wfprintf(out, "alert(");
        exp_list_t *arg_list = stmt->stmt.proc_stmt.exp_list;
        if (arg_list) {
            gen_code_exp(out, arg_list->exp);
            arg_list = arg_list->next;
        }
        wfprintf(out, ");\n");
    } else if (strcmp(stmt->stmt.proc_stmt.sym_ref->sym, "read") == 0) {
        sym_node_t *n = stmt->stmt.proc_stmt.exp_list->exp->node->sym_ref;
        wfprintf(out, "%s = prompt(\"Enter your input:\");\n", n->sym);
    } else {
        wfprintf(out, "%s(", stmt->stmt.proc_stmt.sym_ref->sym);
        exp_list_t *arg_list = stmt->stmt.proc_stmt.exp_list;
        if (arg_list) {
            gen_code_exp(out, arg_list->exp);
            arg_list = arg_list->next;
        }
        while (arg_list) {
            wfprintf(out, ", ");
            gen_code_exp(out, arg_list->exp);
            arg_list = arg_list->next;
        }
        wfprintf(out, ");\n");
    }
}

void gen_code_read(FILE *out) {

}

void gen_code_write(FILE *out) {

}