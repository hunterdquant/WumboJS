#ifndef __DECL__
#define __DECL__

#include "defs.h"

typedef struct data_array_s {
    int start;
    int end;
    simple_type stype;
} data_array_t;

typedef struct data_type_s {
    sym_type type;
    union {
        simple_type stype;
        data_array_t *arr;
    };
} data_type_t;

typedef struct id_list_s {
    char *id;
    struct id_list_s *next;
} id_list_t;

typedef struct data_type_list_s {
    data_type_t *type;
    struct data_type_list_s *next;
} data_type_list_t;


typedef struct func_type_t {
    data_type_list_t *types;
    ret_type rtype;
} func_type_t;

typedef struct proc_type_t {
    data_type_list_t *types;
} proc_type_t;

data_type_t *init_data_type(sym_type, void *);
data_type_list_t *init_data_type_list(data_type_t *);
id_list_t *init_id_list(char *);
data_array_t *init_data_array(int, int, simple_type);
func_type_t *init_func_type(data_type_list_t *, ret_type);
proc_type_t *init_proc_type(data_type_list_t *);

void destroy_data_type_list(data_type_list_t *);
void destroy_data_type(data_type_t *);
void destroy_id_list(id_list_t *);
void destroy_data_array(data_array_t *);
void destroy_func_type(func_type_t *);
void destroy_proc_type(proc_type_t *);
#endif