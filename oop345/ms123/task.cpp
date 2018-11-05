#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "util.h"

using namespace std;

vector<int> Twidth{ 4, 5, 4, 4 };

class Task
{
private:
	string name, slots = "1", pass, fail;
public:
	Task(vector<string> line)
	{
		switch (line.size())
		{
		case 4:
			if (validTaskName(line[3]))
			{
				fail = line[3];
				if (fail.size() > Twidth[3])
					Twidth[3] = fail.size();
			}
		case 3:
			if (validTaskName(line[2]))
			{
				pass = line[2];
				if (pass.size() > Twidth[2])
					Twidth[2] = pass.size();
			}
		case 2:
			if (validSlots(line[1]))
			{
				slots = line[1];
				if (slots.size() > Twidth[1])
					Twidth[1] = slots.size();
			}
			else
				throw string("slots not a number");
		case 1:
			if (validTaskName(line[0]))
			{
				name = line[0];
				if (name.size() > Twidth[0])
					Twidth[0] = name.size();
			}
			else
				throw string("name not a number");
			break;
		default:
			throw string("expected 1, 2, 3, or 4 fields, found") + to_string(line.size());
		}
		if (slots.empty())
		{
			slots = "1";
		}
	}
	void print()
	{
		cout << "|" << setw(Twidth[0]) << name
			<< "|" << setw(Twidth[1]) << slots
			<< "|" << setw(Twidth[2]) << pass
			<< "|" << setw(Twidth[3]) << fail
			<< "|" << endl;
	}
	void graph(fstream& gv)
	{
		if (name != "")
		{
			if (pass.empty() && fail.empty())
				gv << '"' << name << '"' << endl;

			if (!pass.empty())
				gv << '"' << name << '"'
				<< "->"
				<< '"' << pass << '"'
				<< "[color=green];" << endl;

			if (!fail.empty())
				gv << '"' << name << '"'
				<< "->"
				<< '"' << fail << '"'
				<< "[color=red];" << endl;
		}
	}
};

class TaskManager
{
private:
	vector<Task> taskList;
public:
	TaskManager(vector<vector<string>>& csvTaskData)
	{
		for (auto& line : csvTaskData)
		{
			try
			{
				for (auto&e : line) cout << "+" << e; cout << "+\n";
				taskList.push_back(Task(line));
			}
			catch (const std::exception& e)
			{
				cout << e.what() << "\n";
			}
			catch (const std::string& e)
			{
				cout << e << "\n";
			}

		}
	}
	void print()
	{
		cout << "|" << setw(Twidth[0]) << "name"
			<< "|" << setw(Twidth[1]) << "slots"
			<< "|" << setw(Twidth[2]) << "pass"
			<< "|" << setw(Twidth[3]) << "fail"
			<< "|" << endl;
		for (auto& t : taskList)
		{
			t.print();
		}
	}
	void graph(string& fileName)
	{
		fileName += ".gv";
		fstream gv(fileName, ios::out | ios::trunc);
		if (gv.is_open())
		{
			gv << "digraph taskGraph {\n";
			for (auto& t : taskList)
			{
				t.graph(gv);
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
		cout << "usage: " << argv[0] << " task-csv-data task-csv-seperator\n";
		cout << "compiled " << __DATE__ << " at " << __TIME__ << "\n";
		return 1;
	}
	else
	{
		string fileName = argv[1];
		char   delim = argv[2][0];

		vector<vector<string>> csvTaskData;

		csvRead(fileName, delim, csvTaskData);
		csvPrint(cout, csvTaskData);

		TaskManager tm(csvTaskData);
		tm.print();
		tm.graph(fileName);
		cin.get();
		return 0;
	}
}
