#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // INT_MIN için

// Kuyruk yapýsý
typedef struct {
    int on, arka, boyut;
    unsigned kapasite;
    int* dizi;
} Kuyruk;

// Kuyruk oluþturma fonksiyonu
Kuyruk* olustur(unsigned kapasite) {
    Kuyruk* q = (Kuyruk*)malloc(sizeof(Kuyruk));
    q->kapasite = kapasite;
    q->on = q->boyut = 0;
    q->arka = -1; // Kuyruk boþken arka -1 olarak baþlar
    q->dizi = (int*)malloc(q->kapasite * sizeof(int));
    return q;
}

// Kuyruk boþ mu kontrolü
int bosMu(Kuyruk* q) {
    return (q->boyut == 0);
}

// Kuyruk dolu mu kontrolü
int dolu(Kuyruk* q) {
    return (q->boyut == q->kapasite);
}

// Kuyruða eleman ekleme (enqueue)
void enqueue(Kuyruk* q, int eleman) {
    if (dolu(q)) {
        printf("Kuyruk dolu! Eleman eklenemedi: %d\n", eleman);
        return;
    }
    q->arka = (q->arka + 1) % q->kapasite; // Dairesel dizi mantýðý
    q->dizi[q->arka] = eleman;
    q->boyut++;
    printf("---> %d kuyruga eklendi\n", eleman);
}

// Kuyruktan eleman çýkarma (dequeue)
int dequeue(Kuyruk* q) {
    if (bosMu(q)) {
        printf("HATA: Kuyruk bos\n");
        return INT_MIN;
    }
    int silinen = q->dizi[q->on];
    q->on = (q->on + 1) % q->kapasite; // Dairesel dizi mantýðý
    q->boyut--;
    printf("<<--- %d kuyruktan silindi\n", silinen);
    return silinen;
}

// Kuyruðun önündeki elemaný görüntüleme
int front(Kuyruk* q) {
    if (bosMu(q)) {
        printf("Kuyruk boþ!\n");
        return -1;
    }
    return q->dizi[q->on];
}

// Kuyruðun arkasýndaki elemaný görüntüleme
int rear(Kuyruk* q) {
    if (bosMu(q)) {
        printf("Kuyruk boþ!\n");
        return -1;
    }
    return q->dizi[q->arka];
}

// Kuyruðu temizleme (belleði serbest býrakma)
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

    printf("Kuyruðun önündeki eleman: %d\n", front(kuyruk));
    printf("Kuyruðun arkasýndaki eleman: %d\n", rear(kuyruk));

    dequeue(kuyruk);
    dequeue(kuyruk);

    printf("Kuyruðun önündeki eleman: %d\n", front(kuyruk));
    printf("Kuyruðun arkasýndaki eleman: %d\n", rear(kuyruk));

    enqueue(kuyruk, 60); // Kuyrukta boþ alan var, eklenebilir

    temizle(kuyruk);
    return 0;
}