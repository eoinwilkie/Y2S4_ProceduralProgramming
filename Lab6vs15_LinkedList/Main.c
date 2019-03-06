#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

//Add an element to the end of the list.
void add(struct node *head);
//Add an element to the top of the list.
void addStart(struct node** head);
//Display the contents of the list.
void display(struct node *head);
//Delete an element from the list.
//void remove();
//Display the length of the list.
//void size();
//Search the list for a user specified integer.
void search(struct node *head, int search);
/*new element*/
void initList(struct node *head);


void main() {

	struct node *head;
	head = (struct node*)malloc(sizeof(struct node));

	//tests
	initList(head);
	add(head);
	add(head);
	add(head);
	add(head);
	display(head);
	search(head, 7);
	/*
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
void add(struct node *head) {
	int data;
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while (temp->next != NULL){
		temp = temp->next;
	}
	struct node *newNode;
	newNode= (struct node*)malloc(sizeof(struct node));
	printf("\nEnterdata for this node");
	scanf("%d", &newNode->data);
	newNode->next = NULL;
	temp->next = newNode;    
}//add()

//Add an element to the top of the list.
void addStart(struct node **head) {
	struct node *newNode;
	newNode = (struct node*)malloc(sizeof(struct node));
	printf("\nEnterdata for this node");
	scanf("%d", &newNode->data);
	newNode->next = *head;
	*head = newNode; // transfer the address of newNode' to 'head
}//*/
//Display the contents of the list.
void display(struct node *head) {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while (temp != NULL) {
		printf("Data: %d", temp->data);
		temp = temp->next;
	}
}
/*/Delete an element from the list.
void remove(){

}//*/
/*/Display the length of the list.
void size() {

}//*/
//Search the list for a user specified integer.
void search(struct node *head, int search) {
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = head;
	while (temp != NULL) {
		if (temp->data == search){
			printf("\nDataFound.");
			return;
		}
		temp = temp->next;
	}
	printf("\nDatanot found");
}//*/

void initList(struct node *head) {
	printf("\nEnterdata for this node");
	scanf("%d", &head->data);
	head->next = NULL;

}
