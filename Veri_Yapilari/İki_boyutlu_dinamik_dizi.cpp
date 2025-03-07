#include <iostream>

int main() {
	int** ptr;
	int satir_sayisi;

	printf("satir sayisini girin: ");
	scanf("%d", &satir_sayisi);



	ptr = (int**)malloc(sizeof(int*) * satir_sayisi);

}