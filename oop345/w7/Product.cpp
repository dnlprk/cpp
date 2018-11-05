#include <iostream>
#include <iomanip>
#include "Product.h"

using namespace std;
namespace w7 {

	Product::Product(const int no, const double cost) : prodNo(no), cost(cost)
	{ }

	double Product::getCharge() const
	{
		return cost;
	}

	void Product::display(ostream & os) const
	{
		os << setw(10) << right << prodNo
			<< setw(10) << right << fixed << setprecision(2) << cost << ' ' << endl;
	}
}