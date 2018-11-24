#include <stdio.h>
#include <stdlib.h>
#define max 4

// Name:
// Student #:


struct Box{
	int id;        // the box ID
	double size[3];   // dimensions of the box (Length, Width, Height)
	double weight; // weight of the box
};

void listBoxes(const char filename[], struct Box b)
{

	printf(
		"List of boxes\n"
		"=============\n\n"
		"ID Length Width Height Weight\n"
		"-----------------------------\n"
		);


	FILE *fp;
	fp = fopen(filename, "r");

	if (fp != NULL)
	{
		while (!feof(fp))
		{
			fscanf(fp, "%d %lf %lf %lf %lf\n", &b.id, &b.size[0], &b.size[1], &b.size[2], &b.weight);
			printf("%2d %6.2lf %5.2lf %6.2lf %6.2lf\n", b.id, b.size[0], b.size[1], b.size[2], b.weight);
		}
	}
	else
	{
		printf("Failed to open file\n");
	}

	fclose(fp);
	printf("\n");
	return;
}
void printBox(struct Box b);        // print one box- already implemented for you

// returns the record number of a box with specified ID, if found
int searchBox(FILE *fp, int id2Find, const char filename[], struct Box b[])
{
	int count, flag = -1;

	rewind(fp);

	if (fp != NULL)
	{

		for (count = 0; count < max /*|| (!feof(fp))*/; count++)
		{
			fscanf(fp, "%d %lf %lf %lf %lf\n", &b[count].id, &b[count].size[0], &b[count].size[1], &b[count].size[2], &b[count].weight);

			if (b[count].id == id2Find)
			{
				flag = count;

			}
		}
	}
	else
	{
		printf("Failed to open file\n");
	}
	return flag;
}

void displayBox(const char filename[], int id2Find, struct Box b[])
{

	printf("Found box %d as record #%d:\n\n", b[id2Find].id, (id2Find + 1));
	printf(
		"ID:%11d\n"
		"Length:%7.2lf\n"
		"Width:%8.2lf\n"
		"Height:%7.2lf\n"
		"Weight:%7.2lf\n\n", b[id2Find].id, b[id2Find].size[0], b[id2Find].size[1], 
b[id2Find].size[2], b[id2Find].weight
		);

}
int addBox(const char filename[], const struct Box * b2Add);// add a box to file

int numberBoxes(const char filename[]);      // find the number of boxes in a file
int getRandomInt(int lower, int higher);  // get a random number
void displayBoxN(char filename[], int n); // display a box given its record number

void printBox(struct Box b){
	printf("\nID:     %6d\n"
		"Length: %6.2lf\n"
		"Width:  %6.2lf\n"
		"Height: %6.2lf\n"
		"Weight: %6.2lf\n\n", b.id, b.size[0], b.size[1], b.size[2], b.weight);
}

int menu(void){
	int choice = -1;

	printf("1- List all boxes\n");
	printf("2- Find a box\n");
	printf("3- Add a box\n");
	printf("4- Randomly pick a lucky box!\n");
	printf("0- Exit program\n");

	printf("Select an option: ");
	do{
		scanf("%d", &choice);
		if (choice < 0 || choice > 4)
			printf("Please enter a number between 0 and 4: ");
	} while (choice < 0 || choice > 4);
	return choice;
}


int main(void){

	int choice, boxID, r;
	char filename[] = "storage.txt";
	struct Box b[max];
	FILE *fp;
	fp = fopen(filename, "r");

	printf("Welcome to My Storage Room\n");
	printf("==========================\n");
	do {
		// get user's choice
		choice = menu();


		switch (choice){
		case 1:

			listBoxes(filename, b[max]);

			break;

		case 2:
			printf("Enter box ID: ");
			scanf("%d", &boxID);
			r = searchBox(fp, boxID, filename, b);
			if (r != -1)
			{
				displayBox(filename, r, b);
			}
			else
			{
				printf("This box is not recorded.\n\n");
			}


			break;

		case 3:
			// AT_HOME: add a box
			// get user input for box's ID, size and weight



			// call addBox, print message to show number of boxes added



			break;

		case 4:
			// AT_HOME: randomly pick a lucky box



			// choose a random number between 1 and the number of boxes in storage


			// display the lucky box!



			break;


		};

	} while (choice > 0);
	fclose(fp);
	return 0;
}
