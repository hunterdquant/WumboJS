#ifndef __SYM_TABLE__
#define __SYM_TABLE__

#include "defs.h"
#include "decl.h"
#define HASH_SIZE 211
#define EOS '\0'


typedef struct node_s {
    char *sym;
    struct node_s *next;
    node_type ntype;
    union {
        data_type_t *dtype;
        func_type_t *ftype;
        proc_type_t *ptype;
    };
    int offset;
} sym_node_t;

typedef struct table_s {
    long int offset;
    sym_node_t *table[HASH_SIZE];
} sym_table_t;

typedef struct stack_s {
    sym_table_t *scope;
    struct stack_s *next;
    sym_node_t *sym_ref;
    int depth;
} sym_stack_t;

sym_node_t *init_sym_node(char *, node_type, void *, int);
sym_stack_t *init_sym_stack(sym_table_t *, sym_node_t *, int);
sym_stack_t *stack_pop(sym_stack_t **);
sym_stack_t *stack_push(sym_stack_t *, sym_table_t *, sym_node_t *);
sym_node_t *search_stack(sym_stack_t *, char *);
sym_node_t *search_stack_func(sym_stack_t *, char *);

sym_table_t *init_sym_table();
sym_node_t *table_put(sym_table_t *, sym_node_t *);
sym_node_t *table_get(sym_table_t *, char *);

sym_node_t *init_node(char *);


void destroy_sym_node(sym_node_t *);

void destroy_sym_table(sym_table_t *);

void destroy_sym_stack(sym_stack_t *);

int hashpjw(char *);

#endif