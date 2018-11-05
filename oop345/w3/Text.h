#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace w3
{
	class Text
	{
		size_t s = 0;
		string *b = nullptr;
	public:
		Text();
		Text(char* fileName);
		Text& operator= (const Text& rhs);
		Text&& operator= (Text&& rhs);
		Text(const Text& rhs);
		Text(Text&& rhs);
		size_t size();
		~Text();
	};
}