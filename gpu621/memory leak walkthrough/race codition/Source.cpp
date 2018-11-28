#include <iostream>
#include <omp.h>

int main()
{
	int count = 0;
	int half = 0;

	for (size_t i = 0; i < 4; i++)
	{

#pragma omp parallel for
		for (size_t i = 0; i < 10000; i++)
		{
			if (count % 2)
			{
				half++;
			}
			count++;
		}


		std::cout << "count " << count << " half " << half << "\n";
	}
}
