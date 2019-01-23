#include <stdio.h>

typedef struct //Company
{
	char name[40];
	int regNo;
	int vatNo;
}company_t;


void main()
{
	//vars
	FILE* file;
	company_t company;
	int noCompanies, menuSelection = -1, numInputs;

	while (menuSelection != 0)
	{
		switch (menuSelection)
		{
		case 1:	//read file
			file = fopen("CompanyStruct.txt", "r");

			if (file == NULL)
			{
				printf("\tThe out file could not be opened.\n");
			}
			else
			{
				while (!feof(file))
				{
					numInputs = fscanf(file, "%s %d %d", &company.name, &company.regNo, &company.vatNo);
					if (numInputs == 3)
					{
						printf("\tName: %s Reg No: %d Vat No: %d\n", company.name, company.regNo, company.vatNo);
					}
				}

				fclose(file);
				menuSelection = -1;
			}
			break;
		case 2:	//append to file
			//user prompt: how many companies
			printf("\tEnter number of companies: ");
			scanf(" %d", &noCompanies);

			//openFile: change to append
			file = fopen("CompanyStruct.txt", "a");

			if (file == NULL)
			{
				printf("\tThe out file could not be opened.\n");
			}
			else
			{
				printf("\tEnter company details(name, regNo, vatNo)\n");
				for (int i = 0; i < noCompanies; i++)
				{
					//enter company details
					printf("\tCompany %d:", i + 1);
					scanf("%s %d %d", &company.name, &company.regNo, &company.vatNo);
					fprintf(file, "%s %d %d\n", company.name, company.regNo, company.vatNo);
				}
				//close file
				fclose(file);
			}
			menuSelection = -1;
			break;

		case 3:	//del individual - ?how
			menuSelection = -1;
			break;
		case 4:  //del all
				 //openFile: change to append
			file = fopen("CompanyStruct.txt", "w");

			if (file == NULL)
			{
				printf("\tThe out file could not be opened.\n");
			}
			else
			{
				printf("\tThe out file has been wiped.\n");
				//close file
				fclose(file);
			}
			menuSelection = -1;
			break;
		default:
			//create menu: 1) view, 2) add add additional functions, del?
			printf("MENU\n1) VIEW\n2) ADD\n3) DEL(not implemented)\n4) DEL ALL\n");
			scanf(" %d", &menuSelection);
			break;
		}//switch
	}
}