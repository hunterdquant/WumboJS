#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sym_table.h"

stack_t *init_stack(table_t *t) {
    stack_t *s = (stack_t *)malloc(sizeof(stack_t));
    s->scope = t;
    return s;
}

stack_t *stack_pop(stack_t *s) {
    stack_t *tmp = s;
    s = s->next;
    return tmp;
}

stack_t *stack_push(stack_t *s, table_t *t) {
    stack_t *tmp = init_stack(t);
    tmp->next = s;
    s = tmp;
    return s;
}

node_t *search_stack(stack_t *s, char *sym) {
    stack_t *cur = s;
    node_t *n = NULL;
    while ((n = table_get(cur->scope, sym)) == NULL) {
        if (cur->next == NULL) {
            break;
        }
        cur = cur->next;
    }
    return n;
}


table_t *init_table() {
    return (table_t*)malloc(sizeof(table_t));
}

node_t *table_put(table_t *t, char *sym) {
    int hash = hashpjw(sym);
    node_t *cur = t->table[hash];
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

node_t *table_get(table_t *t, char *sym) {
    int hash = hashpjw(sym);
    node_t *cur = t->table[hash];
    while (cur != NULL) {
        if (strcmp(cur->sym, sym) == 1) {
            break;
        }
        cur = cur->next;
    }
    return cur;
}

node_t *init_node(char *sym) {
    node_t *n = (node_t*)malloc(sizeof(node_t));
    n->sym = sym;
    return n;
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