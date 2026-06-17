#include <stdio.h>

#include "list.h"

#define SUCCESS 0
#define FAIL 1

// Verify that add_door inserts a node right after the given element and keeps
// the rest of the list intact.
int test_add_door() {
    struct door d0 = {0, DOOR_CLOSED};
    struct door d1 = {1, DOOR_OPEN};
    struct door d2 = {2, DOOR_CLOSED};

    struct node* root = init(d0);
    if (root == NULL) {
        return FAIL;
    }

    struct node* second = add_door(root, d2);
    struct node* middle = add_door(root, d1);

    int ok = SUCCESS;
    if (second == NULL || middle == NULL) {
        ok = FAIL;
    } else if (root->next != middle || middle->next != second || second->next != NULL) {
        ok = FAIL;
    } else if (middle->door.id != 1 || middle->door.status != DOOR_OPEN) {
        ok = FAIL;
    } else if (second->door.id != 2) {
        ok = FAIL;
    }

    destroy(root);
    return ok;
}

// Verify that remove_door deletes the requested node (head, middle and tail).
int test_remove_door() {
    struct door d0 = {0, DOOR_CLOSED};
    struct door d1 = {1, DOOR_CLOSED};
    struct door d2 = {2, DOOR_CLOSED};

    struct node* root = init(d0);
    if (root == NULL) {
        return FAIL;
    }
    struct node* n1 = add_door(root, d1);
    struct node* n2 = add_door(n1, d2);
    if (n1 == NULL || n2 == NULL) {
        destroy(root);
        return FAIL;
    }

    // Remove the middle node.
    root = remove_door(n1, root);
    if (find_door(1, root) != NULL) {
        destroy(root);
        return FAIL;
    }

    // Remove the head.
    root = remove_door(root, root);
    if (find_door(0, root) != NULL) {
        destroy(root);
        return FAIL;
    }

    // Only the door with id 2 must remain.
    if (root == NULL || root->door.id != 2 || root->next != NULL) {
        destroy(root);
        return FAIL;
    }

    destroy(root);
    return SUCCESS;
}

int main() {
    int failed = 0;

    if (test_add_door() == SUCCESS) {
        printf("test_add_door: SUCCESS\n");
    } else {
        printf("test_add_door: FAIL\n");
        failed = 1;
    }

    if (test_remove_door() == SUCCESS) {
        printf("test_remove_door: SUCCESS\n");
    } else {
        printf("test_remove_door: FAIL\n");
        failed = 1;
    }

    return failed;
}
