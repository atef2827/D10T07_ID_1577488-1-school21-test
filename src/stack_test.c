#include <stdio.h>

#include "stack.h"

#define SUCCESS 0
#define FAIL 1

// Print one test result and return 1 when the test has failed.
static int report(const char* name, int status) {
    int failed = 1;
    if (status == SUCCESS) {
        failed = 0;
        printf("%s: SUCCESS\n", name);
    } else {
        printf("%s: FAIL\n", name);
    }
    return failed;
}

// push must grow the stack and keep values in LIFO order.
static int test_push(void) {
    int result = FAIL;
    struct stack* s = init();
    if (s != NULL) {
        if (push(s, 10) && push(s, 20) && push(s, 30) && s->size == 3 && s->top != NULL &&
            s->top->value == 30) {
            result = SUCCESS;
        }
        destroy(s);
    }
    return result;
}

// pop must return values in LIFO order and report an empty stack.
static int test_pop(void) {
    int result = FAIL;
    int v1 = 0, v2 = 0, v3 = 0;
    struct stack* s = init();
    if (s != NULL) {
        push(s, 1);
        push(s, 2);
        push(s, 3);
        if (pop(s, &v1) && v1 == 3 && pop(s, &v2) && v2 == 2 && pop(s, &v3) && v3 == 1 &&
            s->size == 0 && pop(s, &v1) == 0) {
            result = SUCCESS;
        }
        destroy(s);
    }
    return result;
}

int main(void) {
    int failed = 0;
    failed = failed | report("test_push", test_push());
    failed = failed | report("test_pop", test_pop());
    return failed;
}
