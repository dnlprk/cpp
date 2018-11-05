#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Stations.h"

using namespace std;

namespace w2 {

	Stations::Stations()
	{
	}
	Stations::~Stations()
	{
		delete[] stationTable;
	}

	Stations::Stations(char * filename) {
		fstream in(filename, ios::in);
		if (!in.is_open()) {
			std::cerr << "Cannot open data file '" << filename << "'\n";
		}
		else
		{
			in >> stationCount;
			in.ignore(100, '\n');

			stationTable = new Station[stationCount];

			for (int i = 0; i < stationCount; i++)
			{
				stationTable[i] = Station(in);
			}

			in.close();
		}
	}

	void Stations::update() const {
		cout << "Passes Sold :" << endl
			<< "-------------" << endl;
		for (int i = 0; i < stationCount; i++)
		{
			int s = 0, a = 0;

			cout << stationTable[i].getName() << endl;
			cout << "Student Passes sold : ";
			cin >> s;
			cout << "Adult   Passes sold : ";
			cin >> a;

			stationTable[i].update(PASS_STUDENT, -s);
			stationTable[i].update(PASS_ADULT, -a);
		}
	}

	void Stations::restock() const {
		cout << "Passes Added :" << endl
			<< "--------------" << endl;
		for (int i = 0; i < stationCount; i++)
		{
			int s = 0, a = 0;

			cout << stationTable[i].getName() << endl;
			cout << "Student Passes added : ";
			cin >> s;
			cout << "Adult   Passes added : ";
			cin >> a;

			stationTable[i].update(PASS_STUDENT, s);
			stationTable[i].update(PASS_ADULT, a);
		}
	}

	void Stations::report() const {
		cout << "Passes in Stock : Student Adult" << endl
			<< "-------------------------------" << endl;
		for (int i = 0; i < stationCount; i++)
		{
			cout << left << setw(17) << stationTable[i].getName();
			cout << right << setw(8) << stationTable[i].inStock(PASS_STUDENT);
			cout << right << setw(6) << stationTable[i].inStock(PASS_ADULT) << endl;
		}

	}
}