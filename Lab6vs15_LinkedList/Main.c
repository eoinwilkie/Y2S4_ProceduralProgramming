#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node* NEXT;
};

void AddElementAtStart(struct node** top);
void AddElementAtEnd(struct node* top);
void DisplayList(struct node* top);
void DeleteElementAtStart(struct node** top);
void DeleteElementAtEnd(struct node* top);
int Listlength(struct node* top);
void AddElementAtPos(struct node* top, int position);
void DeleteElementAtPos(struct node* top, int position);
void main()
{
	struct node* headPtr = NULL;
	int choice;
	int position;

	printf("Please enter 1 to add a node at the start\n2 to add a node at the end of the list\n3 to display the list\n");
	printf("Please enter 4 to delete a node from the start\nPlease enter 5 to delete a node from the end\n");
	printf("Please enter 6 to add a position\nPlease enter 7 to delete at a position\n - 1 to exit\n");
	scanf("%d", &choice);

	while (choice != -1)
	{
		if (choice == 1)
		{
			printf("Adding element at the start\n");
			AddElementAtStart(&headPtr);
		}
		else if (choice == 2)
		{
			printf("Adding element at the end\n");
			if (headPtr == NULL)
				AddElementAtStart(&headPtr);
			else
			{
				AddElementAtEnd(headPtr);
			}
		}
		else if (choice == 3)
		{
			printf("Display the list\n");
			DisplayList(headPtr);
		}

		else if (choice == 4)
		{
			DeleteElementAtStart(&headPtr);
		}

		else if (choice == 5)
		{
			if (Listlength(headPtr) == 1)
				DeleteElementAtStart(&headPtr);
			else
			{
				DeleteElementAtEnd(headPtr);
			}
		}

		else if (choice == 6)
		{
			printf("Please enter the position\n");
			scanf("%d", &position);

			if (position < 1 || position>Listlength(headPtr))
				printf("You need to enter a number between 1 and %d\n", Listlength(headPtr));
			else if (position == 1)
				AddElementAtStart(&headPtr);
			else
				AddElementAtPos(headPtr, position);

		}

		else if (choice == 7)
		{
			printf("Please enter the position\n");
			scanf("%d", &position);

			if (position < 1 || position>Listlength(headPtr))
				printf("You need to enter a number between 1 and %d\n", Listlength(headPtr));
			else if (position == 1)
				DeleteElementAtStart(&headPtr);
			else
				DeleteElementAtPos(headPtr, position);

		}
		printf("Please enter 1 to add a node at the start\n2 to add a node at the end of the list\n3 to display the list\n");
		printf("Please enter 4 to delete a node from the start\nPlease enter 5 to delete a node from the end\n");
		printf("Please enter 6 to add a position\nPlease enter 7 to delete at a position\n - 1 to exit\n");
		scanf("%d", &choice);
	}
}


void AddElementAtStart(struct node** top)
{
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter value of the node\n");
	scanf("%d", &newNode->value);

	newNode->NEXT = *top;
	*top = newNode;
}


void DisplayList(struct node* top)
{
	struct node* temp = top;
	while (temp != NULL)
	{
		printf("The values of the node is %d\n", temp->value);
		temp = temp->NEXT;
	}
}

void AddElementAtEnd(struct node* top)
{
	struct node* temp = top;
	struct node* newNode;

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newNode = (struct node*)malloc(sizeof(struct node));

	printf("Enter the value\n");
	scanf("%d", &newNode->value);

	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}

void DeleteElementAtStart(struct node** top)
{
	struct node* temp;

	temp = *top;

	*top = temp->NEXT;

	free(temp);
}
void DeleteElementAtEnd(struct node* top)
{
	struct node* temp;
	struct node* prev_temp;

	temp = top;

	while (temp->NEXT != NULL)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}

	prev_temp->NEXT = NULL;
	free(temp);
}

int Listlength(struct node* top)
{
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

void AddElementAtPos(struct node* top, int position)
{
	int i;
	struct node* temp;
	struct node* prev_temp;
	struct node* newNode;

	temp = top;

	for (i = 0;i < position - 1;i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}

	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter the value of the node\n");
	scanf("%d", &newNode->value);

	newNode->NEXT = temp;
	prev_temp->NEXT = newNode;
}


void DeleteElementAtPos(struct node* top, int position)
{
	int i;
	struct node* temp;
	struct node* prev_temp;

	temp = top;

	for (i = 0;i < position - 1;i++)
	{
		prev_temp = temp;
		temp = temp->NEXT;
	}


	prev_temp->NEXT = temp->NEXT;
	free(temp);

}