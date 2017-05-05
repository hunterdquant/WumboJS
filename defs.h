#ifndef __DEFS__
#define __DEFS__

typedef enum {COMPOUND_STMT, ASSIGNMENT_STMT, PROCEDURE_STMT, IF_STMT, WHILE_STMT, FOR_STMT} stmt_type;
typedef enum {OP_EXP, REAL_EXP, INTEGER_EXP, VAR_EXP, FUNC_EXP, ARRAY_EXP} exp_type;
typedef enum {ADD_OP, SUB_OP, MUL_OP, DIV_OP, EQ_OP, L_OP, G_OP, LE_OP, GE_OP, NEQ_OP, NOT_OP} op_type;
typedef enum {REAL_TYPE, INTEGER_TYPE} simple_type;
typedef enum {SIMPLE_SYM, ARRAY_SYM} sym_type;
typedef enum {PRIM_NODE, FUNC_NODE, PROC_NODE} node_type;
typedef enum {REAL_RET, INTEGER_RET, BOOL_RET} ret_type;

#define W_TYPE_ERROR -1
#define W_ALREADY_DEFINED_ERROR -2

#endif