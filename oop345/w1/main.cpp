#include<iostream>
#include"process.h"
#include"Cstring.h"

using namespace std;

int main(int argc, char* argv[])
{

	cout << "Command Line :";
	for (int i = 0; i < argc; i++)
	{
		cout << " " << argv[i];
	}
	cout << "\n";

	if (argc == 1)
	{
		cout << "Insufficient number of arguments (min 1)\n";
		return 1;
	}
	cout << "Maximum number of characters stored : " << MAX << "\n";
	for (int i = 1; i < argc; i++)
	{
		sict::process process(argv[i]);
	}
	return 0;
}