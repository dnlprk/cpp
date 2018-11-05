#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"


namespace w3
{
	Text::Text()
	{
	}
	Text::Text(char* fileName)
	{
		std::fstream in(fileName, std::ios::in);
		if (in.is_open())
		{
			std::string line;
			while (getline(in, line))
			{
				s++;
			}
			cout << s << endl;

			b = new string[s];

			in.close();
			in.seekp(0);

			for (size_t i = 0; i < s; i++)
			{
				getline(in, b[i]);
				auto cr = b[i].find('\r');
				if (cr != string::npos)
				{
					b[i].erase(cr);
				}
			}
		}
		else
		{

		}
	}


	Text& Text::operator= (const Text& rhs)
	{
		if (this != &rhs)
		{
			delete[] b;
			b = nullptr;
			s = 0;

			if (rhs.b)
			{
				s = rhs.s;
				b = new string[s];
				for (size_t i = 0; i < s; i++)
				{
					b[i] = rhs.b[i];
				}
			}
		}
		return *this;
	}

	Text&& Text::operator= (Text&& rhs)
	{
		if (this != &rhs)
		{
			delete[] b;
			b = rhs.b;
			s = rhs.s;

			rhs.b = nullptr;
			rhs.s = 0;


		}
		return std::move(*this);
	}

	Text::Text(const Text& rhs)
	{
		*this = rhs;
	}

	Text::Text(Text&& rhs)
	{
		*this = move(rhs);
	}

	size_t Text::size()
	{
		return s;
	}
	Text::~Text()
	{
		this->b = nullptr;
		s = 0;
	}
}