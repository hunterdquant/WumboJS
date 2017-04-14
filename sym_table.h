#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include "defs.h"
#define HASH_SIZE 211
#define EOS '\0'

typedef struct array_type_s {
    int start;
    int end;
    sym_type type;
} array_type_t;

typedef struct node_s {

    char *sym;
    struct node_s *next;
    sym_type sym_type;
    union {
        array_type_t *array;
        simple_type type;
    };
    int offset;
} sym_node_t;

typedef struct table_s {

    sym_node_t *table[HASH_SIZE];
} sym_table_t;

typedef struct stack_s {

    sym_table_t *scope;
    struct stack_s *next;

} sym_stack_t;

sym_stack_t *init_stack(sym_table_t *);
sym_stack_t *stack_pop(sym_stack_t *);
sym_stack_t *stack_push(sym_stack_t *, sym_table_t *);
sym_node_t *search_stack(sym_stack_t *, char *);

sym_table_t *init_table();
sym_node_t *table_put(sym_table_t *, char *);
sym_node_t *table_get(sym_table_t *, char *);

sym_node_t *init_node(char *);

int hashpjw(char *);

#endif