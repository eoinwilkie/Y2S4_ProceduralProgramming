#include <stdio.h>
#include <stdlib.h>

#define NO_STATES 5
#define NO_CANDIDATES 4

void getVoteResults(int votes[][NO_STATES]);
void displayVoteResults(int votes[][NO_STATES]);
void displayStateWinners(int votes[][NO_STATES], int stateWinners[NO_STATES]);
int getStateWinner(int votes[][NO_STATES], int state);
void displayNewMayor(int stateReults[NO_STATES]);
char displayCandidate(int candidateNo);

void main()
{
	int votes[NO_CANDIDATES][NO_STATES];
	int stateResults[NO_STATES];		//contains id of winner per state
	for (int state = 0; state < NO_STATES; state++)
	{
		stateResults[state] = 0;
	}
	//int **votes;
	//votes = (int**) malloc()

	getVoteResults(votes);
	displayVoteResults(votes);
	displayStateWinners(votes, stateResults);
	displayNewMayor(stateResults);
}//main()

/*
Prompts user to enter values for election table
*/
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
}//getVoteResults()

/*
Displays vote results as table
*/
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
}//displayVoteResults()

/*
Displays winners for each state and prints to console.
*/
void displayStateWinners(int votes[][NO_STATES], int stateWinners[NO_STATES])
{
	int stateWinner;
	printf("Displaying state winners...\n");
	for (int state = 0; state < NO_STATES; state++)
	{
		stateWinner = getStateWinner(votes, state);
		stateWinners[stateWinner]++;
		printf("State %d: Candidate %c\n", state+1, displayCandidate(stateWinner));
	}
}//displayStateWinners()

/*
Gets the state winner for each state
*/
int getStateWinner(int votes[][NO_STATES], int state)
{
	int stateWin;
	char stateWinChar;
	int stateHigh = -1;

	for (int candidate = 0; candidate < NO_CANDIDATES; candidate++)
	{
		if (votes[candidate][state] > stateHigh)
		{
			stateHigh = votes[candidate][state];
			stateWin = candidate;
		}
	}
	//return state winner
	return stateWin;
}//getStateWinner()

/*
Reads scores per state and returns the winning candidate
*/
void displayNewMayor(int stateResults[NO_STATES])
{
	int newMayor = -1;
	int voteCountHigh = -1;

	printf("Displaying state winners...\n");
	for (int state = 0; state < NO_STATES; state++)
	{
		if (stateResults[state] > voteCountHigh)
		{
			newMayor = state;
			voteCountHigh = stateResults[state];
		}
	}
	printf("Candidate %c has been elected mayor!\n", displayCandidate(newMayor));
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