#pragma once
#include<string>
#include<fstream>

enum PassType
{
	PASS_STUDENT,
	PASS_ADULT,
	PASS_COUNT
};
namespace w2
{
	class Station
	{
	public:
		unsigned passes[PASS_COUNT];
		std::string name;


		Station();
		~Station();
		Station(std::fstream& in);
		void set(const std::string&, unsigned, unsigned);
		void update(PassType, int);
		unsigned inStock(PassType) const;
		const std::string& getName() const;
	};
}