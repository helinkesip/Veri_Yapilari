#include <stdio.h>
#include <stdlib.h>

#define N 100

// Yığın yapısı
typedef struct stack {
    int veri[N]; // Yığın elemanlarını saklamak için dizi
    int top;     // Yığının en üst indeksi
} yigin;

// Fonksiyon bildirimleri
void olustur(yigin* s);
void ekle(yigin* s, int oge);
int al(yigin* s);
int bosMu(yigin* s); // bosMu fonksiyon bildirimi
int doluMu(yigin* s); // doluMu fonksiyon bildirimi
int top(yigin* s);

// Yığın oluşturma fonksiyonu
void olustur(yigin* s) {
    s->top = -1; // Yığın boşken top -1 olur
}

// Yığına eleman ekleme fonksiyonu
void ekle(yigin* s, int oge) {
    if (doluMu(s)) {
        printf("Stack'e daha fazla eleman eklenemez, dolu!\n");
        return;
    }
    s->top++;
    s->veri[s->top] = oge;
    printf("---> %d yigina eklendi\n", oge);
}

// Yığından eleman çıkarma fonksiyonu
int al(yigin* s) {
    if (bosMu(s)) {
        printf("Yigin bos! Eleman cikarilamadi.\n");
        return -1;
    }
    int silinen = s->veri[s->top];
    s->top--;
    printf("<<--- %d yigindan silindi\n", silinen);
    return silinen;
}

// Yığın boş mu kontrolü
int bosMu(yigin* s) {
    return (s->top == -1);
}

// Yığın dolu mu kontrolü
int doluMu(yigin* s) {
    return (s->top == N - 1);
}

// Yığının en üstündeki elemanı görüntüleme
int top(yigin* s) {
    if (bosMu(s)) {
        printf("Yigin bos!\n");
        return -1;
    }
    return s->veri[s->top];
}

// Ana fonksiyon
int main() {
    yigin S;
    olustur(&S);

    ekle(&S, 10);
    ekle(&S, 20);
    ekle(&S, 30);
    ekle(&S, 40);
    ekle(&S, 50);

    printf("Yiginin en ustundeki eleman: %d\n", top(&S));

    al(&S);
    al(&S);

    printf("Yiginin en ustundeki eleman: %d\n", top(&S));

    ekle(&S, 60);

    return 0;
}