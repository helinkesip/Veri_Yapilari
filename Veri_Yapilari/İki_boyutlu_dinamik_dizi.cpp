#include <iostream>



int main() {
	int** ptr;
	int satir_sayisi, sutun_sayisi;



	printf("satir sayisini girin: ");
	scanf("%d", &satir_sayisi);
	printf("s�tun sayisini girin: ");
	scanf("%d", &sutun_sayisi);



	ptr = (int**)malloc(sizeof(int*) * satir_sayisi);

	for (int i = 0; i < satir_sayisi; i++) {
		*(ptr + i) = (int*)malloc(sizeof(int) * sutun_sayisi);

		for (int j = 0; j < sutun_sayisi; j++) {//s�tunlara *(p+i) ile yerle�iyoruz sonras�nda +j ile s�tununu i�indeki sat�rda geziniyoruz
			*(*(ptr + i) + j) = rand() % 100;
			printf("%d", *(*(ptr + i) + j));
			
		}

	}

}