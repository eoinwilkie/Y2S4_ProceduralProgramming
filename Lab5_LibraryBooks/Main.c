#include <stdio.h>
#include <stdlib.h>

void initialiseLibraryBooks(struct libraryBook_t *libraryBooks, int *noOfBooks);
void displayLibraryBooks(struct libraryBook_t *libraryBooks, int *noOfBooks);

typedef struct
{
	long ID;
	char title[30];
	char author[20];
	double price;
}libraryBook_t;

void main(){
	int *noOfBooks;
	libraryBook_t *libraryBooks;

	initialiseLibraryBooks(&libraryBooks, &noOfBooks);
	printf("Init fin\n");
	//displayLibraryBooks(libraryBooks, noOfBooks);

}

void initialiseLibraryBooks(libraryBook_t * libraryBooks, int * noOfBooks){
	/*
	Number library books set by the program user.
	*/
	printf("Number library books set by the program user: ");
	scanf("%d", &noOfBooks);

	libraryBooks = (libraryBook_t*)malloc(*noOfBooks * sizeof(libraryBook_t));
	//printf("%d", noOfBooks);
	/*
	for (int i = 0; i < noOfBooks; i++) {
		//libraryBooks[i].ID = 0;
		//(*(libraryBooks+1)).ID = 0;
		//(libraryBooks + i)->ID = 0;
	}*/
}

void displayLibraryBooks(libraryBook_t *libraryBooks, int noOfBooks) {
	printf("DISPLAYING LIBRARY BOOKS\n");
	printf("%d", noOfBooks);
	for (int i = 0; i < noOfBooks; i++) {
		printf("ID: %d\n", (libraryBooks + i)->ID);
	}
}
