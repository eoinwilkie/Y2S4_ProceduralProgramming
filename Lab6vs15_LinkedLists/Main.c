#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
	char name[30];
	int age;
	char ID[10];
	float average;
	char email[30];
	char mobile[30];

	struct node* NEXT;
	struct node* PREV;
};

void AddElementAtStart(struct node** top);	
void AddElementAtEnd(struct node* top);
void AddElementAtPos(struct node* top, int position);
void DeleteElementAtStart(struct node** top);
void DeleteElementAtEnd(struct node* top);
void DeleteElementAtPos(struct node* top, int position);

int Listlength(struct node* top);
void DisplayList(struct node* top);

void main()
{
	struct node* headPtr = NULL;
	struct node* tailPtr = NULL;
	int choice;
	int position;

	printf("*****[ MENU ]*****\n");
	printf("* 1. Add a node at the start.\n* 2. Add a node at the end.\n* 3. Display the list.\n");
	printf("* 4. Delete a node from the start.\n* 5. Delete a node from the end.\n");
	printf("* 6. Add a position.\n* 7. Delete a position.\n*-1. Exit.\n");
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
		
		printf("*****[ MENU ]*****\n");
		printf("* 1. Add a node at the start.\n* 2. Add a node at the end.\n* 3. Display the list.\n");
		printf("* 4. Delete a node from the start.\n* 5. Delete a node from the end.\n");
		printf("* 6. Add a position.\n* 7. Delete a position.\n*-1. Exit.\n");
		scanf("%d", &choice);
	}
}


void AddElementAtStart(struct node** top)
{
	struct node* newNode;

	newNode = (struct node*)malloc(sizeof(struct node));
	printf("Please enter Name\n");
	scanf("%s", newNode->name);
	printf("Please enter Age\n");
	scanf("%d", &newNode->age);
	printf("Please enter ID\n");
	scanf("%d", &newNode->ID);
	printf("Please enter Average\n");
	scanf("%f", &newNode->average);
	printf("Please enter E-Mail\n");
	scanf("%s", newNode->email);
	printf("Please enter Mobile\n");
	scanf("%s", newNode->mobile);

	newNode->NEXT = *top;
	*top = newNode;
}


void DisplayList(struct node* top)
{
	struct node* temp = top;
	while (temp != NULL)
	{
		printf("Name: %s, age: %d, ID: %s, avgGrade: %.2f, email: %s, mobile: %s\n",
			temp->name, temp->age, temp->ID, temp->average, temp->email, temp->mobile);
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

	printf("Please enter Name\n");
	scanf("%s", newNode->name);
	printf("Please enter Age\n");
	scanf("%d", &newNode->age);
	printf("Please enter ID\n");
	scanf("%d", &newNode->ID);
	printf("Please enter Average\n");
	scanf("%f", &newNode->average);
	printf("Please enter E-Mail\n");
	scanf("%s", newNode->email);
	printf("Please enter Mobile\n");
	scanf("%s", newNode->mobile);

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

	printf("Please enter Name\n");
	scanf("%s", newNode->name);
	printf("Please enter Age\n");
	scanf("%d", &newNode->age);
	printf("Please enter ID\n");
	scanf("%d", &newNode->ID);
	printf("Please enter Average\n");
	scanf("%f", &newNode->average);
	printf("Please enter E-Mail\n");
	scanf("%s", newNode->email);
	printf("Please enter Mobile\n");
	scanf("%s", newNode->mobile);

	newNode->NEXT = temp;
	prev_temp->NEXT = newNode;
}


void DeleteElementAtPos(struct node* top, int position)
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


	prev_temp->NEXT = temp->NEXT;
	free(temp);

}