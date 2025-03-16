#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct n {
    int ogrno;
    char ad[50];
    int yas;
    struct n* next;
} node;

node* root = NULL;

// Listeyi yazdırma
void bastir(node* r) {
    if (r == NULL) {
        printf("Liste bos.\n");
        return;
    }
    while (r != NULL) {
        printf("Ogrenci No: %d, Ad: %s, Yas: %d\n", r->ogrno, r->ad, r->yas);
        r = r->next;
    }
    printf("\n");
}

// Listeye eleman ekleme
node* ekle(node* r, char ad[], int ogrno, int yas) {
    node* yeni = (node*)malloc(sizeof(node));
    if (yeni == NULL) {
        printf("Bellek tahsisi basarisiz.\n");
        return r;
    }

    strcpy(yeni->ad, ad);
    yeni->ogrno = ogrno;
    yeni->yas = yas;
    yeni->next = NULL;

    if (r == NULL) { // Liste boşsa
        return yeni;
    }

    if (r->ogrno > ogrno) { // İlk elemandan küçükse, başa ekle
        yeni->next = r;
        return yeni;
    }

    node* iter = r;
    while (iter->next != NULL && iter->next->ogrno < ogrno) {
        iter = iter->next;
    }

    yeni->next = iter->next;
    iter->next = yeni;
    return r;
}

// Listeden eleman silme
node* sil(node* r, int ogrno) {
    if (r == NULL) {
        printf("Liste bos.\n");
        return NULL;
    }

    node* temp;
    node* iter = r;

    if (r->ogrno == ogrno) { // İlk elemanı silme durumu
        temp = r;
        r = r->next;
        free(temp);
        return r;
    }

    while (iter->next != NULL && iter->next->ogrno != ogrno) {
        iter = iter->next;
    }

    if (iter->next == NULL) {
        printf("Ogrenci numarasi bulunamadi.\n");
        return r;
    }

    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    return r;
}

// Listede arama yapma
void arama(node* r, int ogrno) {
    while (r != NULL) {
        if (r->ogrno == ogrno) {
            printf("Aranan ogrenci bulundu: Ad: %s, Yas: %d\n", r->ad, r->yas);
            return;
        }
        r = r->next;
    }
    printf("Aranan ogrenci bulunamadi.\n");
}

// Listeyi güncelleme
void guncelle(node* r, int ogrno, char yeniAd[], int yeniYas) {
    while (r != NULL) {
        if (r->ogrno == ogrno) {
            strcpy(r->ad, yeniAd);
            r->yas = yeniYas;
            printf("Ogrenci bilgileri guncellendi.\n");
            return;
        }
        r = r->next;
    }
    printf("Guncellenecek ogrenci bulunamadi.\n");
}

// Menüyü göster
void menu() {
    printf("\n--- MENU ---\n");
    printf("1. Liste Olustur\n");
    printf("2. Ekle\n");
    printf("3. Sil\n");
    printf("4. Ara\n");
    printf("5. Guncelle\n");
    printf("6. Listele\n");
    printf("7. Cikis\n");
    printf("Seciminiz: ");
}

int main() {
    int secim, ogrno, yas;
    char ad[50];

    while (1) {
        menu();
        scanf("%d", &secim);

        switch (secim) {
        case 1: // Liste Olustur
            printf("Kac ogrenci eklemek istiyorsunuz? ");
            int sayi;
            scanf("%d", &sayi);
            for (int i = 0; i < sayi; i++) {
                printf("%d. Ogrenci No: ", i + 1);
                scanf("%d", &ogrno);
                printf("%d. Ogrenci Adi: ", i + 1);
                scanf("%s", ad);
                printf("%d. Ogrenci Yasi: ", i + 1);
                scanf("%d", &yas);
                root = ekle(root, ad, ogrno, yas);
            }
            break;

        case 2: // Ekle
            printf("Ogrenci No: ");
            scanf("%d", &ogrno);
            printf("Ogrenci Adi: ");
            scanf("%s", ad);
            printf("Ogrenci Yasi: ");
            scanf("%d", &yas);
            root = ekle(root, ad, ogrno, yas);
            break;

        case 3: // Sil
            printf("Silinecek Ogrenci No: ");
            scanf("%d", &ogrno);
            root = sil(root, ogrno);
            break;

        case 4: // Ara
            printf("Aranacak Ogrenci No: ");
            scanf("%d", &ogrno);
            arama(root, ogrno);
            break;

        case 5: // Guncelle
            printf("Guncellenecek Ogrenci No: ");
            scanf("%d", &ogrno);
            printf("Yeni Ad: ");
            scanf("%s", ad);
            printf("Yeni Yas: ");
            scanf("%d", &yas);
            guncelle(root, ogrno, ad, yas);
            break;

        case 6: // Listele
            bastir(root);
            break;

        case 7: // Cikis
            printf("Program sonlandiriliyor...\n");
            exit(0);

        default:
            printf("Gecersiz secim! Tekrar deneyin.\n");
        }
    }

    return 0;
}