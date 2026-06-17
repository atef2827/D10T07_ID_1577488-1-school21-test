#include <stdio.h>

#include "list.h"

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

// add_door must insert a node right after the given element.
static int test_add_door(void) {
    struct door d0 = {0, DOOR_CLOSED};
    struct door d1 = {1, DOOR_OPEN};
    struct door d2 = {2, DOOR_CLOSED};
    int result = FAIL;
    struct node* root = init(d0);
    if (root != NULL) {
        struct node* second = add_door(root, d2);
        struct node* middle = add_door(root, d1);
        if (second != NULL && middle != NULL && root->next == middle && middle->next == second &&
            second->next == NULL && middle->door.id == 1 && middle->door.status == DOOR_OPEN &&
            second->door.id == 2) {
            result = SUCCESS;
        }
        destroy(root);
    }
    return result;
}

// remove_door must delete the requested node (middle and head cases).
static int test_remove_door(void) {
    struct door d0 = {0, DOOR_CLOSED};
    struct door d1 = {1, DOOR_CLOSED};
    struct door d2 = {2, DOOR_CLOSED};
    int result = FAIL;
    struct node* root = init(d0);
    if (root != NULL) {
        struct node* n1 = add_door(root, d1);
        struct node* n2 = add_door(n1, d2);
        if (n1 != NULL && n2 != NULL) {
            root = remove_door(n1, root);
            root = remove_door(root, root);
            if (find_door(1, root) == NULL && find_door(0, root) == NULL && root != NULL &&
                root->door.id == 2 && root->next == NULL) {
                result = SUCCESS;
            }
        }
        destroy(root);
    }
    return result;
}

int main(void) {
    int failed = 0;
    failed = failed | report("test_add_door", test_add_door());
    failed = failed | report("test_remove_door", test_remove_door());
    return failed;
}
