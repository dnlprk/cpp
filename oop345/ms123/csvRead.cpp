#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string trimSpace(string& s)
{
	while (!s.empty() && s[0] == ' ')
	{
		s.erase(0, 1);
	}
	int test = s.length();
	while (!s.empty() && s[s.length() - 1] == ' ')
	{
		s.erase(s.length() - 1, 1);
	}
	return s;
}

void csvRead(string& fileName, char delim, vector<vector<string>>& csvData)
{
	fstream in(fileName, ios::in);

	if (in.is_open())
	{
		string line;
		string field;
		vector<string> fields;

		while (getline(in, line))
		{
			auto cr = line.find('\r');
			if (cr != string::npos)
			{
				line.erase(cr, 1);
			}

			for (size_t i = 0; i < line.size(); i++)
			{
				if (line[i] != delim)
				{
					field += line[i];
				}
				else
				{
					fields.push_back(move(field));
				}
			}
			fields.push_back(move(field));

			csvData.push_back(move(fields));
		}
	}
	in.close();
}

void csvPrint(ostream& out, vector<vector<string>>& csvData)
{
	/*
	for (auto& line : csvData)
	{
		for (auto& e : line)
		{
			out << "|" << trimSpace(e);
		}
		out << endl;
	}

	for (size_t i = 0; i < csvData.size(); i++)
	{
		for (size_t j = 0; j < csvData[i].size(); j++)
		{
			out << " " << trimSpace(csvData[i][j]);
		}
		out << endl;
	}
	*/
	for (auto line = csvData.begin(); line < csvData.end(); line++)
	{
		for (auto field = line->begin(); field < line->end(); field++)
		{
			out << " " << trimSpace(*field);
		}
		out << endl;
	}
}
/*
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

		vector<vector<string>> csvData;

		csvRead(fileName, delim, csvData);
		csvPrint(cout, csvData);

		system("PAUSE");

		return 0;
	}
}
*/