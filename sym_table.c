#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_table.h"

extern long int LINE_COUNT;

sym_stack_t *init_sym_stack(sym_table_t *t, sym_node_t *ref, int depth) {
    sym_stack_t *s = (sym_stack_t *)malloc(sizeof(sym_stack_t));
    s->scope = t;
    s->next = NULL;
    s->sym_ref = ref;
    s->depth = depth;
    return s;
}

sym_stack_t *stack_pop(sym_stack_t **s) {
    sym_stack_t *tmp = (*s);
    (*s) = (*s)->next;
    tmp->next = NULL;
    return tmp;
}

sym_stack_t *stack_push(sym_stack_t *s, sym_table_t *t, sym_node_t *ref) {
    sym_stack_t *tmp = init_sym_stack(t, ref, s->depth+1);
    tmp->next = s;
    s = tmp;
    return s;
}

sym_node_t *search_stack(sym_stack_t *s, char *sym) {
    sym_stack_t *cur = s;
    sym_node_t *n = NULL;
    while ((n = table_get(cur->scope, sym)) == NULL) {
        if (cur->next == NULL) {
            break;
        }
        cur = cur->next;
    }
    return n;
}

sym_node_t *search_stack_func(sym_stack_t *s, char *sym) {
    sym_stack_t *cur = s;
    sym_node_t *n = NULL;
    while ((n = table_get(cur->scope, sym)) == NULL) {
        if (cur->next == NULL) {
            break;
        }
        if (cur->sym_ref->ntype == FUNC_NODE) {
            return NULL;
        }
        cur = cur->next;
    }
    return n;
}

sym_table_t *init_sym_table() {
    int i;
    sym_table_t *tmp = (sym_table_t*) malloc(sizeof(sym_table_t));
    tmp->offset = 0;
    for (i = 0; i < HASH_SIZE; i++) {
        tmp->table[i] = NULL;
    }
    return tmp;
}

sym_node_t *table_put(sym_table_t *t, sym_node_t *node) {
    int hash = hashpjw(node->sym);
    sym_node_t *cur = t->table[hash];
    if (cur != NULL) {
        if (node == cur) {
            return node;
        }
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
        cur = cur->next;
    } else {
        t->table[hash] = cur = node;
    }
    return cur;
}

sym_node_t *table_get(sym_table_t *t, char *sym) {
    int hash = hashpjw(sym);
    sym_node_t *cur = t->table[hash];
    if (!cur) {
        return NULL;
    }
    while (cur->next != NULL) {
        if (strcmp(cur->sym, sym) == 0) {
            break;
        }
        cur = cur->next;
    }
    return cur;
}

sym_node_t *init_sym_node(char *sym, node_type ntype, void *type, int offset) {
    sym_node_t *n = (sym_node_t*)malloc(sizeof(sym_node_t));
    n->next = NULL;
    n->sym = strdup(sym);
    n->offset = offset;
    n->ntype = ntype;
    switch (n->ntype) {
        case PRIM_NODE:
            n->dtype = (data_type_t *)type;
            break;
        case FUNC_NODE:
            n->ftype = (func_type_t *)type;
            break;
        case PROC_NODE:
            n->ptype = (proc_type_t *)type;
            break;
    }
    return n;
}

void destroy_sym_node(sym_node_t *node) {
    if (node == NULL) {
        return;
    }
    destroy_sym_node(node->next);
    free(node);
}

void destroy_sym_table(sym_table_t *table) {
    int i;
    if (table == NULL) {
        return;
    }
    for (i = 0; i < HASH_SIZE; i++) {
        if (table->table[i]) {
            destroy_sym_node(table->table[i]);
        }
    }
    free(table);
}

void destroy_sym_stack(sym_stack_t *stack) {
    if (stack == NULL) {
        return;
    }
    destroy_sym_table(stack->scope);
    free(stack);
}

/* ----------------------------------------------------------------------------- 
 * hashpjw
 * Peter J. Weinberger's hash function 
 * Source: Aho, Sethi, and Ullman, "Compilers", Addison-Wesley, 1986 (page 436).
 */
int hashpjw(char *s) {
	char *p; 
	unsigned h = 0, g; 
	
	for ( p = s; *p != EOS; p++ ) { 
		h = (h << 4) + (*p); 
		if ( g = h & 0xf0000000 ) { 
			h = h ^ ( g >> 24 ); 
			h = h ^ g; 
		} 
	} 
	return h % HASH_SIZE; 
}