#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Sale.h"
#include "TaxableProduct.h"

using namespace std;

namespace w7 {

	Sale::Sale(char* fileName)
	{
		ifstream file(fileName);
		iProduct* prod;

		while (file.good() && (prod = readProduct(file)) != nullptr)
		{
			productList.push_back(prod);
		}
	}

	void Sale::display(ostream & os) const
	{
		double total = 0;
		os << "Product No	Cost Taxable" << endl;

		for (auto p : productList)
		{
			p->display(os);
			total += p->getCharge();
		}

		os << setw(10) << right << "Total"
			<< setw(10) << right << total << "\n";
	}

	iProduct* readProduct(ifstream& is)
	{
		string line;
		stringstream ss;
		getline(is, line);

		if (!line.empty())
		{
			vector<string> fields;
			string buffer;
			ss.str(line);

			while (ss >> buffer)
			{
				fields.push_back(buffer);
			}

			iProduct* prod;
			if (fields.size() == 3)
			{
				prod = new TaxableProduct(stol(fields[0]), stod(fields[1]), fields[2].c_str()[0]);
			}
			else
			{
				prod = new Product(stol(fields[0]), stod(fields[1]));
			}
			return prod;
		}
		else
		{
			return nullptr;
		}
	}

	ostream& operator<<(ostream& os, const iProduct& product)
	{
		product.display(os);
		return os;
	}

}