typedef enum {COMPOUND_STMT, ASSIGNMENT_STMT, PROCEDURE_STMT, IF_STMT, WHILE_STMT, FOR_STMT} stmt_type;
typedef enum {OP_EXP, IVAL_EXP, RVAL_EXP} exp_type;
typedef enum {ADD_OP, SUB_OP, MUL_OP, DIV_OP, EQ_OP, L_OP, G_OP, LE_OP, GE_OP, NEQ_OP, LNEQ_OP} op_type;
typedef enum {REAL_SYM, INTEGER_SYM} sym_type;