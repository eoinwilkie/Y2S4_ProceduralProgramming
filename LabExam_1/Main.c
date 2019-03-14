/*
	Eoin Wilkie
	G00363134
	Advanced Procedural Programming
	Lab Exam 2019
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int raceType;
	char raceVenue[20];
	int raceDay;
	int raceMonth;
	char firstName[20];
	char surname[20];
	float winningTime;
} winningRaceTimes_t;

void displayMenu(winningRaceTimes_t* races, int dbSize);
//1.
void addNewRaceTime(winningRaceTimes_t* races, int dbSize);
//2.
void displayAthleteBest(winningRaceTimes_t* races, int dbSize);
//3.
int displayEmptySpaces(winningRaceTimes_t* races, int dbSize);
//extra
void displayRaces(winningRaceTimes_t* races, int dbSize);

void main() {
	int dbSize;
	FILE* outfile;

	winningRaceTimes_t* races;
	//create structs, size of userInput
	printf("Enter size of database: ");
	scanf("%d", &dbSize);
	//create malloc/struct
	races = (winningRaceTimes_t*)malloc(dbSize * sizeof(winningRaceTimes_t));

	//initialise array with race times of -1
	for (int i = 0; i < dbSize; i++) {
		(races + i)->winningTime = 0;
	}
	//display menu
	displayMenu(races, dbSize);

	outfile = fopen("WinningRace.txt", "w");

	if (outfile != NULL){

		for (int i = 0; i < dbSize; i++) {
			if ((races + i)->winningTime > 0){

			fprintf(outfile, "%d00m %s %d %d %s %s %.0f\n",
				(races + i)->raceType, (races + i)->raceVenue, (races + i)->raceDay,
				(races + i)->raceMonth, (races + i)->firstName, (races + i)->surname,
				(races + i)->winningTime);
			}

		}
	fclose(outfile);
	}
	else {
		printf("Error opening");
	}

	//free malloc
	free(races);
}//main()


void displayMenu(winningRaceTimes_t* races, int dbSize) {
	//menu loop until -1
	int userSelection;
	int raceType = 0;
	int emptySpaces;
	do {
		printf("\nMENU*****\n");
		printf("Please enter 1 to add a winning race\n2 to search for an athlete best winning time\n3 to find the number of remaining spaces in the database\n-1 to exit");
		scanf("%d", &userSelection);

		switch (userSelection) {
			case 1:		//add new race
				addNewRaceTime(races, dbSize);
				raceType = 0;
				break;
			case 2:		//display athlete best
				displayAthleteBest(races, dbSize);
				break;
			case 3:		//display empty spaces
				emptySpaces = displayEmptySpaces(races, dbSize);
				printf("The database has %d empty spaces.\n", emptySpaces);
				break;
			case -1:	//invalid
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid selection.\n");
				break;
			}//switch
		//displayRaces(races, dbSize);
	} while (userSelection != -1);
	
}//displayMenu()

//1.
void addNewRaceTime(winningRaceTimes_t* races, int dbSize){
	int isSpace = 0;
	int freeIndex = -1;
	int raceType;
	float raceTime;

	//check for empty space in db
	for (int i = 0; i < dbSize; i++) {
		if ((races + i)->winningTime <= 0) {	//is space
			isSpace = 1;
			freeIndex = i;
			break;
		}
	}

	//if is space
	if (isSpace == 1) {
		do {
			printf("Please enter the race type, 1 for 100m, 2 for 200m, 3 for 400m");
			scanf("%d", &raceType);
		} while ((raceType < 0) || (raceType > 3));

		(races + freeIndex)->raceType = raceType;
		printf("Enter the race venue: ");
		scanf("%s", (races + freeIndex) -> raceVenue);
		printf("Please enter the race day: ");
		scanf("%d", &(races + freeIndex)-> raceDay);
		printf("Please enterthe race Month: ");
		scanf("%d", &(races + freeIndex)-> raceMonth);
		printf("Please enter the race winner first name: ");
		scanf("%s", (races + freeIndex)->firstName);
		printf("Please enter the race winner surname: ");
		scanf("%s", (races + freeIndex)->surname);

		do {
			printf("Please enter the race time: ");
			scanf("%f", &raceTime);
		}while(raceTime <= 0);
		(races + freeIndex)-> winningTime = raceTime;
	}
	else {	//no space
		printf("No space remaining on database.\n");
	}
}//addNewRaceTime()

//2.
void displayAthleteBest(winningRaceTimes_t* races, int dbSize) {
	//get athleteName
	char firstname[20];
	char surname[20];
	int raceType;
	int searchFound = 0;
	int foundIndex;

	//forget how to split strings
	printf("Please enter the race winner firstname:");
	scanf("%s", firstname);
	printf("Please enter the race winner surname");
	scanf("%s", surname);

	do {
		printf("Please enter the race type, 1 for 100m, 2 for 200m, 3 for 400m");
		scanf("%d", &raceType);
	} while ((raceType < 0) || (raceType > 3));

	//search
	for (int i = 0; i < dbSize; i++) {
		if ((strcmp((races + i)->firstName, firstname) == 0) && (strcmp((races + i)->surname, surname) == 0)) {
			if ((races + i)->raceType == raceType){
				searchFound = 1;
				foundIndex = i;
				break;
			}
		}
	}

	if (searchFound == 1)
	{
		printf("Search found - ");
		printf("The best winning time is %.0f.\n", (races + foundIndex)->winningTime);

	}else {

		printf("Search not found.\n");
	}
}//displayAthleteBest()

//3.
int displayEmptySpaces(winningRaceTimes_t* races, int dbSize) {
	int countEmpty = 0;
	//check for empty space in db
	for (int i = 0; i < dbSize; i++) {
		if ((races + i)->winningTime <= 0) {	//is space
			countEmpty++;
		}
	}
	return countEmpty;
}//displayEmptySpaces()

void displayRaces(winningRaceTimes_t* races, int dbSize) {
	for (int i = 0; i < dbSize; i++) {
		printf("DISPLAYING TABLE\n");
		printf("%d %s %d %d %s %s %f\n",
			(races + i)->raceType, (races + i)->raceVenue, (races + i)->raceDay,
			(races + i)->raceMonth, (races + i)->firstName, (races + i)->surname,
			(races + i)->winningTime);
	}
}//displayRaces()
