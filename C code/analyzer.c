#include <stdio.h>
#define max 100


struct student_marks {
	int   id;
	float marks;
};

void welcome(void)
{
	printf("####### Marks Analyzer V3.0 #######\n");
}
void clrKyb(void)
{
	char check;
	do
	{
		scanf("%c", &check);
	} while (check != '\n');
}
int get_data(struct student_marks ptr[])
{
	int id, count;
	float grade = 0;


	for (count = 0; grade != -1; count++)
	{
		printf("Enter student id and marks (e.g. 12345 89.5): ");
		scanf("%d %f", &id, &grade);
		clrKyb();
		if (grade != -1)
		{
			ptr[count].id = id;
			ptr[count].marks = grade;
		}
	}
	return ((count-1));
}
void show(struct student_marks list[], int num)
{
	int count;

	for (count = 0; count < num; count++)
	{
		printf("%d. %d, %0.2f\n", (count + 1), list[count].id, list[count].marks);
	}
}
float analyze(struct student_marks list[], int num, float *ptr_highest, float *ptr_lowest)
{
	int count;
	float total = 0, average;
	for ( count = 0; count < num; count++)
	{
		total += list[count].marks;

		if (list[count].marks > *ptr_highest)
		{
			*ptr_highest = list[count].marks;
		}
		if (list[count].marks < *ptr_lowest)
		{
			*ptr_lowest = list[count].marks;
		}
	}
	average = total / num;
	return average;
}
void print_summary(float avg, float high, float low)
{
	printf(
		"### result of marks analysis ###\n"
		"average: %0.2f, highest marks: %0.2f, lowest marks: %0.2f\n", avg, high, low
		);

}

int main(void){

	int range;
	float high = 0, low = 100, avg;


	struct student_marks ptr[max];

	welcome();
	range = get_data(ptr);
	avg = analyze(ptr, range, &high, &low);
	show(ptr, range);
	print_summary(avg, high, low);


	// 1. use a do-while loop to get student ids and student marks


	// 2. print out all the student marks


	// 3. data analysis


	// 4. print the result of data analysis


	return 1;
}
