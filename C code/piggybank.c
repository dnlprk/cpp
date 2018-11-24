// piggybank program workshop 2 IPC144
// name: Vincent Logozzo
// student number: 131631152
// Section: xx


#include <stdio.h>

int main(void)
{
	int toon, loon, quart, dime, nickel, penny;
	float total;

	printf("Please enter the number of coins in your piggy bank:\n");
	printf("Toonies: ");
	scanf("%d", &toon);
	printf("Loonies: ");
	scanf("%d", &loon);
	printf("Quarters: ");
	scanf("%d", &quart);
	printf("Dimes: ");
	scanf("%d", &dime);
	printf("Nickels: ");
	scanf("%d", &nickel);
	printf("Pennies: ");
	scanf("%d", &penny);

	total = toon * 2 + loon + quart * 0.25 + dime * 0.10 + nickel * 0.05 + penny * 0.01;
	printf("You have $%0.2f in your piggy bank!\n", total);

	return 0;
}
