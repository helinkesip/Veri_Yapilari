#include <iostream>
#include <cstdlib> 
#include <cstdio>

void matris_olustur(int*** matris, int satir_sayisi, int sutun_sayisi) {
    *matris = (int**)malloc(sizeof(int*) * satir_sayisi);
    for (int i = 0; i < satir_sayisi; i++) {
        *(*matris + i) = (int*)malloc(sizeof(int) * sutun_sayisi);
        for (int j = 0; j < sutun_sayisi; j++) {
            *(*(*matris + i) + j) = rand() % 100;
        }
    }
}

void matris_yaz(int** matris, int satir_sayisi, int sutun_sayisi) {
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            printf("%d ", *(*(matris + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int** matris_topla(int** m1, int satir1, int sutun1, int** m2, int satir2, int sutun2) {
    if (satir1 != satir2 || sutun1 != sutun2) {
        printf("Satýr ve sütun uyuþmazlýðýndan dolayý toplanamaz.\n");
        return NULL;
    }
    int** m3;
    matris_olustur(&m3, satir1, sutun1);
    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun1; j++) {
            *(*(m3 + i) + j) = *(*(m1 + i) + j) + *(*(m2 + i) + j);
        }
    }
    return m3;
}

int** matris_carp(int** m1, int satir1, int sutun1, int** m2, int satir2, int sutun2) {
    if (sutun1 != satir2) {
        printf("Satýr ve sütun uyuþmazlýðýndan dolayý çarpýlamaz.\n");
        return NULL;
    }

    int** m3;
    matris_olustur(&m3, satir1, sutun2);

    for (int i = 0; i < satir1; i++) {
        for (int j = 0; j < sutun2; j++) {
            *(*(m3 + i) + j) = 0;
            for (int k = 0; k < sutun1; k++) {
                *(*(m3 + i) + j) += (*(*(m1 + i) + k)) * (*(*(m2 + k) + j));
            }
        }
    }

    return m3;
}

int main() {
    int** m1;
    int** m2;
    int** m3;
    int** m4;
    int satir1, sutun1, satir2, sutun2;

    printf("Satir sayisini giriniz: ");
    scanf("%d", &satir1);
    printf("Sütun sayisini giriniz: ");
    scanf("%d", &sutun1);
    printf("Satir2 sayisini giriniz: ");
    scanf("%d", &satir2);
    printf("Sutun2 sayisini giriniz: ");
    scanf("%d", &sutun2);

    matris_olustur(&m1, satir1, sutun1);
    matris_olustur(&m2, satir2, sutun2);

    printf("Matris 1:\n");
    matris_yaz(m1, satir1, sutun1);

    printf("Matris 2:\n");
    matris_yaz(m2, satir2, sutun2);

    m3 = matris_topla(m1, satir1, sutun1, m2, satir2, sutun2);
    if (m3 != NULL) {
        printf("Ýki Matrisin Toplamý:\n");
        matris_yaz(m3, satir1, sutun1);
    }

    m4 = matris_carp(m1, satir1, sutun1, m2, satir2, sutun2);
    if (m4 != NULL) {
        printf("Ýki Matrisin Çarpýmý:\n");
        matris_yaz(m4, satir1, sutun2);
    }

    return 0;
}
