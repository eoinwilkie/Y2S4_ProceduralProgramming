#include <stdio.h>
#pragma warning(disable : 4996)

void main()
{
	FILE* inputfile;
	char dept[20];
	int salesCost;
	int shopTotal = 0;
	int varRead;
	int dptTtlHardware = 0, dptTtlGrocery = 0, dptTtlDrapery = 0;

	inputfile = fopen("DailySales.txt", "r");

	//printf("%d\n", inputfile);

	if (inputfile == NULL)//File was not opened
	{
		printf("Sorry the file was not opened\n");
	}
	else
	{
		printf("The files was opened\n");

		while (!feof(inputfile))
		{
			varRead = fscanf(inputfile, "%s %d", dept, &salesCost);

			if (varRead == 2)
			{
				printf("Dept %s Cost %d\n", dept, salesCost);
				shopTotal += salesCost;

				//find department total
				//printf("DEBUG .%s.\n", dept);
				if ((strcmp(dept, "Hardware") == 0) || (strcmp(dept, "hardware") == 0))
				{
					dptTtlHardware += salesCost;
				}
				else if ((strcmp(dept, "Grocery") == 0) || (strcmp(dept, "grocery") == 0))
				{
					dptTtlGrocery += salesCost;
				}
				else if ((strcmp(dept, "Drapery") == 0) || (strcmp(dept, "drapery") == 0))
				{
					dptTtlDrapery += salesCost;
				}
			}
		}

		printf("\n\n===== Totals =====\n");
		printf("Total shop cost %d\n", shopTotal);
		printf("Total hardware cost %d\n", dptTtlHardware);
		printf("Total grocery cost %d\n", dptTtlGrocery);
		printf("Total drapery cost %d\n", dptTtlDrapery);

		fclose(inputfile);
		_getch();
	}
}