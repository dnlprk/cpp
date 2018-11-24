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

	int input, listsize = 0, SKUinput, count, quantitytemp;

	printf("Welcome to the Shop\n===================\n");

	while (1)
	{
		printf("Please select from the following options:\n");
		do
		{
			
			printf("1) Display the inventory.\n2) Add to shop.\n0) Exit.\nSelect:");
			scanf("%d", &input);
			if (input > 2 || input < 0)
			{
				printf("Invalid input, try again: Please select from the following options:\n");
			}
		} while (input > 2 || input < 0);

		if (input == 1)
		{
			printf("\n");
			printf("\n");
			printf("Inventory\n=========================================\nSku         Price       Quanity\n");
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
		else if (input == 0)
		{
			printf("Good bye!\n");
			return 0;
		}
	}	
}
