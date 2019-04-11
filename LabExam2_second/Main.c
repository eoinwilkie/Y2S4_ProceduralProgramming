/*
	Eoin Wilkie
	Had alot of problems getting program started, unsure what is working and what is not as I hadn't time to test
	it properly, seems that everything is functioning in some sense.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee {
	int id;
	char firstname[20];
	char lastname[20];
	char department[20];
	float salary;

	struct employee* NEXT;
};

//
void AddEmployeeAtStart(struct employee** top);
void AddEmployeeAtEnd(struct employee* top);
void DisplayList(struct employee* top, char search[]);
int listLength(struct employee* top);
int containsID(struct employee* top, int id);
void generatePayslip(struct employee* employees, int employeeSearch);

void readEmployees(struct employee** emp);
void ReadEmployeeAtStart(struct employee** top, int id, char firstname[], char lastname[], char department[], float salary);
void ReadEmployeeAtEnd(struct employee* top, int id, char firstname[], char lastname[], char department[], float salary);

void printEmployees(struct employee* emp);
//*/
//main
void main() {
	int menuInput;
	int employeeSearch;
	char departmentSearch[20];
	struct employee* employees = NULL;

	readEmployees(&employees);

	do {
		printf("Please enter 1 to add a new employee to the end of the list\nPlease enter 2 to display the employees and monthly wages bull for a department\n");
		printf("Please enter 3 to generate a payslip for a given employee ID\n-1 Exit");
		scanf("%d", &menuInput);

		switch (menuInput) {
		case 1:
			if (employees == NULL) {
				AddEmployeeAtStart(&employees);
			}
			else
			{
				AddEmployeeAtEnd(employees);
			}
			break;
		case 2:
			printf("Please enter the department to search");
			scanf("%s", departmentSearch);
			//forget how to compare strings
				DisplayList(employees, departmentSearch);
			break;
		case 3:
			printf("Please enter the employee the payslip is for");
			scanf("%d", &employeeSearch);
			generatePayslip(employees, employeeSearch);
			employeeSearch = -1;
			break;
		default:
			printf("Invalid selection, try again.\n");
			break;
		case -1:
			break;
		}


	} while (menuInput != -1);

	//free
	printEmployees(employees);
	free(employees);
}

//====== [FUNCTIONS: START] =====//


void AddEmployeeAtStart(struct employee** top)
{
	struct employee* newNode;
	struct employee* temp = *top;
	int id;

	printf("Please enter the ID of the new employee\n");
	scanf("%d", &id);

	newNode = (struct employee*)malloc(sizeof(struct employee));

	//enter remainingemployee details
	newNode->id = id;
	printf("Please enter employee name\n");
	scanf("%s %s", newNode->firstname, newNode->lastname);
	printf("Please enter employee department\n");
	scanf("%s", newNode->department);
	printf("Please enter employee salary\n");
	scanf("%f", &newNode->salary);

	newNode->NEXT = *top;
	*top = newNode;
}

void AddEmployeeAtEnd(struct employee* top)
{
	struct employee* temp = top;
	struct employee* newNode;
	int matches = 0;
	int id;

	do {
		printf("Please enter the ID of the new employee\n");
		scanf("%d", &id);

		//check if exists in lsit
		matches = containsID(top, id);
		//not working perfect, no time to fix
	} while (matches == 1);


	while (temp->NEXT != NULL)
	{
	temp = temp->NEXT;
	}

	newNode = (struct employee*)malloc(sizeof(struct employee));

	newNode->id = id;
	printf("Please enter employee name\n");
	scanf("%s %s", newNode->firstname, newNode->lastname);
	printf("Please enter employee department\n");
	scanf("%s", newNode->department);
	printf("Please enter employee salary\n");
	scanf("%f", &newNode->salary);


	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}
int listLength(struct employee * top){
	struct employee* temp;
	int count = 0;
	temp = top;

	while (temp != NULL){
		count++;
		temp = temp->NEXT;
	}

return count;
}


void DisplayList(struct employee* top, char search[]){
	struct employee* temp = top;
	while (temp != NULL) {
		if (strcmp(search, temp->department) == 0) {
			printf("ID: %d Name: %s %s Department: %s Salary:%.2f\n", temp->id, temp->firstname, temp->lastname, temp->department, temp->salary);
		}

		temp = temp->NEXT;
	}
}

int containsID(struct employee* top, int id) {
	struct employee* temp = top;

	while (temp->NEXT != NULL) {
		if (temp->id == id) {
			return 1;
		}
		temp = temp->NEXT;
	}
	return 0;
}

void generatePayslip(struct employee* employees, int employeeSearch) {
	struct employee* temp = employees;
	float paye;
	float usc;

	while (temp != NULL) {
		if (employeeSearch == temp->id) {
			//generate payslip
			printf("Gross pay: %.2f\n", temp->salary);

			if (temp->salary < 1000) {
				paye = 0;
			}
			else if (temp->salary < 2000) {
				paye = 1999 * .20;
			}
			else {
				
				paye = 1999 * .20;
				paye += (temp->salary - 2000) * .40;
			}

			printf("PAYE: %.2f\n", paye);

			usc = temp->salary * .5;
			if (usc > 200)
				usc = 200;
			printf("USC: %.2f\n", usc);


			printf("Nett Pay: %.2f\n", temp->salary - paye - usc);
			return;
		}
	}
}

//====== [FUNCTIONS: READ FILE] =====//
void readEmployees(struct employee** emp){
	FILE* file;
	int numInputs;
	int i = 0;

	int id;
	char firstname[20];
	char lastname[20];
	char department[20];
	float salary;

	file = fopen("Employees.txt", "r");

	if (file == NULL) {
	printf("File could not be opened");
	}
	else {
	//read from file
	while (!feof(file)) {
		numInputs = fscanf(file, "%d %s %s %s %f", &id, firstname, lastname, department, &salary);

		if (numInputs == 5) {
		//createEmployee from file
			if (i == 0) {
				i++;
				ReadEmployeeAtStart(emp, id, firstname, lastname, department, salary);
			}
			else
			{
				ReadEmployeeAtEnd(*emp, id, firstname, lastname, department, salary);
			}
		}
	}
	fclose(file);
	}
}


void ReadEmployeeAtStart(struct employee** top, int id, char firstname[], char lastname[], char department[], float salary) {
	struct employee* newNode;
	struct employee* temp = *top;

	newNode = (struct employee*)malloc(sizeof(struct employee));

	newNode->id = id;
	strcpy(newNode->firstname, firstname);
	strcpy(newNode->lastname, lastname);
	strcpy(newNode->department, department);
	newNode->salary = salary;

	newNode->NEXT = *top;
	*top = newNode;
}
void ReadEmployeeAtEnd(struct employee* top, int id, char firstname[], char lastname[], char department[], float salary) {
	struct employee* temp = top;
	struct employee* newNode;

	while (temp->NEXT != NULL)
	{
		temp = temp->NEXT;
	}

	newNode = (struct employee*)malloc(sizeof(struct employee));

	newNode->id = id;
	strcpy(newNode->firstname, firstname);
	strcpy(newNode->lastname, lastname);
	strcpy(newNode->department, department);
	newNode->salary = salary;


	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}

void printEmployees(struct employee* emp) {
	struct employee* temp = emp;
	FILE* file = fopen("Employees.txt", "w");

	while (temp != NULL) {
		if (file == NULL) {
			printf("File could not be opened");
		}
		else {
			fprintf(file, "%d %s %s %s %.0f\n", temp->id, temp->firstname, temp->lastname, temp->department, temp->salary);
		}
		temp = temp->NEXT;
	}
	fclose(file);
}
//*/