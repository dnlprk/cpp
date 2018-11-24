//This is the code for workshop 6
//Date: Oct 9th 2016
//Author: Elnaz Delpisheh

#include <stdio.h>

#define MAX_ITEMS 10
struct Item {
	int _sku;
	float _price;
	int _quantity;
};



void menu();
int validate(const int  low, const int high);
void clear();
void displayInventory(const struct Item items[], const int size);
int searchInventory(const struct Item items[], const int sku_item, const int size);
void addItem(struct Item items[], int *size);
void checkPrice(const struct Item items[], const int size);


int main()
{
	int select, size = 0;

	//Define and initialize these two arrays

	//At home:
	struct Item items[MAX_ITEMS];


	//Clear the screen
	clear();
	//Welcome massage
	printf("Welcome to the Shop\n");
	printf("===================\n");

	do {
		//Display the menu
		menu();
		//Validate input
		select = validate(0, 3);

		switch (select) {
		case 1:
			//Display Inventory
			displayInventory(items, size);
			break;
		case 2:
			//Add Item
			addItem(items, &size);
			break;
		case 3:
			//Check Price
			checkPrice(items, size);
			break;
		case 4:
			clear();
			break;
		case 0:
			printf("Goodbye!\n");
			break;
		default:
			printf("Invalid input, try again: ");
			break;
		}

	} while (select != 0);
	return(1);
}


void menu()
{
	printf("Please select from the following options:\n"
		"1) Display the inventory.\n"
		"2) Add to the inventory.\n"
		"3) Check price.\n"
		"4) Clear Screen.\n"
		"0) Exit.\n");
	return;
}

int validate(const int  low, const int high)
{
	int check;

	printf("Select: ");

	do
	{
		scanf("%d", &check);

		if (check > high || check < low)
		{
			printf("Invalid input, try again: ");
		}
	} while (check > high || check < low);
	return (check);
}

void clear()
{
	int count;
	for (count = 0; count < 20; count++)
	{
		printf("\n");
	}
	return;
}

void displayInventory(const struct Item items[], const int size)
{
	int count;
	printf(
		"\n\nInventory\n"
		"=========================================\n"
		"Sku         Price       Quantity\n"
	);
	for (count = 0; count < size; count++)
	{
		printf("%-10.0d  %-10.2f  %-10d\n", items[count]._sku, items[count]._price, items[count]._quantity);
	}
	printf("=========================================\n");
	return;
}

int searchInventory(const struct Item items[], const int sku_item, const int size)
{
	int flag = -1, count;

	for (count = 0; count < MAX_ITEMS; count++)
	{
		if (sku_item == items[count]._sku)
		{
			flag = count;
		}
	}
	return (flag);
}

void addItem(struct Item items[], int *size)
{
	int sku, quantily, count, flag = 0;
	float price;

	if (*size == MAX_ITEMS)
	{
		printf("Sorry the inventory is full");
	}
	else if (*size < MAX_ITEMS)
	{
		printf("Please input a SKU number: ");
		scanf("%d", &sku);
		printf("Quantity: ");
		scanf("%d", &quantily);

		for (count = 0; count < MAX_ITEMS; count++)
		{
			if (sku == items[count]._sku)
			{
				flag = count;
			}
		}
		if (sku == items[flag]._sku)
		{
			printf("The item exists in the repository, quantity is updated.\n");
			items[flag]._quantity += quantily;
		}
		else if (count == MAX_ITEMS)
		{
			printf("Price: ");
			scanf("%f", &price);
			printf("The item is successfully added to the inventory.\n");
			items[*size]._price = price;
			items[*size]._quantity = quantily;
			items[*size]._sku = sku;
			*size += 1;
		}
	}
	return;
}


void checkPrice(const struct Item items[], const int size)
{
	int sku, count, flag = 0;

	printf("Please input the sku number of the item: ");
	scanf("%d", &sku);

	for (count = 0; count < MAX_ITEMS; count++)
	{
		if (sku == items[count]._sku)
		{
			flag = count;
		}
	}
	if (sku == items[flag]._sku)
	{
		printf("Item %d costs $%0.2f\n", items[flag]._sku, items[flag]._price);
	}
	else if (count == MAX_ITEMS)
	{
		printf("Item does not exist in the shop! Please try again.\n");
	}
	return;
}
