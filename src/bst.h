#ifndef BST_H
#define BST_H

typedef struct s_btree {
    struct s_btree* left;
    struct s_btree* right;
    int item;
} t_btree;

// Quest 6: create a single tree node that stores `item`.
t_btree* bstree_create_node(int item);

// Quest 7: insert `item` into the tree rooted at `root`, ordering the nodes
// with the `cmpf` comparator callback.
void bstree_insert(t_btree* root, int item, int (*cmpf)(int, int));

// Quest 8: traverse the tree and apply `applyf` to every node value.
void bstree_apply_infix(t_btree* root, void (*applyf)(int));
void bstree_apply_prefix(t_btree* root, void (*applyf)(int));
void bstree_apply_postfix(t_btree* root, void (*applyf)(int));

// Free the whole tree.
void bstree_destroy(t_btree* root);

#endif  // BST_H
