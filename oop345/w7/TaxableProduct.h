#pragma once
#include "Product.h"

namespace w7 {
	class TaxableProduct : public Product
	{
	private:
		double taxes[2] = { 1.13, 1.08 };
		char tax;
	public:
		TaxableProduct(const int, const double, const char);
		double getCharge() const;
		void display(std::ostream&) const;
	};
}
