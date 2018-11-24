/*
name: Vincent Logozzo
student id: 131631152
section: T
*/


#include <stdio.h>

struct Item
{
	int sku_;
	float price_;
	int quantity_;
};

int main(void)
{
	enum { MAX_ITEMS = 10 };
	struct Item item[MAX_ITEMS];

	int input, listsize = 0, SKUinput, count, quantitytemp, skutemp;

	printf("Welcome to the Shop\n");
	printf("===================\n");

	while (1)
	{
		printf("Please select from the following options:\n");
		do
		{
			printf("1) Display the inventory.\n");
			printf("2) Add to shop.\n");
			printf("3) Price check.\n");
			printf("0) Exit.\n");
			printf("Select:");
			scanf("%d", &input);
			if (input > 3 || input < 0)
			{
				printf("Invalid input, try again: Please select from the following options:\n");
			}
		} while (input > 3 || input < 0);

		if (input == 1)
		{
			printf("\n");
			printf("\n");
			printf("Inventory\n");
			printf("=========================================\n");
			printf("Sku         Price       Quanity\n");
			for (count = 0; count < listsize; count++)
			{
				printf("%-10.0d  %-10.2f  %-10d\n", item[count].sku_, item[count].price_, item[count].quantity_);
			}
			printf("=========================================\n");
		}
		else if (input == 2)
		{
			printf("Please input a SKU number:");
			scanf("%d", &SKUinput);

			for (count = 0; count < listsize; count++)
			{
				if (SKUinput == item[count].sku_)
				{
					break;
				}
			}
			if (SKUinput == item[count].sku_)
			{
				printf("Quantity:");
				scanf("%d", &quantitytemp);

				item[count].quantity_ = item[count].quantity_ + quantitytemp;
				printf("The item exists in the repository, quanity is updated.\n");
			}
			else if (count == listsize)
			{
				item[listsize].sku_ = SKUinput;
				printf("Quantity:");
				scanf("%d", &item[listsize].quantity_);
				printf("Price:");
				scanf("%f", &item[listsize].price_);
				printf("The item is successfully added to the inventory.\n");
				listsize++;
			}
		}
		else if (input == 3)
		{
			printf("Please input the sku number of the item:\n");
			scanf("%d", &skutemp);
			for (count = 0; count < listsize; count++)
			{
				if (skutemp == item[count].sku_)
				{
					break;
				}
			}
			if (skutemp == item[count].sku_)
			{
				printf("Item %d costs $%0.2f\n", skutemp, item[count].price_);
			}
			else if (count == listsize)
			{
				printf("Item does not exist in the shop! Please try again.\n");
			}
		}
		else if (input == 0)
		{
			printf("Good bye!\n");
			return 0;
		}
	}	
}