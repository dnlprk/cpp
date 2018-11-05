#pragma once
#include <iostream>
#define MAX 3


namespace sict {
	class Cstring
	{
	public:
		char str[MAX + 1];
		Cstring(char*);
		~Cstring();

	public:
		void display(std::ostream&);	
	};
	std::ostream& operator<<(std::ostream& os, Cstring& cs);
};
