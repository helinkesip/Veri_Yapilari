//dairesel bağlı listelerde sonsuza kadar dolanma riski var, böyle olmamasını sağlayacak kontrol iter'in roota yani ilk düğüme eşit olması.

#include <iostream>

typedef struct n {
    int data;
    n* next;
}node;

void bastir(node* r) {
    node* iter = r;
    printf("%d", iter->data);
    iter = iter->next;
    while (iter != r) {
        printf("%d", iter->data);
        iter = iter->next;
    }
    printf("\n");
}
void sonaekle(node* r, int data) {
    node* iter = r;

    while (r->next != r) {
        iter = iter->next;
    }
    iter->next = (node*)malloc(sizeof(node));
    iter->next->data = data;
    iter->next->next = r; //dairesel olduğu için ilk düğüme bağlayacağız eklenen elemanı
}
node* ekleSirali(node* r,int data) {
    if (r == NULL) { //linked list boşsa
        r = (node*)malloc(sizeof(node));
        r->next = NULL;




    }

}








int main()
{
    
}


