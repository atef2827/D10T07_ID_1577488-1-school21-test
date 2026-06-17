#include <stdio.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

// Comparator callback shared with the insert quest.
int cmp_int(int a, int b) { return a - b; }

// applyf callback: print a node value to the terminal.
void print_item(int item) { printf("%d ", item); }

// Build a BST from `values` and print it using all three traversals.
int test_traverse(const int* values, int count) {
    t_btree* root = bstree_create_node(values[0]);
    if (root == NULL) {
        return FAIL;
    }
    for (int i = 1; i < count; i++) {
        bstree_insert(root, values[i], cmp_int);
    }

    printf("infix   (ascending) : ");
    bstree_apply_infix(root, print_item);
    printf("\n");

    printf("prefix  (stored)    : ");
    bstree_apply_prefix(root, print_item);
    printf("\n");

    printf("postfix (descending): ");
    bstree_apply_postfix(root, print_item);
    printf("\n");

    bstree_destroy(root);
    return SUCCESS;
}

int main() {
    int failed = 0;

    int set1[] = {5, 3, 8, 1, 4, 7, 9};
    int set2[] = {4, 2, 6, 1, 3, 5, 0};

    printf("--- set 1 ---\n");
    if (test_traverse(set1, (int)(sizeof(set1) / sizeof(set1[0]))) == SUCCESS) {
        printf("test_traverse(set1): SUCCESS\n");
    } else {
        printf("test_traverse(set1): FAIL\n");
        failed = 1;
    }

    printf("--- set 2 ---\n");
    if (test_traverse(set2, (int)(sizeof(set2) / sizeof(set2[0]))) == SUCCESS) {
        printf("test_traverse(set2): SUCCESS\n");
    } else {
        printf("test_traverse(set2): FAIL\n");
        failed = 1;
    }

    return failed;
}
