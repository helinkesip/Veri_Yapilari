#include <iostream>
#include <stdlib.h>

typedef struct n {
    int data;
    n* next;
    n* prev;
} node;

// Listeyi yazdırma
void bastir(node* r) {
    if (r == NULL) {
        printf("Liste bos.\n");
        return;
    }
    node* iter = r;
    do {
        printf("%d ", iter->data);
        iter = iter->next;
    } while (iter != r);
    printf("\n");
}

// Listeyi tersine yazdırma
void tersBastir(node* r) {
    if (r == NULL) {
        printf("Liste bos.\n");
        return;
    }
    node* iter = r->prev; // Listenin sonundan başla
    do {
        printf("%d ", iter->data);
        iter = iter->prev;
    } while (iter != r->prev);
    printf("\n");
}

// Listeye sıralı ekleme
node* ekleSirali(node* r, int data) {
    node* temp = (node*)malloc(sizeof(node));
    if (temp == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return r;
    }
    temp->data = data;

    if (r == NULL) { // Liste boşsa
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }

    node* iter = r;
    if (r->data > data) { // İlk elemandan küçük durumu, root değişiyor
        while (iter->next != r) {
            iter = iter->next;
        }
        iter->next = temp;
        temp->prev = iter;
        temp->next = r;
        r->prev = temp;
        return temp;
    }

    while (iter->next != r && iter->next->data < data) {
        iter = iter->next;
    }

    temp->next = iter->next;
    temp->prev = iter;
    iter->next->prev = temp;
    iter->next = temp;
    return r;
}

// Listeden eleman silme
node* sil(node* r, int data) {
    if (r == NULL) {
        printf("Liste bos.\n");
        return NULL;
    }

    node* iter = r;
    node* temp;

    if (r->data == data) { // İlk elemanı silme durumu
        if (r->next == r) { // Tek eleman varsa
            free(r);
            return NULL;
        }
        while (iter->next != r) { // Son elemana kadar git
            iter = iter->next;
        }
        iter->next = r->next;
        r->next->prev = iter;
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
    iter->next = temp->next;
    temp->next->prev = iter;
    free(temp);
    return r;
}

// Belleği temizleme (tüm listeyi silme)
void listeyiTemizle(node* r) {
    if (r == NULL) {
        return;
    }
    node* iter = r;
    node* temp;
    do {
        temp = iter;
        iter = iter->next;
        free(temp);
    } while (iter != r);
    printf("Liste temizlendi.\n");
}

// Liste uzunluğunu bulma
int listeUzunlugu(node* r) {
    if (r == NULL) {
        return 0;
    }
    int uzunluk = 0;
    node* iter = r;
    do {
        uzunluk++;
        iter = iter->next;
    } while (iter != r);
    return uzunluk;
}

int main() {
    node* root = NULL;

    root = ekleSirali(root, 400);
    root = ekleSirali(root, 32);
    root = ekleSirali(root, 10);
    root = ekleSirali(root, 543);
    root = ekleSirali(root, 2);

    printf("Liste: ");
    bastir(root);

    printf("Liste uzunlugu: %d\n", listeUzunlugu(root));

    printf("Ters Liste: ");
    tersBastir(root);

    root = sil(root, 10);
    printf("10 silindikten sonra Liste: ");
    bastir(root);

    listeyiTemizle(root); // Belleği temizle
    root = NULL; // root'u NULL yap

    return 0;
}