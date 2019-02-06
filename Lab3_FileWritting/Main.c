/*
Author: Eoin Wilkie
*/
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

void main()
{
	int usernameValid = 0;
	char username[20];
	char password[20];

	FILE* fileBugs;
	FILE* fileUrgent;
	int numInputs;
	int bugId;
	char bugApp[20];
	char bugStatus[20];
	char bugName[20];
	int countNewBugs;

	printf("Enter username: ");
	scanf("%s", username);

	fileBugs = fopen("Bugs.txt", "r");

	//read file: bugs
	if (fileBugs == NULL)
	{
		printf("No save file found.\n");
	}
	else
	{
		while (!feof(fileBugs))
		{
			numInputs = fscanf(fileBugs, "%d %s %s %s", &bugId, bugApp, bugStatus, bugName);
			if (numInputs == 4)
			{
				if (strcmpi(bugName, username) == 0)
				{
					printf("%d.%s: %s %s\n", bugId, bugApp, bugStatus, bugName);
					//if bug status == O|A, store to urgent.txt
					if ((strcmpi(bugStatus, "Open") == 0) || (strcmpi(bugStatus, "Assigned") == 0))
					{
						fileUrgent = fopen("Urgent.txt", "a");

						if (fileBugs == NULL)
						{
							printf("No save file found.\n");
							return 0;
						}
						else
						{
							//write to urgentFile
							fprintf(fileUrgent, "%d %s %s %s\n", bugId, bugApp, bugStatus, bugName);

							fclose(fileUrgent);
						}//writting to urgentFile
					}
				}//searching file for userInput match
			}
		}
		fclose(fileBugs);
	}

	//add to bugs
	printf("How many new bugs to enter: ");
	scanf("%d", &countNewBugs);

	fileBugs = fopen("Bugs.txt", "a");

	if (fileBugs == NULL)
	{
		printf("No save file found.\n");
		return 0;
	}
	else
	{
		for (int i = 0; i < countNewBugs; i++)
		{
			scanf("%d %s %s %s", &bugId, bugApp, bugStatus, bugName);
			fprintf(fileBugs, "%d %s %s %s\n", bugId, bugApp, bugStatus, bugName);
		}

		fclose(fileBugs);
	}//writting to urgentFile
		
	getch();
}