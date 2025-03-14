#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} node;

void write_linkedlist(struct Node* n) {
    while (n != NULL) {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n-----------------------------------------------\n");
}

struct Node* create_linkedlist(int data) {
    node* n = (node*)malloc(sizeof(node));
    if (!n) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    n->data = data;
    n->next = NULL;
    return n;
}

void add_node_head_linkedlist(struct Node** linkedlist, int data) {
    node* new_linkedlist = create_linkedlist(data);
    if (!new_linkedlist) return;
    new_linkedlist->next = *linkedlist;
    *linkedlist = new_linkedlist;
}

void add_node_end_of_linkedlist(struct Node** linkedlist, int data) {
    if (*linkedlist == NULL) {
        *linkedlist = create_linkedlist(data);
        return;
    }

    node* temp = *linkedlist;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = create_linkedlist(data);
}

void delete_node_from_linkedlist(struct Node** linkedlist, int data) {
    if (*linkedlist == NULL) {
        printf("Linked list is empty.\n");
        return;
    }

    node* temp = *linkedlist;
    node* prev = NULL;

    if (temp->data == data) {
        *linkedlist = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Data is not found.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

int main() {
    node* root = create_linkedlist(5);
    add_node_head_linkedlist(&root, 4);
    add_node_head_linkedlist(&root, 3);
    add_node_end_of_linkedlist(&root, 6);
    add_node_head_linkedlist(&root, 2);
    add_node_head_linkedlist(&root, 1);
    write_linkedlist(root);

    delete_node_from_linkedlist(&root, 3);
    write_linkedlist(root);

    return 0;
}
