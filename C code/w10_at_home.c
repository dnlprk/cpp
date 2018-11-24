#include <stdio.h>
#include <string.h>

#define MAX 9



int main(void)
{
	char username[MAX], password[MAX], input[MAX] = " ", backup[MAX];
	int count;


	printf(
		"Password Game\n"
		"=============\n"
		);
	printf("Enter your name (up to 8 characters): ");
	scanf("%8[^\n]%*c", username);

	for (count = 0; count < strlen(username); count++)
	{
		password[count] = ((int)username[count] - 1);
	}
	password[count] = '\0';

	strcpy(backup, username);

	printf("WELCOME %s\n", username);
	printf("Guess the password (up to 8 characters) %s: ", username);


	for (count = strlen(username); (count > 0) && (strcmp(input, password) != 0); count--)
	{
		scanf("%8[^\n]%*c", input);

		if (count > 1 && strcmp(password, input) != 0)
		{
			backup[count - 1] = '\0';
			printf("FALSE: Guess the password(up to 8 characters) %s: ", backup);
		}
	}

	if (strcmp(password, input) == 0)
	{
		printf("You got it, %s!!!\n", username);
	}
	else
	{
		printf("Thou has failed.\n");
	}
	printf("Game Over!\n");



	return 0;
}