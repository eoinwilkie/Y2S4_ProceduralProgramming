#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee{
	int id;
	char firstname[20];
	char lastname[20];
	char department[20];
	float salary;

	struct employee* NEXT;
};

/*/
void addEmployee(struct employee** top);
void AddElementAtStart(struct employee** top);
void AddElementAtStart(struct employee** top);
void AddElementAtEnd(struct employee* top);
void DisplayList(struct employee* top);
int Listlength(struct employee* top);


void readEmployees(struct employee** emp);
//*/
//main
void Main() {
	int menuInput;
	struct employee* employees;
	employees = (struct employee*)malloc(sizeof(struct employee));

	do {
		printf("Please enter 1 to add a new employee to the eod of the list\nPlease enter 2 to display the employees and monthly wages bull for a department");
		printf("Please enter 3 to generate a payslip for a given employee ID");
		scanf("%d", &menuInput);

		switch (menuInput) {
		case 1:
			//addEmployee(&employees);
			break;
		case 2:
			//displayList(employees);
			break;
		case 3:
			break;
		default:
			printf("Invalid selection, try again.\n");
			break;
		}


	} while (menuInput != -1);

	//free
}

/*/====== [FUNCTIONS: START] =====//
void addEmployee(struct employee** top) {
	if (listLength(top) == 0)
		addEmployeeAtStart(top);
	else
		AddElementAtEnd(*top);
}

void AddElementAtStart(struct employee** top)
{
	struct employee* newNode;
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
	scanf("%f", newNode->salary);

	newNode->NEXT = *top;
	*top = newNode;
}



void AddElementAtEnd(struct employee* top)
{
	struct employee* temp = top;
	struct employee* newNode;
	int id;

	printf("Please enter the ID of the new employee\n");
	scanf("%d", &id);

	//check if exists in lsit


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
	scanf("%f", newNode->salary);
	

	newNode->NEXT = NULL;
	temp->NEXT = newNode;
}
int Listlength(struct employee * top){
	struct employee* temp;
	int count = 0;
	temp = top;

	while (temp != NULL)
	{
		count++;
		temp = temp->NEXT;
	}

	return count;
}

void DisplayList(struct employee* top)
{
	struct employee* temp = top;
	while (temp != NULL)
	{
		printf("ID: %d Name: %s %s Department: %s Salary:%.2f\n", temp->id, temp->firstname, temp->lastname, temp->department, temp->salary);
		temp = temp->NEXT;
	}
}

//====== [FUNCTIONS: READ FILE] =====//
void readEmployees(struct employee** emp){
	FILE* file;
	int numInputs;

	int id;
	char firstname[20];
	char lastname[20];
	char department[20];
	float salary;

	file = fopen("employees.txt", "r");

	if (file == NULL) {
		printf("File could not be opened");
	}
	else {
		//read from file
		while (!feof(file)) {
			numInputs = fscanf(file, "%d %s %s %s %f", &id, firstname, lastname, department, &salary);

			if (numInputs == 5) {
				//createEmployee from file
			}
		}
		fclose(file);
	}
}

//*/