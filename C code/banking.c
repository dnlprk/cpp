#include <stdio.h>


// Structure Declaration for account
struct account
{
	int accNumber;				// Account number
	double balance;				// Balance of the account
};

/*  Function to add an amount if positive-valued */
float balanceUP(float balance, float amount)
{
	float sum;

	if (amount < 0)
	{
		sum = balance;
	}
	if (amount >= 0)
	{
		sum = balance + amount;
	}

	return(sum);
}	
float balanceDown(double balance, double amount)
{
	double sum;

	sum = balance - amount;

	return(sum);
}
float interestCalc(double balance)
{
	float rate;

	if (balance < 500)
	{
		rate = (balance * (0.99/100));
	}
	else if (balance > 500 && balance <= 1500)
	{
		rate = (balance * (1.66 / 100));
	}
	else if (balance > 1500)
	{
		rate = (balance * (2.49 / 100));
	}

	return (rate);
}

/* Function to calculate the interest rate*/
//


/* main program */
int main()
{
	const int nosClients = 5;							// Number of accounts
	int option, input, count;
	float depositAM, interestAM, withdrawAM, service;									// Hold the selection
	// Initialize the struct account array with opening balance
	struct account acct[] = { { 11111111, 123.45 }, { 22222222, 12365.50 }, { 33333333, 0 }, { 44444444, 1475 }, { 55555555, 25000.65 } };

	printf("***** Welcome to Savings Account Banking *****\n\n");

	do
	{
		// Print the option list
		printf("1.) Deposit \n");
		printf("2.) Withdraw\n");
		printf("3.) Apply monthly interest earnings to all accounts\n");
		printf("4.) Apply service charges to all accounts\n");
		printf("5.) Account Summary\n");
		printf("0.) Log out\n\n");
		printf("Please enter an option to continue: ");

		// Waiting for the input
		scanf("%d", &option);
		
		switch (option)
		{
		case 0: // Exit the program
			break;

		case 1: // Deposit

			printf("\n-- Make a deposit --\n\n");

			printf("Enter account number: ");
			scanf("%d", &input);

			for (count = 0; count < nosClients; count++)
			{
				if (input == acct[count].accNumber)
				{
					break;
				}
			}

			if (count == nosClients)
			{
				printf("ERROR: Account number does not exist.\n\n");
			}
			if (input == acct[count].accNumber)
			{
				printf("Enter amount to deposit (CAD): ");
				scanf("%f", &depositAM);
				acct[count].balance = balanceUP(acct[count].balance, depositAM);
				printf("Current balance is : ");
				printf("%0.2f", acct[count].balance);
				printf("\n\n");
			}
			//@IN-LAB				


			break;

		case 2: // Withdraw funds
			
			printf("\n-- Withdraw funds --\n\n");

			printf("Enter account number: ");
			scanf("%d", &input);

			for (count = 0; count < nosClients; count++)
			{
				if (input == acct[count].accNumber)
				{
					break;
				}
			}

			if (count == nosClients)
			{
				printf("ERROR: Account number does not exist.\n");
			}
			if (input == acct[count].accNumber)
			{
				printf("Enter amount to withdraw (CAD): ");
				scanf("%f", &withdrawAM);
				if (withdrawAM > 0 && withdrawAM <= acct[count].balance)
				{
					acct[count].balance = balanceDown(acct[count].balance, withdrawAM);
					printf("Current balance is : ");
					printf("%0.2f", acct[count].balance);
					printf("\n");
				}
				else if (withdrawAM > acct[count].balance)
				{
					printf("Withdrawal failed. You only have : %0.2f in your account\n", acct[count].balance);
				}
				else if (withdrawAM < 0)
				{
					printf("Withdrawal failed. %0.2f is not a valid amount to withdraw\n", withdrawAM);
				}
			}
			printf("\n");

			break;

		case 3: // Apply interest earnings to all accounts

			printf("\n-- Add monthly interest earnings to all accounts --\n");
			printf("\nAccount# New Balance Interest Earnings (M)\n");
			printf("-------- ----------- ---------------------\n");

			for (count = 0; count < nosClients; count++)
			{
				interestAM = interestCalc(acct[count].balance);

				printf("%8d %11.2f %21.2f\n", acct[count].accNumber, (acct[count].balance + interestAM), interestAM);
				acct[count].balance += interestAM;
			}

			printf("\n");
			break;

		case 4: // Apply Service Charges
			printf("\n-- Apply service charges to all accounts --\n\n");
			printf("Account# New Balance Service charges (M)\n");
			printf("-------- ----------- -------------------\n");

			for (count = 0; count < nosClients; count++)
			{
				if (acct[count].balance < 1500)
				{
					service = 7.50;
				}
				else if (acct[count].balance > 1500)
				{
					service = 2.50;
				}

				printf("%8d %11.2f %19.2f\n", acct[count].accNumber, balanceDown(acct[count].balance,service), service);
				acct[count].balance -= service;
			}
			printf("\n");

			break;

		case 5: // Display Account Information

			printf("\n-- Account information --\n\n");
			printf("Account# Balance   \n");
			printf("-------- ----------\n");

			for (count = 0; count < nosClients; count++)
			{
				printf("%8d %10.2f\n", acct[count].accNumber, acct[count].balance);
			}
			printf("\n");
			break;

		default:
			printf("Error: Please enter a valid option to continue\n\n");
			break;
		}


	} while (option != 0);


	return 0;
}


