#include "list.h"

#include <stdlib.h>

struct node* init(struct door door) {
    struct node* root = malloc(sizeof(struct node));
    if (root != NULL) {
        root->door = door;
        root->next = NULL;
    }
    return root;
}

struct node* add_door(struct node* elem, struct door door) {
    struct node* new_elem = NULL;
    if (elem != NULL) {
        new_elem = malloc(sizeof(struct node));
        if (new_elem != NULL) {
            new_elem->door = door;
            new_elem->next = elem->next;
            elem->next = new_elem;
        }
    }
    return new_elem;
}

struct node* find_door(int door_id, struct node* root) {
    struct node* found = NULL;
    struct node* cur = root;
    while (cur != NULL && found == NULL) {
        if (cur->door.id == door_id) {
            found = cur;
        }
        cur = cur->next;
    }
    return found;
}

struct node* remove_door(struct node* elem, struct node* root) {
    struct node* new_root = root;
    if (elem != NULL && root != NULL) {
        if (elem == root) {
            new_root = root->next;
            free(root);
        } else {
            struct node* prev = root;
            while (prev->next != NULL && prev->next != elem) {
                prev = prev->next;
            }
            if (prev->next == elem) {
                prev->next = elem->next;
                free(elem);
            }
        }
    }
    return new_root;
}

void destroy(struct node* root) {
    struct node* cur = root;
    while (cur != NULL) {
        struct node* next = cur->next;
        free(cur);
        cur = next;
    }
}
