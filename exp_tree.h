#include "defs.h"

typedef struct exp_node_s {
    exp_type type;
    union {
        float fval;
        int ival;
        op_type op;
    }
} exp_node_t;

typedef struct exp_tree_s {
    exp_node_t *node;
    exp_tree_s *left;
    exp_tree_s *right;
} exp_tree_t;