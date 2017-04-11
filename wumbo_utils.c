#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "defs.h"
#include "wumbo_utils.h"

op_type str2optype(char *s) {
    if (!strcmp(s, "+")) {
        return ADD_OP;
    } else if (!strcmp(s, "-")) {
        return SUB_OP;
    } else if (!strcmp(s, "*")) {
        return MUL_OP;
    } else if (!strcmp(s, "/")) {
        return DIV_OP;
    } else if (!strcmp(s, "==")) {
        return EQ_OP;
    } else if (!strcmp(s, "<")) {
        return L_OP;
    } else if (!strcmp(s, ">")) {
        return G_OP;
    } else if (!strcmp(s, "<=")) {
        return LE_OP;
    } else if (!strcmp(s, ">=")) {
        return GE_OP;
    } else if (!strcmp(s, "<>")) {
        return NEQ_OP;
    } 
    return -1;
}

void wprintf(const char *s, ...) {
    va_list args;
    va_start(args, s);
    #ifndef DEBUG
        vfprintf(stderr, s, args);
    #endif
    va_end(args);
}

void print_spaces(int spaces) {
    int i;
    for (i = 0; i < spaces; i++) {
        fprintf(stderr, " ");
    }
}