#include "stack.h"

#include <stdlib.h>

struct stack* init(void) {
    struct stack* s = malloc(sizeof(struct stack));
    if (s == NULL) {
        return NULL;
    }
    s->top = NULL;
    s->size = 0;
    return s;
}

int push(struct stack* s, int value) {
    if (s == NULL) {
        return 0;
    }
    struct stack_node* node = malloc(sizeof(struct stack_node));
    if (node == NULL) {
        return 0;
    }
    node->value = value;
    node->next = s->top;
    s->top = node;
    s->size++;
    return 1;
}

int pop(struct stack* s, int* value) {
    if (s == NULL || s->top == NULL) {
        return 0;
    }
    struct stack_node* node = s->top;
    if (value != NULL) {
        *value = node->value;
    }
    s->top = node->next;
    s->size--;
    free(node);
    return 1;
}

void destroy(struct stack* s) {
    if (s == NULL) {
        return;
    }
    struct stack_node* cur = s->top;
    while (cur != NULL) {
        struct stack_node* next = cur->next;
        free(cur);
        cur = next;
    }
    free(s);
}
