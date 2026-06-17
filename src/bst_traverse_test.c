#include <stdio.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

// Comparator callback shared with the insert quest.
static int cmp_int(int a, int b) { return a - b; }

// applyf callback: print a single node value to the terminal.
static void print_item(int item) { printf("%d ", item); }

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

// Build a tree and print one labelled traversal through `applyf`.
static void show_traversal(const char* label, t_btree* root,
                           void (*traverse)(t_btree*, void (*)(int))) {
    printf("%s", label);
    traverse(root, print_item);
    printf("\n");
}

// Build a BST from `values` and print all three traversals.
static int test_traverse(const int* values, int count) {
    int result = FAIL;
    t_btree* root = bstree_create_node(values[0]);
    if (root != NULL) {
        for (int i = 1; i < count; i++) {
            bstree_insert(root, values[i], cmp_int);
        }
        show_traversal("infix   (ascending) : ", root, bstree_apply_infix);
        show_traversal("prefix  (stored)    : ", root, bstree_apply_prefix);
        show_traversal("postfix (descending): ", root, bstree_apply_postfix);
        bstree_destroy(root);
        result = SUCCESS;
    }
    return result;
}

int main(void) {
    int failed = 0;
    int set1[] = {5, 3, 8, 1, 4, 7, 9};
    int set2[] = {4, 2, 6, 1, 3, 5, 0};
    printf("--- set 1 ---\n");
    failed = failed | report("test_traverse(set1)", test_traverse(set1, 7));
    printf("--- set 2 ---\n");
    failed = failed | report("test_traverse(set2)", test_traverse(set2, 7));
    return failed;
}
