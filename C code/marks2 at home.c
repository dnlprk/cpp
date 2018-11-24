/* marks.c */
/*
name: Vincent Logozzo
student id: 131631152
section: T
*/

#include<stdio.h>

int main(void)
{
	int nummarks, pass = 0, fail = 0, topmark = 0, bottommark = 100, count;
	float total = 0, average, passaverage = 0, failaverage = 0, passtotal = 0, failtotal = 0;

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

	int studentnum[40];
	int marks[40];

	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");
	for (count = 0; count < nummarks; count++)
	{
		printf("    _________ ___\r");
		printf("%3d ", count + 1);
		do
		{
			scanf("%d %d", &studentnum[count], &marks[count]);

			if (studentnum[count] > 999999999 || studentnum[count] < 10000000)
			{
				printf("Error: Enter student number values between 10000000 and 999999999 inclusive.\n");
				printf("    _________ ___\r");
				printf("%3d ", count + 1);
			}
			else if (marks[count] > 100 || marks[count] < 0)
			{
				printf("Error: Enter mark values between 0 and 100 inclusive.\n");
				printf("    _________ ___\r");
				printf("%3d ", count + 1);
			}
		} while ((studentnum[count] > 999999999 || studentnum[count] < 10000000) || (marks[count] > 100 || marks[count] < 0));
		total = total + marks[count];
		if (marks[count] >= 50)
		{
			passtotal = passtotal + marks[count];
			pass++;
		}
		else if (marks[count] < 50)
		{
			failtotal = failtotal + marks[count];
			fail++;
		}
		if (marks[count] > topmark)
		{
			topmark = marks[count];
		}
		if (marks[count] < bottommark)
		{
			bottommark = marks[count];
		}
	}

	printf("=================\n");
	printf("Marks Entered, printing results:\n");
	printf("Row   Std No  Mrk\n");
	printf("--- --------- ---\n");

	for (count = 0; count < nummarks; count++)
	{
		if (marks[count] == topmark)
		{
			printf("%03d ", count + 1);
			printf("%09d %3d ***Highest mark***\n", studentnum[count], marks[count]);
		}
		else if (marks[count] == bottommark)
		{
			printf("%03d ", count + 1);
			printf("%09d %3d ***Lowest mark***\n", studentnum[count], marks[count]);
		}
		else
		{
			printf("%03d ", count + 1);
			printf("%09d %3d\n", studentnum[count], marks[count]);
		}
	}
	passaverage = passtotal / pass;
	failaverage = failtotal / fail;
	average = total / nummarks;
	printf("=================\n");
	printf("Total of %d students passed with an average of %0.1f.\n", pass, passaverage);
	printf("Total of %d students failed with an average of %0.1f.\n", fail, failaverage);
	printf("Highest mark in group: %d\n", topmark);
	printf("Lowest mark in group: %d\n", bottommark);
	printf("The average of all marks in this group is %0.1f.\n", average);
	printf("Program Ended.\n");
	return (0);
}

