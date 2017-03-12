#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_table.h"

sym_stack_t *init_stack(sym_table_t *t) {
    sym_stack_t *s = (sym_stack_t *)malloc(sizeof(sym_stack_t));
    s->scope = t;
    return s;
}

sym_stack_t *stack_pop(sym_stack_t *s) {
    sym_stack_t *tmp = s;
    s = s->next;
    return tmp;
}

sym_stack_t *stack_push(sym_stack_t *s, sym_table_t *t) {
    sym_stack_t *tmp = init_stack(t);
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

sym_table_t *init_table() {
    return (sym_table_t*)malloc(sizeof(sym_table_t));
}

sym_node_t *table_put(sym_table_t *t, char *sym) {
    int hash = hashpjw(sym);
    sym_node_t *cur = t->table[hash];
    if (cur != NULL) {
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur = init_node(sym);
    } else {
        t->table[hash] = cur = init_node(sym);
    }
    return cur;
}

sym_node_t *table_get(sym_table_t *t, char *sym) {
    int hash = hashpjw(sym);
    sym_node_t *cur = t->table[hash];
    while (cur != NULL) {
        if (strcmp(cur->sym, sym) == 1) {
            break;
        }
        cur = cur->next;
    }
    return cur;
}

sym_node_t *init_node(char *sym) {
    sym_node_t *n = (sym_node_t*)malloc(sizeof(sym_node_t));
    n->sym = sym;
    return n;
}

void free_node(sym_node_t *node) {
    if (node == NULL) {
        return;
    }
    free_node(node->next);
    free(node);
}

void free_table(sym_table_t *table) {
    int i;
    if (table == NULL) {
        return;
    }
    for (i = 0; i < HASH_SIZE; i++) {
        if (table->table[i]) {
            free_node(table->table[i]->next);
        }
    }
    free(table);
}

void free_stack(sym_stack_t *stack) {
    if (stack == NULL) {
        return;
    }
    free_table(stack->scope);
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