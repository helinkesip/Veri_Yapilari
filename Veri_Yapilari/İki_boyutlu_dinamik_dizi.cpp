#include <iostream>



int main() {
	int** ptr;
	int satir_sayisi, sutun_sayisi;



	printf("satir sayisini girin: ");
	scanf("%d", &satir_sayisi);
	printf("sütun sayisini girin: ");
	scanf("%d", &sutun_sayisi);



	ptr = (int**)malloc(sizeof(int*) * satir_sayisi);

	for (int i = 0; i < satir_sayisi; i++) {
		*(ptr + i) = (int*)malloc(sizeof(int) * sutun_sayisi);

		for (int j = 0; j < sutun_sayisi; j++) {//sütunlara *(p+i) ile yerleþiyoruz sonrasýnda +j ile sütununu içindeki satýrda geziniyoruz
			*(*(ptr + i) + j) = rand() % 100;
			printf("%d", *(*(ptr + i) + j));
			
		}

	}

}