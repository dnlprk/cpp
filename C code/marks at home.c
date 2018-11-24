/* marks.c */
/*
name: Vincent Logozzo
student id: 131631152
section: T
*/

#include <stdio.h>

int main(void)
{
	int nummarks, marks, total = 0, count, pass = 0, fail = 0, topmark = 0, bottommark = 100;
	float average, passtotal = 0, failtotal = 0, passaverage = 0, failaverage = 0;

	printf("       ---=== IPC mark Analyser ===---\n");
	printf("Please enter the number of marks(between 3 and 40): ");
	do
	{
		scanf("%d", &nummarks);
		if (nummarks > 40 || nummarks < 3)
		{
			printf("Invalid number, enter a number between 3 and 40 inclusive: ");
		}
	} while (nummarks > 40 || nummarks < 3);

	for (count = 0; count < nummarks; count++)
	{
		printf("%d> ", count + 1);
		scanf("%d", &marks);
		if (marks >= 0 && marks <= 100)
		{
		total = total + marks;
			if (marks >= 50)
			{
				passtotal = passtotal + marks;
				pass++;
			}
			else if (marks < 50)
			{
				failtotal = failtotal + marks;
				fail++;
			}
			if (marks > topmark)
			{
				topmark = marks;
			}
			if (marks < bottommark)
			{
				bottommark = marks;
			}
		}
		else
		{
			printf("Error: Enter values between 0 and 100 inclusive.\n");
			count--;
		}

		
	}
	passaverage = passtotal / pass;
	failaverage = failtotal / fail;
	average = (float)total / nummarks;
	printf("Total of %d students passed with an average of %0.1f.\n", pass, passaverage);
	printf("Total of %d students failed with an average of %0.1f.\n", fail, failaverage);
	printf("Highest mark in group: %d\n", topmark);
	printf("Lowest mark in group: %d\n", bottommark);
	printf("The average of all marks in this group is %0.1f.\n", average);
	printf("Program Ended.\n");
	return (0);
}
