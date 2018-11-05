#include <iostream>
#include <iomanip>
#include "TaxableProduct.h"


using namespace std;
namespace w7 {

	TaxableProduct::TaxableProduct(const int no, const double cost, const char type) : Product(no, cost)
	{ 
		this->tax = type;
	}

	double TaxableProduct::getCharge() const
	{
		if (tax == 'H')
		{
			return Product::getCharge() * taxes[0];
		}
		return Product::getCharge() * taxes[1];
	}

	void TaxableProduct::display(ostream & os) const
	{
		os << setw(10) << prodNo
			<< setw(10) << fixed << setprecision(2) << cost
			<< ' ' << (tax == 'H' ? "HST" : "PST") << endl;
	}
}