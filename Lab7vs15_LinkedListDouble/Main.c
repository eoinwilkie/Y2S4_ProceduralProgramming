#include <stdio.h>

struct node {
	int value;

	struct node* NEXT;
	struct node* PREV;
};

void addElementStart(struct node** top, struct node** bottom);
void addElementEnd(struct node** top, struct node** bottom);
void displayList(struct node* top);
void displayListReverse(struct node* bottom);
void deleteElementStart(struct node **top, struct node** bottom);
void deleteElementEnd(struct node** top, struct node** bottom);
int listLength(struct node* top);
void insertElementAt(struct node** top, struct node**bottom, int location);

void main() {
	struct node* headPtr = NULL;
	struct node* tailPtr = NULL;
	int userSelection, insertLocation;

	/**
		=====[ MENU ]=====
	 */
	do {
		printf("====[ MENU ]====\n\t1. Add node start\n\t2. Add node end\n\t3. Display list\n\t4. Display list reverse");
		printf("\n\t5. Del element at start\n\t6. Del element at end\n\t7. Insert at position");
		scanf("%d", &userSelection);

		switch (userSelection){
		case 1:
			addElementStart(&headPtr, &tailPtr);
			break;
		case 2:
			addElementEnd(&headPtr, &tailPtr);
			break;
		case 3:
			displayList(headPtr);
			break;
		case 4:
			displayListReverse(tailPtr);
			break;
		case 5:
			deleteElementStart(&headPtr, &tailPtr);
			displayList(headPtr);
			break;
		case 6:
			deleteElementEnd(&headPtr, &tailPtr);
			displayList(headPtr);
			break;
		case 7:
			do {
				printf("\tInsert where: ");
				scanf("%d", &insertLocation);
			} while (insertLocation > listLength(headPtr) + 1 || insertLocation < 1);

			insertElementAt(&headPtr, &tailPtr, insertLocation);
			break;
		}
	} while (userSelection != 0);
}

void addElementStart(struct node** top, struct node** bottom) {
	struct node *temp = *top;
	struct node* newNode;
	newNode = (struct node*) malloc(sizeof(struct node));

	printf("Enter new value\n");
	scanf("%d", &newNode->value);

	if (*top == NULL) {
		//list is empty
		newNode->PREV = NULL;
		newNode->NEXT = NULL;
		*top = newNode;
		*bottom= newNode;
	}
	else {
		//list is not empty
		newNode->PREV = NULL;
		newNode->NEXT = *top;
		(*top)->PREV = newNode;
		*top = newNode;
	}

}

void addElementEnd(struct node** top, struct node** bottom) {
	struct node* newNode;

	newNode = (struct node*) malloc(sizeof(struct node));

	printf("Enter new value\n");
	scanf("%d", &newNode->value);

	if (*bottom == NULL) {
		newNode->PREV = NULL;
		newNode->NEXT = NULL;
		*top = newNode;
		*bottom= newNode;
	}
	else {
		newNode->NEXT = NULL;
		(*bottom)->NEXT= newNode;
		newNode->PREV = *(bottom);
		*bottom = newNode;
	}
}

void displayList(struct node* top){
	struct node* temp = top;
	while (temp != NULL)
	{
		printf("Value: %d\n", temp->value);
		temp = temp->NEXT;
	}
}

void displayListReverse(struct node* bottom) {
	struct node* temp = bottom;
	while (temp != NULL)
	{
		printf("Value: %d\n", temp->value);
		temp = temp->PREV;
	}

}

void deleteElementStart(struct node **top, struct node** bottom) {
	struct node* newNode;

	//if list is empty, return
	if (*top == NULL)
		return;

	//check if last element is first
	if (*top == *bottom) {
		*top = NULL;
		*bottom = NULL;
		free(*top);
	}
	else {
		newNode = *top;
		newNode = newNode->NEXT;
		newNode->PREV = NULL;
		free(*top);
		*top = newNode;
	}
}

void deleteElementEnd(struct node** top, struct node** bottom) {
	struct node* newNode;

	//if list is empty, return
	if (*top == NULL)
		return;

	//check if last element is first
	if (*top == *bottom) {
		*top = NULL;
		*bottom = NULL;
		free(*top);
	}
	else {
		newNode = *bottom;
		newNode = newNode->PREV;
		newNode->NEXT = NULL;
		free(*bottom);
		*bottom = newNode;
	}
}

int listLength(struct node* top){
	struct node* temp;
	int count = 0;
	temp = top;

	while (temp != NULL)
	{
		count++;
		temp = temp->NEXT;
	}

	return count;
}

void insertElementAt(struct node** top, struct node**bottom, int location) {
	//if <= 0, insert at start. If > listLength, insert at end.
	//restrictions on location entered are applied at the menu, must be between 1 and listLength +1 (to allow insertion at end)
	int i = 1;
	struct node* temp;
	struct node* prevTemp;
	struct node* newNode;
	temp = *top;

	if (location <= 1) {
		//insert start - could have additional conditions to ensure locations is in range
		addElementStart(top, bottom);
	}
	else {
		//search through list for location
		while (temp->NEXT != NULL) {
			if (i == location) {
				//create and insert here
				newNode = (struct node*) malloc(sizeof(struct node));

				printf("Enter new value\n");
				scanf("%d", &newNode->value);

				//switch
				newNode->PREV = temp->PREV;
				prevTemp = temp->PREV;
				prevTemp->NEXT = newNode;
				newNode->NEXT = temp;
				temp->PREV = newNode;

				return;
			}
			i++;
			temp = temp->NEXT;
		}
		//if reach here, add to end - could have additional conditions to ensure location is in range
		addElementEnd(top, bottom);
	}
}
