#include <stdio.h>
#include <stdlib.h>

#include "wumbo_utils.h"
#include "exp_tree.h"
#include "stmt.h"

void print_stmt_tree(stmt_t *stmt, int spaces) {
    if (!stmt) {
        return;
    }
    print_spaces(spaces);
    switch (stmt->type) {
        case COMPOUND_STMT: {
            fprintf(stderr, "[BEGIN COMP STMT]\n");
            stmt_list_t *temp = stmt->stmt.compound_stmt.body_stmt;
            while (temp) {
                print_stmt_tree(temp->stmt, spaces+4);
                fprintf(stderr, "\n");
                temp = temp->next;
            }
            fprintf(stderr, "[END COMP STMT]\n");
            break;
        }
        case ASSIGNMENT_STMT:
            fprintf(stderr, "[ASSN STMT]\n");
            //print_sym_ref(stmt->stmt.assn_stmt.sym_ref);
            print_spaces(spaces+4);
            fprintf(stderr, "[:=]\n");
            print_exp_tree(stmt->stmt.assn_stmt.exp, spaces+4);
            break;
        case PROCEDURE_STMT: {
            fprintf(stderr, "[PROC STMT]\n");
            exp_list_t *arg_list = stmt->stmt.proc_stmt.exp_list;
           // print_sym_ref(stmt->stmt.proc_stmt.sym_ref);
            print_spaces(spaces+2);
            fprintf(stderr, "ARGS:\n");

            while (arg_list) {
                print_exp_tree(arg_list->exp, spaces+4);
                arg_list = arg_list->next;
            }
            break;
        }
        case IF_STMT:
            fprintf(stderr, "[IF STMT]\n");
            print_exp_tree(stmt->stmt.if_stmt.exp, spaces+2);
            print_spaces(spaces+2);
            fprintf(stderr, "[THEN STMT]\n");
            print_stmt_tree(stmt->stmt.if_stmt.true_stmt, spaces+4);
            print_spaces(spaces+2);
            fprintf(stderr, "[ELSE STMT]\n");
            print_stmt_tree(stmt->stmt.if_stmt.false_stmt, spaces+4);
            break;
        case WHILE_STMT:
            fprintf(stderr, "[WHILE STMT]\n");
            print_exp_tree(stmt->stmt.while_stmt.exp, spaces+2);
            print_stmt_tree(stmt->stmt.while_stmt.body_stmt, spaces+4);
            break;
        case FOR_STMT:
            fprintf(stderr, "[FOR STMT]\n");
            print_stmt_tree(stmt->stmt.for_stmt.assign_stmt, spaces+2);
            print_exp_tree(stmt->stmt.for_stmt.exp_bound, spaces+2);
            print_stmt_tree(stmt->stmt.for_stmt.body_stmt, spaces+4);
            break;
        default:
            fprintf(stderr, "Unrecognized stmt type\n");
    }
}