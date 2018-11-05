#include <cstring>
#include "Cstring.h"

using namespace std;

namespace sict {


	Cstring::Cstring(char* s)
	{
		strncpy(str, s, MAX);
		str[MAX] = '\0';
	}

	Cstring::~Cstring()
	{
	}

	void Cstring::display(ostream& os)
	{
		os << str;
	}

	ostream& operator<<(ostream& os, Cstring& cs)
	{
		static int count = 0;
		os << count << ": ";
		cs.display(os);
		count++;
		return os;
	}
}