#include <stdio.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

// Comparator callback: natural ordering of two integers.
static int cmp_int(int a, int b) { return a - b; }

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

// Report whether `child` of `parent` carries `value` on the given side.
static int report_child(t_btree* parent, t_btree* child, int value, const char* side) {
    int matched = 0;
    if (child != NULL && child->item == value) {
        printf("value %d inserted as %s child of %d\n", value, side, parent->item);
        matched = 1;
    }
    return matched;
}

// Walk the tree to locate `value` and print its insertion place.
static int locate_value(t_btree* root, int value) {
    int found = 0;
    t_btree* cur = root;
    while (cur != NULL && found == 0) {
        int order = cmp_int(value, cur->item);
        if (order == 0) {
            found = 1;
        } else if (order < 0) {
            found = report_child(cur, cur->left, value, "left");
            cur = cur->left;
        } else {
            found = report_child(cur, cur->right, value, "right");
            cur = cur->right;
        }
    }
    return found;
}

// Build a tree from `values` and verify every value is reachable.
static int test_insert(const int* values, int count) {
    int result = FAIL;
    t_btree* root = bstree_create_node(values[0]);
    if (root != NULL) {
        int all_found = 1;
        for (int i = 1; i < count; i++) {
            bstree_insert(root, values[i], cmp_int);
        }
        for (int i = 1; i < count; i++) {
            all_found = all_found & locate_value(root, values[i]);
        }
        if (all_found == 1) {
            result = SUCCESS;
        }
        bstree_destroy(root);
    }
    return result;
}

int main(void) {
    int failed = 0;
    int set1[] = {5, 3, 8, 1, 4, 7, 9};
    int set2[] = {4, 2, 6, 1, 3, 5, 0};
    printf("--- set 1 ---\n");
    failed = failed | report("test_insert(set1)", test_insert(set1, 7));
    printf("--- set 2 ---\n");
    failed = failed | report("test_insert(set2)", test_insert(set2, 7));
    return failed;
}
