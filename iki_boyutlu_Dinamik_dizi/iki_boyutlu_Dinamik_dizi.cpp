/*#include <iostream>
#include <cstdlib> 
#include <ctime>   

void iki_boyutlu_matris_olusturma(int*** matris, int satir_sayisi, int sutun_sayisi);
void matris_yazdir(int** matris, int satir_sayisi, int sutun_sayisi);

int main() {

    

    int** ptr;
    int satir_sayisi, sutun_sayisi;

    printf("satir sayisini girin: ");
    scanf("%d", &satir_sayisi);
    printf("sutun sayisini girin: ");
    scanf("%d", &sutun_sayisi);

    ptr = (int**)malloc(sizeof(int*) * satir_sayisi);

    srand(time(NULL)); // Rastgele sayı üretecinin tohumunu ayarla

    for (int i = 0; i < satir_sayisi; i++) {
        *(ptr + i) = (int*)malloc(sizeof(int) * sutun_sayisi);

        for (int j = 0; j < sutun_sayisi; j++) {
            *(*(ptr + i) + j) = rand() % 100;
            printf("%d ", *(*(ptr + i) + j)); // Sayıları yazdır ve boşluk ekle
        }
        printf("\n"); // Satır sonu ekle
    }

    // Belleği serbest bırak
    for (int i = 0; i < satir_sayisi; i++) {
        free(*(ptr + i));
    }
    free(ptr);

    
    

int** matris;
int satir_sayisi, sutun_sayisi;

printf("satir sayisini girin: ");
scanf("%d", &satir_sayisi);

printf("sutun sayisini girin: ");
scanf("%d", &sutun_sayisi);




iki_boyutlu_matris_olusturma(&matris, satir_sayisi, sutun_sayisi);



return 0;
}



void matris_yazdir(int** matris, int satir_sayisi, int sutun_sayisi) {
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < sutun_sayisi; j++) {
            printf("%d ", *(*(matris + i) + j));
        }
        printf("\n");
    }
}




void iki_boyutlu_matris_olusturma(int*** matris, int satir_sayisi, int sutun_sayisi) {
    *matris = (int**)malloc(sizeof(int*) * satir_sayisi);

    for (int i = 0; i < satir_sayisi; i++) {

        *(*(matris + i)) = (int*)malloc(sizeof(int) * sutun_sayisi);

        for (int j = 0; j < sutun_sayisi; j++) {

            *(*(*matris + i) + j) = rand() % 100;
            printf("%d ", *(*(*matris + i) + j));
        }
    }


}

*/

