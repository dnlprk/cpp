#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "util.h"

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

		vector<vector<string>> csvData;

		csvRead(fileName, delim, csvData);
		csvPrint(cout, csvData);

		return 0;
	}
}