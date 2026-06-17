#include <stdio.h>

#include "stack.h"

#define SUCCESS 0
#define FAIL 1

// Verify that push grows the stack and stores values in LIFO order.
int test_push() {
    struct stack* s = init();
    if (s == NULL) {
        return FAIL;
    }

    int ok = SUCCESS;
    if (!push(s, 10) || !push(s, 20) || !push(s, 30)) {
        ok = FAIL;
    } else if (s->size != 3) {
        ok = FAIL;
    } else if (s->top == NULL || s->top->value != 30) {
        ok = FAIL;
    }

    destroy(s);
    return ok;
}

// Verify that pop returns values in LIFO order and reports an empty stack.
int test_pop() {
    struct stack* s = init();
    if (s == NULL) {
        return FAIL;
    }

    push(s, 1);
    push(s, 2);
    push(s, 3);

    int value = 0;
    int ok = SUCCESS;
    if (!pop(s, &value) || value != 3) {
        ok = FAIL;
    } else if (!pop(s, &value) || value != 2) {
        ok = FAIL;
    } else if (!pop(s, &value) || value != 1) {
        ok = FAIL;
    } else if (s->size != 0) {
        ok = FAIL;
    } else if (pop(s, &value) != 0) {
        // Popping from an empty stack must fail.
        ok = FAIL;
    }

    destroy(s);
    return ok;
}

int main() {
    int failed = 0;

    if (test_push() == SUCCESS) {
        printf("test_push: SUCCESS\n");
    } else {
        printf("test_push: FAIL\n");
        failed = 1;
    }

    if (test_pop() == SUCCESS) {
        printf("test_pop: SUCCESS\n");
    } else {
        printf("test_pop: FAIL\n");
        failed = 1;
    }

    return failed;
}
