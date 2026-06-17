#ifndef STACK_H
#define STACK_H

// A dynamic stack of integers implemented as a singly linked list of nodes.
struct stack_node {
    int value;
    struct stack_node* next;
};

struct stack {
    struct stack_node* top;
    int size;
};

// Create an empty stack.
struct stack* init(void);

// Push `value` onto the stack. Returns 1 on success, 0 on allocation failure.
int push(struct stack* s, int value);

// Pop the top value into `*value`. Returns 1 on success, 0 if the stack is
// empty or invalid.
int pop(struct stack* s, int* value);

// Free the stack and all of its nodes.
void destroy(struct stack* s);

#endif  // STACK_H
