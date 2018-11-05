#include <iostream>
#include "process.h"

using namespace std;

namespace sict
{

	process::process(char* s)
	{
		Cstring cs(s);
		cout << cs << "\n";
	}


	process::~process()
	{
	}
}