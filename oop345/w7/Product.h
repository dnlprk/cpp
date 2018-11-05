#pragma once
#include "iProduct.h"
namespace w7
{
	class Product : public iProduct
	{
	protected:
		int prodNo;
		double cost;
	public:
		Product(const int, const double);
		double getCharge() const;
		void display(std::ostream&) const;
	};
}
