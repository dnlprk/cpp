#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "util.h"

using namespace std;

vector<int> Iwidth{ 4, 9, 7, 14, 11 };

class Item
{
private:
	string name, installer, remover, sequenceNumber, description;

public:
	Item(vector<string> line)
	{
		switch (line.size())
		{
		case 5:
			description = line[4];
			if (description.size() > Iwidth[4])
				Iwidth[4] = description.size();
		case 4:
			if (validSequenceNumber(line[3]))
			{
				sequenceNumber = line[3];
				if (sequenceNumber.size() > Iwidth[3])
					Iwidth[3] = sequenceNumber.size();
			}
			if (validTaskName(line[2]))
			{
				remover = line[2];
				if (remover.size() > Iwidth[2])
					Iwidth[2] = remover.size();
			}
			if (validTaskName(line[1]))
			{
				installer = line[1];
				if (installer.size() > Iwidth[1])
					Iwidth[1] = installer.size();
			}
			if (validItemName(line[0]))
			{
				name = line[0];
				if (name.size() > Iwidth[0])
					Iwidth[0] = name.size();
			}
			else
				throw string("slots not a number");
			break;
		default:
			throw string("expected 1, 2, 3, 4 or 5 fields, found") + to_string(line.size());
		}
	}
	void print()
	{
		cout << "|" << setw(Iwidth[0]) << name
			<< "|" << setw(Iwidth[1]) << installer
			<< "|" << setw(Iwidth[2]) << remover
			<< "|" << setw(Iwidth[3]) << sequenceNumber
			<< "|" << setw(Iwidth[4]) << description
			<< "|" << endl;
	}
	void graph(fstream& gv)
	{
		gv << '"' << "ITEM\n" << name << '"'
			<< "->"
			<< '"' << "INSTALLER\n" << installer << '"'
			<< "[color=green];" << endl;

		gv << '"' << "ITEM\n" << name << '"'
			<< "->"
			<< '"' << "REMOVER\n" << remover << '"'
			<< "[color=red];" << endl;

		gv << '"' << "ITEM\n" << name << '"'
			<< "->"
			<< '"' << "DISCRIPTION\n" << description << '"' << endl;
	}
};

class ItemManager
{
private:
	vector<Item> itemList;
public:
	ItemManager(vector<vector<string>>& csvTaskData)
	{
		for (auto& line : csvTaskData)
		{
			itemList.push_back(Item(line));
		}
	}
	void print()
	{
		cout << "|" << setw(Iwidth[0]) << "name"
			<< "|" << setw(Iwidth[1]) << "installer"
			<< "|" << setw(Iwidth[2]) << "remover"
			<< "|" << setw(Iwidth[3]) << "sequenceNumber"
			<< "|" << setw(Iwidth[4]) << "description"
			<< "|" << endl;
		for (size_t i = 0; i < Iwidth[0] + Iwidth[1] + Iwidth[2] + Iwidth[3] + Iwidth[4] + 6; i++)
		{
			cout << "-";
		}
		cout << endl;
		for (auto& item : itemList)
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
			gv << "digraph ItemGraph {\n";
			for (auto& i : itemList)
			{
				i.graph(gv);
			}
			gv << "}\n";
			gv.close();

			//add code from dot.cpp file
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

		ItemManager im(csvTaskData);
		im.print();
		im.graph(fileName);
		cin.get();
		return 0;
	}
}
