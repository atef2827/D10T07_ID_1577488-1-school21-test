#include <stdio.h>

#include "bst.h"

#define SUCCESS 0
#define FAIL 1

// Comparator callback: returns the natural ordering of two integers.
int cmp_int(int a, int b) { return a - b; }

// Build a tree from `values` and verify that every value can be located at the
// branch dictated by the BST ordering.
int test_insert(const int* values, int count) {
    t_btree* root = bstree_create_node(values[0]);
    if (root == NULL) {
        return FAIL;
    }

    for (int i = 1; i < count; i++) {
        bstree_insert(root, values[i], cmp_int);
    }

    int ok = SUCCESS;
    for (int i = 1; i < count && ok == SUCCESS; i++) {
        t_btree* cur = root;
        int placed = 0;
        while (cur != NULL) {
            if (values[i] == cur->item && cur != root) {
                placed = 1;
                printf("value %d inserted under parent (item %d)\n", values[i], cur->item);
                break;
            }
            if (cmp_int(values[i], cur->item) <= 0) {
                if (cur->left != NULL && cur->left->item == values[i]) {
                    printf("value %d inserted to the left of %d\n", values[i], cur->item);
                    placed = 1;
                    break;
                }
                cur = cur->left;
            } else {
                if (cur->right != NULL && cur->right->item == values[i]) {
                    printf("value %d inserted to the right of %d\n", values[i], cur->item);
                    placed = 1;
                    break;
                }
                cur = cur->right;
            }
        }
        if (!placed) {
            ok = FAIL;
        }
    }

    bstree_destroy(root);
    return ok;
}

int main() {
    int failed = 0;

    int set1[] = {5, 3, 8, 1, 4, 7, 9};
    int set2[] = {4, 2, 6, 1, 3, 5, 0};

    printf("--- set 1 ---\n");
    if (test_insert(set1, (int)(sizeof(set1) / sizeof(set1[0]))) == SUCCESS) {
        printf("test_insert(set1): SUCCESS\n");
    } else {
        printf("test_insert(set1): FAIL\n");
        failed = 1;
    }

    printf("--- set 2 ---\n");
    if (test_insert(set2, (int)(sizeof(set2) / sizeof(set2[0]))) == SUCCESS) {
        printf("test_insert(set2): SUCCESS\n");
    } else {
        printf("test_insert(set2): FAIL\n");
        failed = 1;
    }

    return failed;
}
