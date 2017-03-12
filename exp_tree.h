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
    struct exp_tree_s *left;
    struct exp_tree_s *right;
} exp_tree_t;

ret_type get_exp_type(exp_tree_t *tree) {
    if (tree->node->type == OP_EXP) {
        ret_type left_ret;
        ret_type right_ret;
        if (tree->left && tree->right) {
            left_ret = get_exp_type(tree->left);
            right_ret = get_exp_type(tree->right);
            if (left_ret == right_ret) {
                return left_ret;
            }
        } else if (tree->left) {
            left_ret = get_exp_type(tree->left);
            return left_ret;
        } else {
            right_ret = get_exp_type(tree->right);
            return right_ret;
        }
        return TYPE_ERROR;
    } else {
        return (tree->node->type == INTEGER_EXP) ? INTEGER_EXP : REAL_EXP;
    }
}