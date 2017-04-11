#ifndef __EXP_TREE__
#define __EXP_TREE__

#include "defs.h"

typedef struct exp_node_s {
    exp_type type;
    union {
        float fval;
        int ival;
        op_type op;
    };
} exp_node_t;

typedef struct exp_tree_s {
    exp_node_t *node;
    struct exp_tree_s *left;
    struct exp_tree_s *right;
} exp_tree_t;

typedef struct exp_list_s {
    exp_tree_t *exp;
    struct exp_list_s *next;
} exp_list_t;

void print_tree(exp_tree_t *, int);
ret_type get_exp_type(exp_tree_t *);

#endif