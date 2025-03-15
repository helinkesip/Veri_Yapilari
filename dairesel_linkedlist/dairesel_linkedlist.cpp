//dairesel bağlı listelerde sonsuza kadar dolanma riski var, böyle olmamasını sağlayacak kontrol iter'in roota yani ilk düğüme eşit olması.

#include <iostream>
#include <stdlib.h>

typedef struct n {
    int data;
    n* next;
}node;

void bastir(node* r) {
    node* iter = r;
    printf("%d ", iter->data);
    iter = iter->next;
    while (iter != r) {
        printf("%d ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}
void sonaekle(node* r, int data) {
    node* iter = r;

    while (iter->next != r) {
        iter = iter->next;
    }
    iter->next = (node*)malloc(sizeof(node));
    iter->next->data = data;
    iter->next->next = r; //dairesel olduğu için ilk düğüme bağlayacağız eklenen elemanı

}
node* ekleSirali(node* r,int data) {
    if (r == NULL) { //linked list boşsa
        r = (node*)malloc(sizeof(node));
        r->next = r;
        r->data = data;
        return r;

    }
    if (r->data > data) {//ilk elemandan kücük durumu, root degisiyor
        node* temp = (node*)malloc(sizeof(node)); 
        temp->data = data;
        temp->next = r;
        node* iter = r;
        while (iter->next != r) {
            iter = iter->next;
        }
        iter->next = temp;
        return temp;

    }
    node* iter = r;
    while (iter->next != r && iter->next->data < data) {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->data = data;
    return r;

}

node* sil(node* r, int data) {
    if (r == NULL) {
        printf("Liste bos.\n");
        return NULL;
    }
    node* iter = r;
    node* temp;

    if (r->data == data) { // İlk elemanı silme durumu
        while (iter->next != r) { // Son elemana kadar git
            iter = iter->next;
        }
        if (r->next == r) { // Tek eleman varsa
            free(r);
            return NULL;
        }
        iter->next = r->next; // Yeni kök belirle
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }

    while (iter->next != r && iter->next->data != data) {
        iter = iter->next;
    }
    if (iter->next == r) {
        printf("Sayi bulunamadi.\n");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}


int main()
{
    node* root;
    root = NULL; //Atamak gerekiyor sistem kendisi null atamıyor

    root = ekleSirali(root, 400);
    root = ekleSirali(root, 32);
    root = ekleSirali(root, 10);
    root = ekleSirali(root, 543);
    root = ekleSirali(root, 2);
    bastir(root);
    root = sil(root, 10);
    bastir(root);
}


