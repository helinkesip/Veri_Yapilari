#include <iostream>
#include <cstdlib> 
#include <cstdio>

void matris_olustur(int*** matris, int satir_sayisi, int sutun_sayisi) {

	int i, j;

	*matris = (int**)malloc(sizeof(int*) * satir_sayisi);

	for (i = 0; i < satir_sayisi; i++) {

		*(*(matris + i)) = (int*)malloc(sizeof(int) * sutun_sayisi);

		for (j = 0; j < sutun_sayisi; j++) {
			*(*(*matris + i) + j) = rand() % 100;
		}
	}


}

void matris_yaz(int** matris, int satir_sayisi, int sutun_sayisi) {

	int i, j;

	for (i = 0; i < satir_sayisi; i++) {

		for (j = 0; j < sutun_sayisi; j++) {

			printf("%d", *(*(matris + i)) + j);
			if (j == sutun_sayisi - 1) {

				printf("\n");
			}
		}

		if (i == satir_sayisi - 1) {
			printf("\n");
		}

	}


}



int main() {

	int** m1;
	int** m2;

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

	matris_yaz(m1, satir1, sutun1);
	matris_yaz(m2, satir2, sutun2);




	return 0;

}
#include <iostream>
#include <cstdlib> 
#include <cstdio>

void matris_olustur(int*** matris, int satir_sayisi, int sutun_sayisi) {

	int i, j;

	*matris = (int**)malloc(sizeof(int*) * satir_sayisi);

	for (i = 0; i < satir_sayisi; i++) {

		*(*(matris + i)) = (int*)malloc(sizeof(int) * sutun_sayisi);

		for (j = 0; j < sutun_sayisi; j++) {
			*(*(*matris + i) + j) = rand() % 100;
		}
	}


}

void matris_yaz(int** matris, int satir_sayisi, int sutun_sayisi) {

	int i, j;

	for (i = 0; i < satir_sayisi; i++) {

		for (j = 0; j < sutun_sayisi; j++) {

			printf("%d", *(*(matris + i)) + j);
			if (j == sutun_sayisi - 1) {

				printf("\n");
			}
		}

		if (i == satir_sayisi - 1) {
			printf("\n");
		}

	}


}



int main() {

	int** m1;
	int** m2;

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

	matris_yaz(m1, satir1, sutun1);
	matris_yaz(m2, satir2, sutun2);




	return 0;

}
