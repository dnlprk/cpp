#pragma once
#include <string>
#include <iostream>
#include <fstream>
namespace w5 {
	class Message
	{
	public:
		std::string name, reply, tweet;
		Message()
		{
		}
		Message(std::ifstream& in, char c)
		{
			std::string line;
			getline(in, line, c);

			auto cr = line.find('\r');
			if (cr != std::string::npos)
			{
				line.erase(cr);
			}
			size_t i = 0;
			for (; i < line.size() && line[i] != ' '; i++)
			{
				name += line[i];
			}
			i++;
			if (i < line.size() && line[i] == '@')
			{
				i++;
				for (; i < line.size() && line[i] != ' '; i++)
				{
					reply += line[i];
				}
				i++;
			}
			for (; i < line.size(); i++)
			{
				tweet += line[i];
			}

			if (tweet.empty())
			{
				name.clear();
				reply.clear();
			}


		}// -constructor retrieves a record from the in file object, parses the record(as described above) and stores its components in the Message object.c is the character that delimits each record
		bool empty() const
		{
			return tweet.empty();
		}// -returns true if the object is in a safe empty state
		void display(std::ostream& os) const
		{
			os << "Message" << "\n";
			os << " User  : " << name << "\n";
			if (!reply.empty())
				os << " Reply : " << reply << "\n";
			os << " Tweet : " << tweet << "\n";
			os << "\n";
		}// -displays the Message objects within the container

	};

}