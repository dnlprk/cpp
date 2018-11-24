#include <stdio.h>
#include <string.h>

#define max 100


int main(void)
{
	char input[max];
	char name[max] = "default";


	while (1)
	{
		printf(
			"default name is: default\n"
			"Enter a name 100 characters or less: "
			);

			scanf(" %[^\n]", input);


		if (strcmp(input, name) != 0 && strlen(input) < 9)
		{
			strcpy(name, input);
			printf("name was successfully changed!\n");
			printf("input is: %s\n", input);
			printf("name is: %s\n", input);
			break;
		}
		else
		{
			printf("could not copy name, was too long!!\n");
			printf("input is: %s\n", input);
			printf("name is: %s\n", name);
		}
	}
	return 1;
}