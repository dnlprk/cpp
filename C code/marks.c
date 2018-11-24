/* marks.c */
/*
name: Vincent Logozzo
student id: 131631152
section: T
*/

#include <stdio.h>

int main(void)
{
	int nummarks, marks, total = 0, count;
	float average;

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
		total = total + marks;
	}
	average = (float)total / nummarks;
	printf("The average of all marks in this group is %0.1f.\n", average);
	printf("Program Ended.\n");
	return (0);
}
