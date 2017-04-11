#include "exp_tree.h"
#include "defs.h"
#include "wumbo_utils.h"
#include <stdio.h>

void print_exp_tree(exp_tree_t *tree, int spaces) {
    exp_node_t *node = tree->node;
    if (!tree) {
        return;
    }
    print_spaces(spaces);
    switch (node->type) {
        case OP_EXP:
            switch (node->op) {
                case ADD_OP:
                    fprintf(stderr, "[+]");
                    break;
                case SUB_OP:
                    fprintf(stderr, "[-]");
                    break;
                case MUL_OP:
                    fprintf(stderr, "[*]");
                    break;
                case DIV_OP:
                    fprintf(stderr, "[/]");
                    break;
                case EQ_OP:
                    fprintf(stderr, "[==]");
                    break;
                case L_OP:
                    fprintf(stderr, "[<]");
                    break;
                case G_OP:
                    fprintf(stderr, "[>]");
                    break;
                case LE_OP:
                    fprintf(stderr, "[<=]");
                    break;
                case GE_OP:
                    fprintf(stderr, "[>=]");
                    break;
                case NEQ_OP:
                    fprintf(stderr, "[<>]");
                    break;
                case NOT_OP:
                    fprintf(stderr, "[not]");
                    break;
                default:
                    fprintf(stderr, "Not type found for OP_EXP");
            }
            break;
        case INTEGER_EXP:
            fprintf(stderr, "[INT:%d]", node->ival);
            break;
        case REAL_EXP:
            fprintf(stderr, "[REAL:%f]", node->fval);
            break;
        default:
            fprintf(stderr, "Not type found for EXP_TYPE\n");
    }
    fprintf(stderr, "\n");
    print_exp_tree(tree->left, spaces+4);
    print_exp_tree(tree->right, spaces+4);
}

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
        return W_TYPE_ERROR;
    } else {
        return (tree->node->type == INTEGER_EXP) ? INTEGER_EXP : REAL_EXP;
    }
}