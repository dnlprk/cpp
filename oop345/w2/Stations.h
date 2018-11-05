#pragma once
#include <string>
#include "Station.h"
namespace w2
{
	class Stations
	{
	public:
		std::string dataFileName;
		int stationCount;
		Station* stationTable;


		Stations();
		~Stations();
		Stations(char*);
		void update() const;
		void restock() const;
		void report() const;
	};
}