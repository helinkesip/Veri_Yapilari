#include <stdio.h>

void selectionSort(int dizi[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;  // En küçük elemanın indeksini sakla

        for (int j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[minIndex]) {
                minIndex = j;  // Daha küçük eleman bulundu
            }
        }

        // Swap işlemi (Yer değiştir)
        if (minIndex != i) {
            int temp = dizi[i];
            dizi[i] = dizi[minIndex];
            dizi[minIndex] = temp;
        }
    }
}

void printArray(int dizi[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");
}

int main() {
    int dizi[] = { 39, 4, 23, 65, 78, 33, 64, 54, 0, 12 };
    int n = sizeof(dizi) / sizeof(dizi[0]);  // Dizi boyutunu hesapla

    printf("Sıralama öncesi: ");
    printArray(dizi, n);

    selectionSort(dizi, n);

    printf("Sıralama sonrası: ");
    printArray(dizi, n);

    return 0;
}
