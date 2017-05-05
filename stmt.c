#include <stdio.h>
#include <stdlib.h>

#include "wumbo_utils.h"
#include "exp_tree.h"
#include "stmt.h"

extern long int LINE_COUNT;

stmt_t *init_stmt(stmt_type type) {
    stmt_t *tmp = (stmt_t *)malloc(sizeof(stmt_t));
    tmp->type = type;
    return tmp;
}

stmt_list_t *init_stmt_list(stmt_t *stmt) {
    stmt_list_t *tmp = (stmt_list_t *)malloc(sizeof(stmt_list_t));
    tmp->stmt = stmt;
    tmp->next = NULL;
    return tmp;
}

void destroy_stmt(stmt_t *stmt) {
    if (!stmt) {
        return;
    }
    switch (stmt->type) {
        case COMPOUND_STMT:
            destroy_stmt_list(stmt->stmt.compound_stmt.body_stmt);
            break;
        case ASSIGNMENT_STMT:
            destroy_exp_tree(stmt->stmt.assn_stmt.exp);
            break;
        case IF_STMT:
            destroy_exp_tree(stmt->stmt.if_stmt.exp);
            destroy_stmt(stmt->stmt.if_stmt.true_stmt);
            destroy_stmt(stmt->stmt.if_stmt.false_stmt);
            break;
        case WHILE_STMT:
            destroy_exp_tree(stmt->stmt.while_stmt.exp);
            destroy_stmt(stmt->stmt.while_stmt.body_stmt);
            break;
        case FOR_STMT:
            destroy_exp_tree(stmt->stmt.for_stmt.exp_bound);
            destroy_stmt(stmt->stmt.for_stmt.assign_stmt);
            destroy_stmt(stmt->stmt.for_stmt.body_stmt);
            break;
        case PROCEDURE_STMT:
            destroy_exp_list(stmt->stmt.proc_stmt.exp_list);
            break;
    }
    free(stmt);
}

void destroy_stmt_list(stmt_list_t *stmt_list) {
    if (!stmt_list) {
        return;
    }
    destroy_stmt_list(stmt_list->next);
    destroy_stmt(stmt_list->stmt);
    free(stmt_list);
}

void print_stmt_tree(stmt_t *stmt, int spaces) {
    if (!stmt) {
        return;
    }
    print_spaces(spaces);
    switch (stmt->type) {
        case COMPOUND_STMT: {
            wprintf("[BEGIN COMP STMT]\n");
            stmt_list_t *temp = stmt->stmt.compound_stmt.body_stmt;
            while (temp) {
                print_stmt_tree(temp->stmt, spaces+4);
                wprintf("\n");
                temp = temp->next;
            }
            wprintf("[END COMP STMT]\n");
            break;
        }
        case ASSIGNMENT_STMT:
            wprintf("[ASSN STMT]\n");
            //print_sym_ref(stmt->stmt.assn_stmt.sym_ref);
            print_spaces(spaces+4);
            wprintf("[:=]\n");
            print_exp_tree(stmt->stmt.assn_stmt.exp, spaces+4);
            break;
        case PROCEDURE_STMT: {
            wprintf("[PROC STMT]\n");
            exp_list_t *arg_list = stmt->stmt.proc_stmt.exp_list;
           // print_sym_ref(stmt->stmt.proc_stmt.sym_ref);
            print_spaces(spaces+2);
            wprintf("ARGS:\n");

            while (arg_list) {
                print_exp_tree(arg_list->exp, spaces+4);
                arg_list = arg_list->next;
            }
            break;
        }
        case IF_STMT:
            wprintf("[IF STMT]\n");
            print_exp_tree(stmt->stmt.if_stmt.exp, spaces+2);
            print_spaces(spaces+2);
            wprintf("[THEN STMT]\n");
            print_stmt_tree(stmt->stmt.if_stmt.true_stmt, spaces+4);
            print_spaces(spaces+2);
            wprintf("[ELSE STMT]\n");
            print_stmt_tree(stmt->stmt.if_stmt.false_stmt, spaces+4);
            break;
        case WHILE_STMT:
            wprintf("[WHILE STMT]\n");
            print_exp_tree(stmt->stmt.while_stmt.exp, spaces+2);
            print_stmt_tree(stmt->stmt.while_stmt.body_stmt, spaces+4);
            break;
        case FOR_STMT:
            wprintf("[FOR STMT]\n");
            print_stmt_tree(stmt->stmt.for_stmt.assign_stmt, spaces+2);
            print_exp_tree(stmt->stmt.for_stmt.exp_bound, spaces+2);
            print_stmt_tree(stmt->stmt.for_stmt.body_stmt, spaces+4);
            break;
        default:
            wprintf("Unrecognized stmt type\n");
    }
}

int semantic_check_body(sym_stack_t *scope, sym_node_t *ref, stmt_t *stmt) {
    int ret = (ref->ntype == FUNC_NODE) ? 0 : 1;
    if (!stmt) {
        return ret;
    }
    switch (stmt->type) {
        case COMPOUND_STMT: {
            stmt_list_t *temp = stmt->stmt.compound_stmt.body_stmt;
            while (temp) {
                ret = ret | semantic_check_body(scope, ref, temp->stmt);
                temp = temp->next;
            }
            break;
        }
        case ASSIGNMENT_STMT: {
            simple_type st;
            if (strcmp(stmt->stmt.assn_stmt.sym_ref->sym, ref->sym) == 0) {
                ret = 1;
                st = (stmt->stmt.assn_stmt.sym_ref->ftype->rtype == INTEGER_RET) ? INTEGER_TYPE : REAL_TYPE;
            } else {
                if (stmt->stmt.assn_stmt.sym_ref->dtype->type == ARRAY_SYM) {
                    st = stmt->stmt.assn_stmt.sym_ref->dtype->arr->stype;
                } else {
                    st = stmt->stmt.assn_stmt.sym_ref->dtype->stype;
                }
            }
            ret_type t = get_exp_type(stmt->stmt.assn_stmt.exp);
            sym_node_t *p = search_stack_func(scope, stmt->stmt.assn_stmt.sym_ref->sym);
            if (!p && strcmp(stmt->stmt.assn_stmt.sym_ref->sym, ref->sym) != 0) {
                panic("\nVariable \"%s\" is not mutable in this scope, line %d\n", stmt->stmt.assn_stmt.sym_ref->sym);
            }
            if (t == W_TYPE_ERROR) {
                panic("\nType error in expression at line %d\n", LINE_COUNT);
            }
            if (!((st == INTEGER_TYPE && t == INTEGER_RET) || (st == REAL_TYPE && t == REAL_RET))) {
                panic("\nType mismatch in ASSIGN statement statement at line %d\n", LINE_COUNT);
            }
            break;
        }
        case PROCEDURE_STMT: {
            exp_list_t *arg_list = stmt->stmt.proc_stmt.exp_list;
            sym_node_t *p = search_stack(scope, stmt->stmt.proc_stmt.sym_ref->sym);
            data_type_list_t *dt_list = p->ptype->types;
            while (arg_list && dt_list) {
                ret_type t = get_exp_type(arg_list->exp);
                if (!((t == INTEGER_RET && dt_list->type->stype == INTEGER_TYPE) || (t == REAL_RET && dt_list->type->stype == REAL_TYPE))) {
                    panic("\nType mismatch on parameter arguments, line %d\n", LINE_COUNT);
                }
                arg_list = arg_list->next;
                dt_list = dt_list->next;
            }
            if ((arg_list && !dt_list) || (!arg_list && dt_list)) {
                panic("\nProcedure call is lacking the required number of arguments, line %d\n", LINE_COUNT);
            }
            break;
        }
        case IF_STMT: {
            ret_type t = get_exp_type(stmt->stmt.if_stmt.exp);
            if (t == W_TYPE_ERROR) {
                panic("\nInvalid expression in IF-THEN-ELSE statement, type mismatch at line %d\n", LINE_COUNT);
            }
            if (t != BOOL_RET) {
                panic("\nInvalid expression in IF-THEN-ELSE statement, expects BOOL expression", LINE_COUNT);
            }
            ret = ret | semantic_check_body(scope, ref, stmt->stmt.if_stmt.true_stmt);
            ret = ret | semantic_check_body(scope, ref, stmt->stmt.if_stmt.false_stmt);
            break;
        }
        case WHILE_STMT: {
            ret_type t = get_exp_type(stmt->stmt.while_stmt.exp);
            if (t == W_TYPE_ERROR) {
                panic("\nInvalid expression in while statement, type mismatch at line %d\n", LINE_COUNT);
            }
            if (t != BOOL_RET) {
                panic("\nInvalid expression in while statement, expects BOOL expression at line %d\n", LINE_COUNT);
            }
            ret = ret | semantic_check_body(scope, ref, stmt->stmt.while_stmt.body_stmt);
            break;
        }
        case FOR_STMT: {
            semantic_check_body(scope, ref, stmt->stmt.for_stmt.assign_stmt);
            simple_type st = stmt->stmt.for_stmt.assign_stmt->stmt.assn_stmt.sym_ref->dtype->stype;
            ret_type t = get_exp_type(stmt->stmt.for_stmt.exp_bound);
            // Ensures type match for all params.
            if (!((st == INTEGER_TYPE && t == INTEGER_RET) || (st == REAL_TYPE && t == REAL_RET))) {
                    panic("\nType mismatch in FOR-DO construction line %d\n", LINE_COUNT);
            }
            ret = ret | semantic_check_body(scope, ref, stmt->stmt.for_stmt.assign_stmt);
            ret = ret | semantic_check_body(scope, ref, stmt->stmt.for_stmt.body_stmt);
            break;
        }
    }
    return ret;
}
