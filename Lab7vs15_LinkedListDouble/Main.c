#include <stdio.h>

struct node {
	int value;

	struct node* NEXT;
	struct node* PREV;
};

void addElementStart(struct node** top, struct node** bottm);

void main() {
	struct node* headPtr = NULL;
	struct node* tailPtr = NULL;

}

void addElementStart(struct node** top, struct node** bottom) {
	struct node* newNode;
	newNode = (struct node*) malloc(sizeof(struct node*));
	printf("Enter new value\n");
	scanf("%d", &newNode->value);

	if (*top == NULL) {
		newNode->PREV = NULL;
		newNode->NEXT = NULL;
		*top = newNode;
		*bottom= newNode;
	}
	else {
		newNode->PREV = NULL;
		newNode->NEXT = *top;
		(*top)->PREV = newNode;
		*top = newNode;
	}

}
