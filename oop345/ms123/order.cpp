#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <sstream>
#include "util.h"

using namespace std;

vector<int> Owidth{ 8, 7, 4 };

class Order
{
private:
	string customer, product;
	vector<string> itemList;
public:
	Order(vector<string> line)
	{
		if (line.size() > 2)
		{
			if (validCustomerName(line[0]))
			{
				customer = line[0];
				if (customer.size() > Owidth[0])
					Owidth[0] = customer.size();
			}
			if (validProductName(line[1]))
			{
				product = line[1];
				if (product.size() > Owidth[1])
					Owidth[1] = product.size();
			}
			for (size_t i = 2; i < line.size(); i++)
			{
				if (line[i].empty()) //skips nulls
				{
					continue;
				}
				else if (validItemName(line[i]))
				{
					itemList.push_back(line[i]);
					if (line[i].size() > Owidth[2])
						Owidth[2] = line[i].size();
				}
			}
		}
	}
	void print()
	{
		cout << "|" << setw(Owidth[0]) << customer
			<< "|" << setw(Owidth[1]) << product
			<< "|";
		for (auto& item : itemList)
		{
			cout << "/" << item;
		}
		cout << endl;
	}
	void graph(fstream& gv)
	{
		for (auto& item : itemList)
		{
			gv << '"' << customer << "\n" << product << '"'
				<< "->"
				<< '"' << item << '"'
				<< "[color=blue];" << endl;
		}
	}
};

class orderManager
{
private:
	vector<Order> orderList;
public:
	orderManager(vector<vector<string>>& csvTaskData)
	{
		for (auto& line : csvTaskData)
		{
			orderList.push_back(Order(line));
		}
	}
	void print()
	{		
		cout << endl
			<< "|" << setw(Owidth[0]) << "customer"
			<< "|" << setw(Owidth[1]) << "product"
			<< "|" << "item" << endl;


		for (size_t i = 0; i < Owidth[0] + Owidth[1] + 7; i++)
		{
			cout <<  "-";
		}
		cout << endl;
		for (auto& item : orderList)
		{
			item.print();
		}
	}
	void graph(string& fileName)
	{
		fileName += ".gv";
		fstream gv(fileName, ios::out | ios::trunc);
		if (gv.is_open())
		{
			gv << "digraph OrderGraph {\n";
			for (auto& o : orderList)
			{
				o.graph(gv);
			}
			gv << "}\n";
			gv.close();
		}
		vector<string> dotLocations{
			"/usr/bin/dot",                                       // default UNIX
			"/usr/local/bin/dot",                                 // sometimes a UNIX package is installed in /usr/local
			"C:\\Program Files (x86)\\Graphviz2.38\\bin\\dot.exe" // a known DOS location for graphviz 2.38 (current package as of Nov 25, 2017)
		};

		string dot;
		for (auto& e : dotLocations) {
			auto fileexist = [](string file) {fstream f(file, ios::in); return f.is_open(); };
			if (fileexist(e)) {
				if (e == dotLocations[2])
				{
					e = '"' + e + '"';
				}
				dot = move(e);
				break;
			}
		}

		if (dot.empty()) {
			cerr << "graphviz not installed\n";
			return;
		}
		string cmd = dot;
		cmd += " -Tpng -O " + fileName; // -O flag - automatically generate the output file name with the proper suffix determined by -T image type flag 
		cout << "Running command -->" << cmd << "<--\n";
		int result = system(cmd.c_str());
		cout << "It returned '" << result << (result ? "' (command failed)\n" : "' (command passed)\n");
		return;
	}
};



using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		return 1;
	}
	else
	{
		string fileName = argv[1];
		char   delim = argv[2][0];

		vector<vector<string>> csvTaskData;

		csvRead(fileName, delim, csvTaskData);
		csvPrint(cout, csvTaskData);

		orderManager om(csvTaskData);
		om.print();
		om.graph(fileName);
		cin.get();
		return 0;
	}
}
