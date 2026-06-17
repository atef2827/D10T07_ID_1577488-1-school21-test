#ifndef LIST_H
#define LIST_H

#include "door_struct.h"

struct node {
    struct door door;
    struct node* next;
};

// Create a new singly linked list with a single element built from `door`.
struct node* init(struct door door);

// Insert a new `door` right after the node `elem`. Returns the new node.
struct node* add_door(struct node* elem, struct door door);

// Search the list (starting from `root`) for a door by its id.
struct node* find_door(int door_id, struct node* root);

// Remove `elem` from the list. Returns the (possibly new) list root.
struct node* remove_door(struct node* elem, struct node* root);

// Free the whole list.
void destroy(struct node* root);

#endif  // LIST_H
