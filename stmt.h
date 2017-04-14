#ifndef __STMT__
#define __STMT__

#include "sym_table.h"
#include "defs.h"

struct stmt_list_s;
typedef struct stmt_list_s stmt_list_t;

typedef struct stmt_s {
    stmt_type type;
    union {
        struct {
            exp_tree_t *exp;
            sym_node_t *sym_ref;
        } assn_stmt;
        struct {
            exp_tree_t *exp;
            struct stmt_s *true_stmt;
            struct stmt_s *false_stmt;
        } if_stmt;
        struct {
            exp_tree_t *exp;
            struct stmt_s *body_stmt;
        } while_stmt;
        struct {
            exp_tree_t *exp_bound;
            struct stmt_s *assign_stmt;
            struct stmt_s *body_stmt;
        } for_stmt;
        struct {
            stmt_list_t *body_stmt;
        } compound_stmt;
        struct {
            sym_node_t *sym_ref;
            exp_list_t *exp_list;
        } proc_stmt;
    } stmt;
} stmt_t;

struct stmt_list_s {
    stmt_t *stmt;
    struct stmt_list_s *next;
};

stmt_t *init_stmt(stmt_type);
stmt_list_t *init_stmt_list(stmt_t *);

void destroy_stmt(stmt_t *);
void destroy_stmt_list(stmt_list_t *);

void print_stmt_tree(stmt_t *, int);
#endif