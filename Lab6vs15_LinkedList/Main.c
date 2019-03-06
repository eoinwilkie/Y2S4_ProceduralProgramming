#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
}node;

//Add an element to the end of the list.
void add(struct node *node, int value);
//Add an element to the top of the list.
void addStart(struct node *node, int value);
//Display the contents of the list.
void display(struct node *node);
//Delete an element from the list.
void remove(struct node *node, int value);
//Display the length of the list.
void size();
//Search the list for a user specified integer.
void search(struct node *node, int value);
/*new element*/
void createLinkedList();
void newIndex();

void main() {

	struct node *head;

	//tests
	/*
	add(head, 5);
	display(head);
	search(head, 1);
	remove(head, 1);
	add(head, 1);
	search(head, 1);
	size();
	display(head);
	remove(head, 1);
	size();
	*/
}


//Add an element to the end of the list.
void add(struct node *node, int value) {
	/*
	node = (struct node *)malloc(sizeof(struct node));
	node->next = NULL;
	node->value = 5;
	*/
}//add()
//Add an element to the top of the list.
void addStart(struct node *node, int value) {

}
//Display the contents of the list.
void display(struct node *node) {

}
//Delete an element from the list.
void remove(struct node *node, int value) {

}
//Display the length of the list.
void size() {

}
//Search the list for a user specified integer.
void search(struct node *node, int value) {

}
/*new element*/
void createLinkedList() {

}
void newIndex() {

}
