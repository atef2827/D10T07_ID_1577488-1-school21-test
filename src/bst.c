#include "bst.h"

#include <stdlib.h>

t_btree* bstree_create_node(int item) {
    t_btree* node = malloc(sizeof(t_btree));
    if (node == NULL) {
        return NULL;
    }
    node->left = NULL;
    node->right = NULL;
    node->item = item;
    return node;
}

void bstree_insert(t_btree* root, int item, int (*cmpf)(int, int)) {
    if (root == NULL || cmpf == NULL) {
        return;
    }

    if (cmpf(item, root->item) <= 0) {
        if (root->left == NULL) {
            root->left = bstree_create_node(item);
        } else {
            bstree_insert(root->left, item, cmpf);
        }
    } else {
        if (root->right == NULL) {
            root->right = bstree_create_node(item);
        } else {
            bstree_insert(root->right, item, cmpf);
        }
    }
}

void bstree_apply_infix(t_btree* root, void (*applyf)(int)) {
    if (root == NULL || applyf == NULL) {
        return;
    }
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_prefix(t_btree* root, void (*applyf)(int)) {
    if (root == NULL || applyf == NULL) {
        return;
    }
    applyf(root->item);
    bstree_apply_prefix(root->left, applyf);
    bstree_apply_prefix(root->right, applyf);
}

void bstree_apply_postfix(t_btree* root, void (*applyf)(int)) {
    if (root == NULL || applyf == NULL) {
        return;
    }
    bstree_apply_postfix(root->left, applyf);
    bstree_apply_postfix(root->right, applyf);
    applyf(root->item);
}

void bstree_destroy(t_btree* root) {
    if (root == NULL) {
        return;
    }
    bstree_destroy(root->left);
    bstree_destroy(root->right);
    free(root);
}
