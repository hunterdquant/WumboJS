#include "sym_table.h"
#include "defs.h"

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
            struct assn_stmt *assign_stmt;
            struct stmt_s *body_stmt;
        } for_stmt;
        struct {
            struct stmt_s *body_stmt;
        } compound_stmt;
        struct {
            sym_node_t *sym_ref;
            exp_list_t *exp_list;
        } proc_stmt;
    } stmt;
} stmt_t;
