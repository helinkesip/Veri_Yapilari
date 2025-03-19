#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MIN i�in

// Kuyruk yap�s�
typedef struct {
    int on, arka, boyut;
    unsigned kapasite;
    int* dizi;
} Kuyruk;

// Kuyruk olu�turma fonksiyonu
Kuyruk* olustur(unsigned kapasite) {
    Kuyruk* q = (Kuyruk*)malloc(sizeof(Kuyruk));
    q->kapasite = kapasite;
    q->on = q->boyut = 0;
    q->arka = -1; // Kuyruk bo�ken arka -1 olarak ba�lar
    q->dizi = (int*)malloc(q->kapasite * sizeof(int));
    return q;
}

// Kuyruk bo� mu kontrol�
int bosMu(Kuyruk* q) {
    return (q->boyut == 0);
}

// Kuyruk dolu mu kontrol�
int dolu(Kuyruk* q) {
    return (q->boyut == q->kapasite);
}

// Kuyru�a eleman ekleme (enqueue)
void enqueue(Kuyruk* q, int eleman) {
    if (dolu(q)) {
        printf("Kuyruk dolu! Eleman eklenemedi: %d\n", eleman);
        return;
    }
    q->arka = (q->arka + 1) % q->kapasite; // Dairesel dizi mant���
    q->dizi[q->arka] = eleman;
    q->boyut++;
    printf("---> %d kuyruga eklendi\n", eleman);
}

// Kuyruktan eleman ��karma (dequeue)
int dequeue(Kuyruk* q) {
    if (bosMu(q)) {
        printf("HATA: Kuyruk bos\n");
        return INT_MIN;
    }
    int silinen = q->dizi[q->on];
    q->on = (q->on + 1) % q->kapasite; // Dairesel dizi mant���
    q->boyut--;
    printf("<<--- %d kuyruktan silindi\n", silinen);
    return silinen;
}

// Kuyru�un �n�ndeki eleman� g�r�nt�leme
int front(Kuyruk* q) {
    if (bosMu(q)) {
        printf("Kuyruk bo�!\n");
        return -1;
    }
    return q->dizi[q->on];
}

// Kuyru�un arkas�ndaki eleman� g�r�nt�leme
int rear(Kuyruk* q) {
    if (bosMu(q)) {
        printf("Kuyruk bo�!\n");
        return -1;
    }
    return q->dizi[q->arka];
}

// Kuyru�u temizleme (belle�i serbest b�rakma)
void temizle(Kuyruk* q) {
    free(q->dizi);
    free(q);
}

// Ana fonksiyon
int main() {
    Kuyruk* kuyruk = olustur(5);

    enqueue(kuyruk, 10);
    enqueue(kuyruk, 20);
    enqueue(kuyruk, 30);
    enqueue(kuyruk, 40);
    enqueue(kuyruk, 50);
    enqueue(kuyruk, 60); // Kuyruk dolu, eklenemez

    printf("Kuyru�un �n�ndeki eleman: %d\n", front(kuyruk));
    printf("Kuyru�un arkas�ndaki eleman: %d\n", rear(kuyruk));

    dequeue(kuyruk);
    dequeue(kuyruk);

    printf("Kuyru�un �n�ndeki eleman: %d\n", front(kuyruk));
    printf("Kuyru�un arkas�ndaki eleman: %d\n", rear(kuyruk));

    enqueue(kuyruk, 60); // Kuyrukta bo� alan var, eklenebilir

    temizle(kuyruk);
    return 0;
}