#define HASH_SIZE 211
#define EOS '\0'


typedef struct node_s {

    char *sym;
    struct node_s *next;
    int type;
    union {
        int ival;
        float fval;
    };

} node_t;

typedef struct table_s {

    node_t *table[HASH_SIZE];

} table_t;

typedef struct stack_s {

    table_t *scope;
    struct stack_s *next;

} stack_t;

stack_t *init_stack(table_t *);
stack_t *stack_pop(stack_t *);
stack_t *stack_push(stack_t *, table_t *);
node_t *search_stack(stack_t *, char *);

table_t *init_table();
node_t *table_put(table_t *, char *);
node_t *table_get(table_t *, char *);

node_t *init_node(char *);

int hashpjw(char *);

