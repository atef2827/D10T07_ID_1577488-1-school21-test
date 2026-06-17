#include "list.h"

#include <stdlib.h>

struct node* init(struct door door) {
    struct node* root = malloc(sizeof(struct node));
    if (root == NULL) {
        return NULL;
    }
    root->door = door;
    root->next = NULL;
    return root;
}

struct node* add_door(struct node* elem, struct door door) {
    if (elem == NULL) {
        return NULL;
    }
    struct node* new_elem = malloc(sizeof(struct node));
    if (new_elem == NULL) {
        return NULL;
    }
    new_elem->door = door;
    new_elem->next = elem->next;
    elem->next = new_elem;
    return new_elem;
}

struct node* find_door(int door_id, struct node* root) {
    for (struct node* cur = root; cur != NULL; cur = cur->next) {
        if (cur->door.id == door_id) {
            return cur;
        }
    }
    return NULL;
}

struct node* remove_door(struct node* elem, struct node* root) {
    if (elem == NULL || root == NULL) {
        return root;
    }
    if (elem == root) {
        struct node* new_root = root->next;
        free(root);
        return new_root;
    }
    struct node* prev = root;
    while (prev->next != NULL && prev->next != elem) {
        prev = prev->next;
    }
    if (prev->next == elem) {
        prev->next = elem->next;
        free(elem);
    }
    return root;
}

void destroy(struct node* root) {
    while (root != NULL) {
        struct node* next = root->next;
        free(root);
        root = next;
    }
}
