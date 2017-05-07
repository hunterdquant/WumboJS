#include "exp_tree.h"
#include "defs.h"
#include "wumbo_utils.h"
#include <stdio.h>
#include <stdlib.h>

extern long int LINE_COUNT;

void print_exp_tree(exp_tree_t *tree, int spaces) {
    if (!tree) {
        return;
    }
    exp_node_t *node = tree->node;
    print_spaces(spaces);
    switch (node->type) {
        case OP_EXP:
            switch (node->op) {
                case ADD_OP:
                    wprintf("[+]");
                    break;
                case SUB_OP:
                    wprintf("[-]");
                    break;
                case MUL_OP:
                    wprintf("[*]");
                    break;
                case DIV_OP:
                    wprintf("[/]");
                    break;
                case EQ_OP:
                    wprintf("[=]");
                    break;
                case L_OP:
                    wprintf("[<]");
                    break;
                case G_OP:
                    wprintf("[>]");
                    break;
                case LE_OP:
                    wprintf("[<=]");
                    break;
                case GE_OP:
                    wprintf("[>=]");
                    break;
                case NEQ_OP:
                    wprintf("[<>]");
                    break;
                case NOT_OP:
                    wprintf("[not]");
                    break;
                default:
                    wprintf("Not type found for OP_EXP");
            }
            break;
        case INTEGER_EXP:
            wprintf("[INT:%d]", node->ival);
            break;
        case REAL_EXP:
            wprintf("[REAL:%f]", node->fval);
            break;
        case VAR_EXP:
            if (!node->sym_ref) {
                panic("Undeclared variable. Line:%d\n", LINE_COUNT);
            }
            wprintf("[VAR:%s]", node->sym_ref->sym);
            break;
        case FUNC_EXP: {
            exp_list_t *tmp = node->func_exp->args;
            if (!node->func_exp->sym_ref) {
                panic("Undeclared function. Line:%d\n", LINE_COUNT);
            }
            wprintf("[FUNC:%s]", node->func_exp->sym_ref->sym);
            while (tmp) {
                wprintf("\n");
                print_exp_tree(tmp->exp, spaces+4);
                tmp = tmp->next;
            }
            break;
        }
        case ARRAY_EXP: {
            if (!node->array_exp->sym_ref) {
                panic("Undeclared array. Line:%d\n", LINE_COUNT);
            }
            wprintf("[ARRAY:%s]", node->array_exp->sym_ref->sym);
            print_exp_tree(node->array_exp->arg, spaces+4);
            break;
        }
        default:
            wprintf("Not type found for EXP_TYPE\n");
    }
    wprintf("\n");
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
            switch (tree->node->op) {
                case ADD_OP:
                case SUB_OP:
                case MUL_OP:
                case DIV_OP:
                    if (left_ret == right_ret) {
                            return left_ret;
                    }
                case EQ_OP:
                case NEQ_OP:
                case L_OP:
                case G_OP:
                case LE_OP:
                case GE_OP:
                    if (left_ret == right_ret) {
                        return BOOL_RET;
                    }
                    break;
                case NOT_OP:
                    if (right_ret == BOOL_RET) {
                        return BOOL_RET;
                    }
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
        if (tree->node->type == INTEGER_EXP) {
            return INTEGER_RET;
        } else if (tree->node->type == REAL_EXP) {
            return REAL_RET;
        } else if (tree->node->type == FUNC_EXP) {
            if (tree->node->func_exp->sym_ref->ftype->rtype == INTEGER_RET) {
                return INTEGER_RET;
            } else if (tree->node->func_exp->sym_ref->ftype->rtype == REAL_RET) {
                return REAL_RET;
            }
        } else if (tree->node->type == VAR_EXP) {
            if (tree->node->sym_ref->dtype->stype == INTEGER_TYPE) {
                return INTEGER_RET;
            } else if (tree->node->sym_ref->dtype->stype == REAL_TYPE) {
                return REAL_RET;
            }
        } else if (tree->node->type == ARRAY_EXP) {
            if (tree->node->array_exp->sym_ref->dtype->type != ARRAY_SYM) {
                panic("\nVariable, %s, is not declared as an array in this scope, line %d\n", tree->node->array_exp->sym_ref->sym, LINE_COUNT);
            }
            if (tree->node->array_exp->sym_ref->dtype->arr->stype == INTEGER_TYPE) {
                return INTEGER_RET;
            } else if (tree->node->array_exp->sym_ref->dtype->arr->stype == REAL_TYPE) {
                return REAL_RET;
            }
        }
    }
    return W_TYPE_ERROR;
}

exp_node_t *init_exp_node(exp_type type, void *val) {
    exp_node_t *tmp = (exp_node_t *) malloc(sizeof(exp_node_t));
    tmp->type = type;
    switch (type) {
        case OP_EXP:
            tmp->op = (op_type)val;
            break;
        case INTEGER_EXP:
            tmp->ival = *(int *)val;
            break;
        case REAL_EXP:
            tmp->fval = *(float *)val;
            break;
        case VAR_EXP:
            tmp->sym_ref = (sym_node_t *)val;
            break;
        case FUNC_EXP:
            tmp->func_exp = (func_exp_t *)val;
            break;
        case ARRAY_EXP:
            tmp->array_exp = (array_exp_t *)val;
            break;
    }
    return tmp;
}

exp_tree_t *init_exp_tree(exp_node_t *node) {
    exp_tree_t *tmp = (exp_tree_t *)malloc(sizeof(exp_tree_t));
    tmp->node = node;
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->is_paren = 0;
    return tmp;
}

exp_list_t *init_exp_list(exp_tree_t *exp) {
    exp_list_t *tmp = (exp_list_t *)malloc(sizeof(exp_list_t));
    tmp->next = NULL;
    tmp->exp = exp;
    return tmp;
}

func_exp_t *init_func_exp(sym_node_t *ref, exp_list_t *args) {
    func_exp_t *tmp = (func_exp_t *)malloc(sizeof(func_exp_t));
    tmp->sym_ref = ref;
    tmp->args = args;
    return tmp;
}

array_exp_t *init_array_exp(sym_node_t *ref, exp_tree_t *arg) {
    array_exp_t *tmp = (array_exp_t *)malloc(sizeof(array_exp_t));
    tmp->sym_ref = ref;
    tmp->arg = arg;
    return tmp;
}

void destroy_exp_node(exp_node_t *node) {
    if (!node) {
        return;
    }
    switch (node->type) {
        case FUNC_EXP:
            destroy_exp_list(node->func_exp->args);
            free(node->func_exp);
            break;
        case ARRAY_EXP:
            destroy_exp_tree(node->array_exp->arg);
            free(node->array_exp);
            break;
    }
    free(node);
}

void destroy_exp_list(exp_list_t *list) {
    if (!list) {
        return;
    }
    destroy_exp_list(list->next);
    destroy_exp_tree(list->exp);
    free(list); //PLS DONT SEGGY
}

void destroy_exp_tree(exp_tree_t *tree) {
    if (!tree) {
        return;
    }
    destroy_exp_tree(tree->right);
    destroy_exp_tree(tree->left);
    destroy_exp_node(tree->node);
    free(tree);
}

void destroy_func_exp(func_exp_t *exp) {
    destroy_exp_list(exp->args);
    free(exp);
}

void destroy_array_exp(array_exp_t *exp) {
    destroy_exp_tree(exp->arg);
    free(exp);
}