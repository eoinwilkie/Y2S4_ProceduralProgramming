#include<stdio.h>
#include<stdlib.h>


typedef struct
{
	long ID;
	char title[30];
	char author[20];
	double price;
}libraryBook_t;

void displayLibraryBooks(libraryBook_t *libraryBooks, int noOfBooks);
void add_book(libraryBook_t *libraryBooks, int noOfBooks);
void display_book(libraryBook_t *libraryBooks, int noOfBooks, int searchISBN);
void displayMenu(libraryBook_t *libraryBooks);
void edit_book(libraryBook_t *libraryBooks, int noOfBooks, int searchISBN);

void main() {
	int noOfBooks;
	libraryBook_t *libraryBooks;

	//?can this section be moved to fun
	printf("Number library books set by the program user: ");
	scanf("%d", &noOfBooks);
	libraryBooks = (libraryBook_t*)malloc(noOfBooks * sizeof(libraryBook_t));

	//2.Initialise the array of book structures by placing a “0” in the book number of each array element
	for (int i = 0; i < noOfBooks; i++)
		(libraryBooks + i)->ID = 0;
	printf("\nLibrary books created.\n");

	//Menu - runs until -1
	displayMenu(libraryBooks, noOfBooks);
}

void displayLibraryBooks(libraryBook_t *libraryBooks, int noOfBooks) {
	printf("DISPLAYING LIBRARY BOOKS\n");
	printf("%d\n", noOfBooks);
	for (int i = 0; i < noOfBooks; i++) {
		printf("ID: %d\n", (libraryBooks + i)->ID);
	}
}

/*
Adds a new book to first available space
Available space indicated by ISBN value of 0
*/
void add_book(libraryBook_t *libraryBooks, int noOfBooks) {
	// id - title - author - price
	int bookAdded = 0;
	for (int i = 0; i < noOfBooks; i++)
	{
		if ((libraryBooks + i)->ID == 0) {
			printf("Enter book details(id - title - author - price): ");
			scanf("%d %s %s %lf", &(libraryBooks + i)->ID, (libraryBooks + i)->title, (libraryBooks + i)->author, &(libraryBooks + i)->price);
			printf("Adding new book...\n");
			bookAdded = 1;
			break;
		}
	}
	if (bookAdded == 0)
		printf("Not enough space.\n");

}//add_book()

/*
Search for book ISBN and displays book 
*/
void display_book(libraryBook_t *libraryBooks, int noOfBooks, int searchISBN) {
	int bookFound = 0;
	for (int i = 0; i < noOfBooks; i++)
	{
		if ((libraryBooks + i)->ID == searchISBN) {
			printf("ID: %d, title: %s, author: %s, price: %.2lf", (libraryBooks + i)->ID, (libraryBooks + i)->title, (libraryBooks + i)->author, (libraryBooks + i)->price);
			bookFound = 1;
			break;
		}
	}
	if (bookFound == 0)
		printf("Book not Found.\n");
}//display_book()

/*
Search for book ISBN and allows user to enter new price for book
*/
void edit_book(libraryBook_t *libraryBooks, int noOfBooks, int searchISBN) {
	//?how to edit, only edit price? - req menu to edit all values
	for (int i = 0; i < noOfBooks; i++)
	{
		if ((libraryBooks + i)->ID == searchISBN) {
			printf("ID: %d, title: %s, author: %s, price: %.2lf\n", (libraryBooks + i)->ID, (libraryBooks + i)->title, (libraryBooks + i)->author, (libraryBooks + i)->price);
			printf("Enter new price: ");
			scanf("%lf", &(libraryBooks + i)->price);
			break;
		}
	}

}//edit_book()

/*
Displays menu, -1 to exit.
1. Search book#, display its members details
2. Add new book to array, if available space
3. Edit book price
*/
void displayMenu(libraryBook_t *libraryBooks, int noOfBooks) {
	//prompt userInput
	int userInput = 0;
	int searchISBN;

	while (userInput != -1) {
		printf("\nMENU\n 1. Search book\n 2. Add book\n 3. Edit book price\n-1. Exit\n");
		scanf("%d", &userInput);

		switch (userInput) {
		case 1:
			printf("Enter ISBN: ");
			scanf("%d", &searchISBN);
			printf("Searching...\n");
			//prompt user to enter ISBN search
			if (searchISBN != 0)
				display_book(libraryBooks, noOfBooks, searchISBN);
			else
				printf("Invalid ISBN selection\n");
			break;
		case 2:
			//check if full
			printf("Adding new book details...\n");
			add_book(libraryBooks, noOfBooks);
			break;
		case 3:
			printf("Enter ISBN: ");
			scanf("%d", &searchISBN);
			printf("Searching...\n");
			edit_book(libraryBooks, noOfBooks, searchISBN);
			break;
		case -1:
			printf("Exiting...");
			break;
		default:
			printf("Invalid selection\n");
			//while loop req for menu
			break;
		}
	}
}//displayMenu()
