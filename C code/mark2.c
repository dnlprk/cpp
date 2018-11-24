#include<stdio.h>
int main(void) {

	int nummarks, count;
	float total = 0, average = 0;

	printf("       ---=== IPC mark Analyser V2.0 ===---\n");
	printf("Please enter the number of students(between 3 and 40): ");
	do
	{
		scanf("%d", &nummarks);
		if (nummarks > 40 || nummarks < 3)
		{
			printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		}
	} while (nummarks > 40 || nummarks < 3);

	int studentID[40], marks[40];

	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");
	for (count = 0; count < nummarks; count++)
	{
		printf("    _________ ___\r");
		printf("  %d ", count + 1);
		scanf("%d %d", &studentID[count], &marks[count]);	
	}
	printf("=================\n");
	printf("Marks Entered, printing results:\n");
	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");
	for (count = 0; count < nummarks; count++)
	{
		total = total + marks[count];
		printf("%03d ", count + 1);
		printf("%09d %3d\n", studentID[count], marks[count]);
	}
	average = total / nummarks;
	printf("=================\n");
	printf("The average of all marks in this group is %0.1f.\n", average);
	printf("Program Ended.\n");
	return 0;
}
