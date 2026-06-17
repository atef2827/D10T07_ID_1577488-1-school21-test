#include <stdio.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

// Verify that bstree_create_node stores the value and initializes children to
// NULL.
int test_create_node(int item) {
    t_btree* node = bstree_create_node(item);
    if (node == NULL) {
        return FAIL;
    }

    int ok = SUCCESS;
    if (node->item != item || node->left != NULL || node->right != NULL) {
        ok = FAIL;
    } else {
        printf("created node: item = %d, left = %p, right = %p\n", node->item, (void*)node->left,
               (void*)node->right);
    }

    bstree_destroy(node);
    return ok;
}

int main() {
    int failed = 0;

    if (test_create_node(4) == SUCCESS) {
        printf("test_create_node(4): SUCCESS\n");
    } else {
        printf("test_create_node(4): FAIL\n");
        failed = 1;
    }

    if (test_create_node(-7) == SUCCESS) {
        printf("test_create_node(-7): SUCCESS\n");
    } else {
        printf("test_create_node(-7): FAIL\n");
        failed = 1;
    }

    return failed;
}
