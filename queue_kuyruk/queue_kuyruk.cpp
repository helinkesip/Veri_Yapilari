/*#include <iostream>
#include <stdio.h>
#include <stdlib.h>


// Queue Node
typedef struct node {
	int data;
	struct node* next;
}node;

// Front & Rear

node* front = NULL;
node* rear = NULL;

int enqueue(int data) {
	// Queue is empty
	if (front == NULL) {
		node* new_node = (node*)malloc(sizeof(node));
		new_node->data = data;
		new_node->next = NULL;

		front = rear = new_node;
	}
	else {
		node* new_node = (node*)malloc(sizeof(node));
		new_node->data = data;
		new_node->next = NULL;
		
		rear->next = new_node;

		rear = new_node;
	}
	return 0;
}

//Display queue 

int display() {

	//Queue
	if (front == NULL) {
		printf("kuyrukta eleman bulunmuyor. \n");
		return 0;
	}
	else {
		node* index = front;
		while (index != NULL) {
			printf("%d - ", index->data);
			index = index->next;
		}
		printf("\n");
		return 1;

	}


}

//dequeue 

int dequeue() {

	//Queue is empty
	if (front == NULL) {
		printf("queue is empty\n");
		return 1;
	}

	node* temp = front;
	front = front->next;
	free(temp);


	return 1;
}

int main() {

	enqueue(5);
	enqueue(7);
	enqueue(9);
	enqueue(20);
	enqueue(8);
	enqueue(1);
	display();

	dequeue();
	display();

	return 0;
}

*/