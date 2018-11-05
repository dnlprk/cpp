#pragma once
#include <vector>
#include <iomanip>
#include "iProduct.h"

namespace w7
{
	class Sale
	{
	private:
		std::vector<iProduct*> productList;
	public:
		Sale(char*);
		void display(std::ostream& os) const;

	};
}