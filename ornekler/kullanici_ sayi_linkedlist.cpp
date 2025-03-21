#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    char ad[20];
    char soyad[30];
    int maas;
    Node* dizi;
    struct Node* next;
} node;

node* ekle(node* r, int data) {
    if (r == NULL) { // Liste boþsa
        r = (node*)malloc(sizeof(node));
        r->data = data;
        r->next = NULL;
        return r;
    }
    else {
        if (r->data > data) { // Listenin baþýna ekleme
            node* yeniDugum = (node*)malloc(sizeof(node));
            yeniDugum->data = data;
            yeniDugum->next = r;
            return yeniDugum;
        }
        else { // Listenin ortasýna veya sonuna ekleme
            node* iter = r;
            while (iter->next != NULL && iter->next->data < data) {
                iter = iter->next;
            }
            node* yeniDugum = (node*)malloc(sizeof(node));
            yeniDugum->data = data;
            yeniDugum->next = iter->next;
            iter->next = yeniDugum;
            return r;
        }
    }
}






void yazdir(node* r) {
    while (r != NULL) {
        printf("%d ", r->data);
        r = r->next;
    }
    printf("\n");
}

int main() {
    node* root = NULL;
    root = ekle(root, 12);
    root = ekle(root, 5);
    root = ekle(root, 20);
    root = ekle(root, 15);

    yazdir(root);

    // Belleði temizle
    while (root != NULL) {
        node* temp = root;
        root = root->next;
        free(temp);
    }

    return 0;
}