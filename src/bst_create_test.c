#include <stdio.h>

#include "bst.h"

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

// bstree_create_node must store the value and initialize children to NULL.
static int test_create_node(int item) {
    int result = FAIL;
    t_btree* node = bstree_create_node(item);
    if (node != NULL) {
        if (node->item == item && node->left == NULL && node->right == NULL) {
            printf("created node: item = %d, left = %p, right = %p\n", node->item,
                   (void*)node->left, (void*)node->right);
            result = SUCCESS;
        }
        bstree_destroy(node);
    }
    return result;
}

int main(void) {
    int failed = 0;
    failed = failed | report("test_create_node(4)", test_create_node(4));
    failed = failed | report("test_create_node(-7)", test_create_node(-7));
    return failed;
}
