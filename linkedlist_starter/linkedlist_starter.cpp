
#include <stdio.h>
#include <stdlib.h>

typedef struct n {
	int data;
	struct n* next; //bir sonraki değeri işaret eden pointer

}node;

void bastir(node* r) {
	while (r != NULL) {
		printf("%d ", r->data);
		r = r->next;
	}
	printf("\n");

}


void sonaekle(node* r, int data) {
	while (r->next != NULL) {
		r = r->next;
	}
	r->next = (node*)malloc(sizeof(node));
	r->next->data = data;
	r->next->next = NULL;
}


node* ekleSirali(node* r, int data)
{
	if (r == NULL) { //linkedlist boşsa
		r = (node*)malloc(sizeof(node));
		r->next = NULL;
		r->data = data;
		return r;
	}
	if (r->data > data) { //ilk elemandan küçük durumu **root değişiyor
		node* temp = (node*)malloc(sizeof(node));
		temp->data = data;
		temp->next = r; /*root değeri değişecek yeni değeri döndürmemiz ve anakoddaki root değerini değiştirmemiz gerekir
							gerekeceği için fonksiyonumuz void olmadı.*/
		return temp;

	}

	node* iter = r; 
	while (iter->next != NULL && iter->next->data < data) {
		iter= iter->next;
	}
	node* temp = (node*)malloc(sizeof(node));
	temp->next = iter->next;
	iter->next = temp;
	temp->data = data;
	return r;

}

node* sil(node* r, int data) { //baştaki eleman silinebilir yani root değişebilir o yüzden fonksiyon void dönmeli ki yeni root değerini main
						//fonksiyonumuzda döndürebilirim.
	node* temp;
	node* iter  = r;

	if (r->data == data) {
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}

	while (iter->next != NULL && iter->next->data != data) {
		iter = iter->next;
	}
	if (iter->next == NULL) {
		printf("Aranan eleman bulunamadı.");
		return r;
	}
	temp = iter->next;
	iter->next = iter->next->next;
	free(temp);
	return r;


}




int main() {
	
	node* root;
	root = NULL; //Atamak gerekiyor sistem kendisi null atamıyor

	root = ekleSirali(root, 400);
	root = ekleSirali(root, 32);
	root = ekleSirali(root, 10);
	root = ekleSirali(root, 543);
	root = ekleSirali(root, 2);
	bastir(root);
	root = sil(root, 10);
	bastir(root);
	}

















































/*
root->data = 10; //ilk değer
root->next = (node*)malloc(sizeof(node));
root->next->data = 20; //bir sonraki düğümün datasına 20 değeri
root->next->next = (node*)malloc(sizeof(node));
root->next->next->data = 30;
root->next->next->next = NULL; //son düğüm null ı göstersin

node* iter; //düğümdeki elemanları gezmemize yarayacak bir pointer
iter = root; //ilk düğüme eşitledik
printf("%d ", iter->data);
iter = iter->next;
printf("%d \n", iter->data);
iter = root;



int i = 0;
while (iter!= NULL) { //manuel olarak son düğümün nextini null a atadığımız için iter != NULL kontrolü doğru
	i++;
	printf("%d. eleman: %d \n", i, iter->data);
	iter = iter->next;
}
iter = root;
while (iter->next != NULL) {
	printf("%d ", iter->data);
	iter = iter->next;

}

*/