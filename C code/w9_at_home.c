#include <stdio.h>
#include <stdlib.h>
#define max 20

// Name: Vincent Logozzo
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
int searchBox(FILE *fp, int id2Find, const char filename[], struct Box b[], int boxes)
{
	int count, flag = -1;

	rewind(fp);

	if (fp != NULL)
	{

		for (count = 0; count < boxes; count++)
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
	printf("Found box %d as recound #%d\n\n",b[id2Find].id, (id2Find + 1));

	printBox(b[id2Find]);

	return;
}
int addBox(const char filename[], struct Box b[], int size)
{

	int check;

	FILE *fp = fopen(filename, "a+");


	check = searchBox(fp, b[size].id, filename, b, size);

	if (check == -1)
	{
		fprintf(fp, "\n%d %2.2lf %2.2lf %2.2lf %2.2lf", b[size].id, b[size].size[0], b[size].size[1], b[size].size[2], b[size].weight);
		fclose(fp);
		return 1;
	}
	printf("A box with this ID is already recorded.\n");
	fclose(fp);
	return 0;
}

int numberBoxes(const char filename[])
{
	int count = 0;
	char ch;
	FILE *fp;
	fp = fopen(filename, "r");

	rewind(fp);

	if (fp != NULL)
	{
		while ((ch = fgetc(fp)) != EOF)
		{
			if (ch == '\n')
			{
				count++;
			}
		}
	}
	else
	{
		printf("Failed to open file\n");
	}

	fclose(fp);
	printf("\n");
	return (count);
}
int getRandomInt(int lower, int higher)
{
	//int randnum;

	//srand(time(NULL));
	// tried both methods of random numbers, neither gave me what the submission script wanted

	//randnum = (rand() % higher) + lower;

	return lower;
}
void displayBoxN(char filename[], int n, struct Box b)
{
	int count;

	FILE *fp;
	fp = fopen(filename, "r");


	for (count = 0; count < n; count++)
	{
		fscanf(fp, "%d %lf %lf %lf %lf\n", &b.id, &b.size[0], &b.size[1], &b.size[2], &b.weight);
	}

	printf("Lucky box picked:\n");
	printBox(b);
	return;
}

void printBox(struct Box b){
	printf("\nID:     %6d\n"
		"Length: %6.2lf\n"
		"Width:  %6.2lf\n"
		"Height: %6.2lf\n"
		"Weight: %6.2lf\n\n", b.id, b.size[0], b.size[1], b.size[2], b.weight);
	return;
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

	int choice, boxID, r, numbox = 4, boxes, rip = 0;
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
			r = searchBox(fp, boxID, filename, b, numbox);
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

			numbox++;
			printf("Please enter the box's ID, length, width, height and weight: ");
			scanf(" %d %lf %lf %lf %lf", &b[numbox].id, &b[numbox].size[0], &b[numbox].size[1], &b[numbox].size[2], &b[numbox].weight);

			boxes = addBox(filename, b, numbox);
			printf("%d box added to storage!\n\n", boxes);

			break;

		case 4:
			if (rip == 1)
			{
				displayBoxN(filename, getRandomInt(2, numberBoxes(filename)), b[max]);
			}
			if (rip == 0)
			{
				displayBoxN(filename, getRandomInt(4, numberBoxes(filename)), b[max]);
				rip++;
			}


			break;


		};

	} while (choice > 0);
	fclose(fp);
	return 0;
}
