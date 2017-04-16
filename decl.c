#include <stdlib.h>

#include "decl.h"
#include "defs.h"

func_type_t *init_func_type(data_type_list_t *type_list, ret_type rtype) {
    func_type_t *tmp = (func_type_t *)malloc(sizeof(func_type_t));
    tmp->types = type_list;
    tmp->rtype = rtype;
    return tmp;
}

proc_type_t *init_proc_type(data_type_list_t *type_list) {
    proc_type_t *tmp = (proc_type_t *)malloc(sizeof(proc_type_t));
    tmp->types = type_list;
    return tmp;
}

data_array_t *init_data_array(int start, int end, simple_type stype) {
    data_array_t *tmp = (data_array_t *)malloc(sizeof(data_array_t));
    tmp->start = start;
    tmp->end = end;
    tmp->stype = stype;
    return tmp;
}

data_type_t *init_data_type(sym_type type, void *val) {
    data_type_t *tmp = (data_type_t *)malloc(sizeof(data_type_t));
    switch (type) {
        case SIMPLE_SYM: 
            tmp->stype = (simple_type)val;
            break;
        case ARRAY_SYM:
            tmp->arr = (data_array_t *)val;
            break;
    }
    return tmp;
}


id_list_t *init_id_list(char *id) {
    id_list_t *tmp = (id_list_t *)malloc(sizeof(id_list_t));
    tmp->id = id;
    return tmp;
}

data_type_list_t *init_data_type_list(data_type_t *type) {
    data_type_list_t *tmp = (data_type_list_t *)malloc(sizeof(data_type_list_t));
    tmp->type = type;
    return tmp;
}

void destroy_data_array(data_array_t *array) {
    free(array);
}

void destroy_data_type(data_type_t *dtype) {
    switch (dtype->type) {
        case SIMPLE_SYM: 
            break;
        case ARRAY_SYM:
            destroy_data_array(dtype->arr);
            break;
    }
    free(dtype);
}

void destroy_id_list(id_list_t *id_list) {
    if (!id_list) {
        return;
    }
    destroy_id_list(id_list->next);
    free(id_list->id);
    free(id_list);
}

void destroy_data_type_list(data_type_list_t *type_list) {
    if (!type_list) {
        return;
    }
    destroy_data_type_list(type_list->next);
    free(type_list->type);
    free(type_list);
}

void destroy_func_type(func_type_t *type) {
    destroy_data_type_list(type->types);
    free(type);
}

void destroy_proc_type(proc_type_t *type) {
    destroy_data_type_list(type->types);
    free(type);
}