#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

//Add an element to the end of the list.
int add();
//Add an element to the top of the list.
int addStart();
//Display the contents of the list.
int display();
//Delete an element from the list.
int remove();
//Display the length of the list.
int size();
//Search the list for a user specified integer.
int search();
/*new element*/
int createLinkedList();
int newIndex();

void main() {

	struct node *head;
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	head->value = 5;
}