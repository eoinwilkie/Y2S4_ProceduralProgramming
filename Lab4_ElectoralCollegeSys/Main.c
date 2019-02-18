#include <stdio.h>
#include <stdlib.h>

#define NO_STATES 5
#define NO_CANDIDATES 4

void getVoteResults(int **votes);
void displayVoteResults(int **votes);
void displayStateWinners(int **votes, int *stateWinners);
int getStateWinner(int *votes);
void displayNewMayor(int *stateReults);
char displayCandidate(int candidateNo);

void main()
{
	int **votes = (int**)malloc(NO_STATES * sizeof(int *));
	int *stateResults = (int*)malloc(NO_STATES * sizeof(int));

	//assign stateResults to 0 - check if necessary
	for (int i = 0; i < NO_STATES; i++)
	{
		//?unsure what this is doing but seems necessary - may be because I am using [][] to assign
		//seems to be allowing votes to be assigned with [][]
		votes[i] = malloc(NO_CANDIDATES * sizeof(int));

		//assign 0 value to stateResults
		*(stateResults + i) = 0;
	}
	
	getVoteResults(votes);
	displayVoteResults(votes);
	displayStateWinners(votes, stateResults);
	displayNewMayor(stateResults);

	//free maloc
	//should this be free ( votes or **votes )
	free(votes);
	free(stateResults);

}//main()

/*
Prompts user to enter values for election table
*/
void getVoteResults(int **votes)
{
	int tempInt;
	for (int i = 0; i < NO_STATES; i++)
	{
		printf("State %d\n", i + 1);
		for (int j = 0; j < NO_CANDIDATES; j++)
		{
			//enter candidate i
			//?assign to ** directly from scanf?
			printf("Enter votes for candidate %d: ", j + 1);
			//scanf("%d", &tempInt);
			scanf("%d", &votes[i][j]);
			//scanf("%d", (*(*(votes + i)* j));
			//unsure why this is not using * or &
			//?what is diff here? *& values are printed with votes[][]
			//https://cs.brynmawr.edu/Courses/cs246/spring2014/Slides/16_2DArray_Pointers.pdf
			//&votes[i][j] = tempInt;
			//votes[i][j] = tempInt;
		}
	}
}//getVoteResults()

/*
Displays vote results as table
*/
void displayVoteResults(int **votes)
{
	printf("\n\t\t\tTable of the vote data\nState\tCandidate A\tCandidate B\tCandidate C\tCandidate D\n");
	for (int i = 0; i < NO_STATES; i++)
	{
		printf("State %d\t", i+1);
		for (int j = 0; j < NO_CANDIDATES; j++)
		{
			//printf("%d\t\t", *&votes[i][j]);
			printf("%d\t\t", votes[i][j]);
		}
		printf("\n");
	}
}//displayVoteResults()

/*
Displays winners for each state and prints to console.
*/
void displayStateWinners(int **votes, int *stateWinners)
{
	int stateWinner;
	printf("Displaying state winners...\n");
	for (int state = 0; state < NO_STATES; state++)
	{
		stateWinner = getStateWinner(votes[state]);
		stateWinners[stateWinner]++;
		printf("State %d: Candidate %c\n", state+1, displayCandidate(stateWinner));
	}
}//displayStateWinners()

/*
Gets the state winner for each state
*/
int getStateWinner(int *votes)
{
	int stateWin;
	char stateWinChar;
	int stateHigh = -1;

	for (int candidate = 0; candidate < NO_CANDIDATES; candidate++)
	{
		if (votes[candidate] > stateHigh)
		{
			stateHigh = votes[candidate];
			stateWin = candidate;
		}
	}
	//return state winner
	return stateWin;
}//getStateWinner()

/*
Reads scores per state and returns the winning candidate
*/
void displayNewMayor(int *stateResults)
{
	int newMayor = -1;
	int voteCountHigh = -1;

	for (int state = 0; state < NO_STATES; state++)
	{
		if (stateResults[state] > voteCountHigh)
		{
			newMayor = state;
			voteCountHigh = stateResults[state];
		}
	}
	printf("\nCandidate %c has been elected mayor!\n", displayCandidate(newMayor));
}//displayNewMayor()

/*
Displays candate as A/B/C/D based on int input
*/
char displayCandidate(int candidateNo)
{
	switch (candidateNo)
	{
	case 0: return 'A';
		break;
	case 1: return 'B';
		break;
	case 2: return 'C';
		break;
	case 3: return 'D';
		break;
	}
}//displayCandidate()