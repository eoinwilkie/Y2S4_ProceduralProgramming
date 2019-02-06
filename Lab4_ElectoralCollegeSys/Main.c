#include <stdio.h>
#include <stdlib.h>

#define NO_STATES 5
#define NO_CANDIDATES 4

void getVoteResults(int votes[][NO_STATES]);
void displayVoteResults(int votes[][NO_STATES]);
void displayStateWinner(int votes[][NO_STATES]);
void displayNewMayor(int votes[][NO_STATES]);
char displayCandidate(int candidateNo);

void main()
{
	int votes[NO_CANDIDATES][NO_STATES];
	//int **votes;
	//votes = (int**) malloc()

	getVoteResults(votes);
	displayVoteResults(votes);
	displayStateWinner(votes);
	displayNewMayor(votes);
}

//functions
void getVoteResults(int votes[][NO_STATES])
{
	for (int state = 0; state < NO_STATES; state++)
	{
		printf("State %d votes...\n", state + 1);
		for (int candidate = 0; candidate < NO_CANDIDATES; candidate++)
		{
			//enter candidate i
			printf("Enter votes for candidate %d: ", candidate+1);
			scanf("%d", &votes[candidate][state]);
		}
	}

}

void displayVoteResults(int votes[][NO_STATES])
{
	printf("\n\t\t\tTable of the vote data\nState\tCandidate A\tCandidate B\tCandidate C\tCandidate D\n");
	for (int state = 0; state < NO_STATES; state++)
	{
		printf("State %d\t", state+1);
		for (int candidate = 0; candidate < NO_CANDIDATES; candidate++)
		{
			printf("%d\t\t", votes[candidate][state]);
		}
		printf("\n");
	}
}

void displayStateWinner(int votes[][NO_STATES])
{
	int stateWin;
	char stateWinChar;
	int stateHigh;

	printf("\n\t\t\tState winners\n");
	for (int state = 0; state < NO_STATES; state++)
	{
		int stateHigh = -1;
		for (int candidate = 0; candidate < NO_CANDIDATES; candidate++)
		{
			if (votes[candidate][state] > stateHigh)
			{
				stateHigh = votes[candidate][state];
				stateWin = candidate;
			}
		}
		//print state winner
		stateWinChar = displayCandidate(stateWin);

		printf("State %d winner: %c\n", state+1, stateWinChar);
	}

}

void displayNewMayor(int votes[][NO_STATES])
{
	int statesWon[NO_CANDIDATES];

	int stateWin;
	char stateWinChar;
	int stateHigh;
	int newMayor;
	char newMayorChar;
	int highStateWon = 0;

	for (int state = 0; state < NO_STATES; state++)
	{
		int stateHigh = -1;
		for (int candidate = 0; candidate < NO_CANDIDATES; candidate++)
		{
			if (votes[candidate][state] > stateHigh)
			{
				stateHigh = votes[candidate][state];
				stateWin = candidate;
			}
		}
		statesWon[stateWin++];
	}

	for (int candidate = 0; candidate < NO_CANDIDATES; candidate++)
	{

		if (statesWon[candidate] > highStateWon)
		{
			highStateWon = statesWon[candidate];
			newMayor = candidate;
		}
	}
	newMayorChar = displayCandidate(newMayor);
	printf("Candidate %c is the new mayor\m", newMayorChar);
}

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
}