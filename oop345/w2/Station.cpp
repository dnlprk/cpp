#include<fstream>
#include<iostream>
#include "Station.h"

using namespace std;

namespace w2 {
	Station::Station()
	{
		this->name = "";
		this->passes[PASS_STUDENT] = 0;
		this->passes[PASS_ADULT] = 0;
	}
	Station::~Station()
	{
	}

	Station::Station(std::fstream & is)
	{
		string n;
		int s, a;

		getline(is, n, ';');

		is >> s;
		is >> a;
		is.ignore(100, '\n');

		set(n, s, a);
	}
	
	void Station::set(const std::string & n, unsigned s, unsigned a) {
		name = n;
		passes[PASS_STUDENT] = s;
		passes[PASS_ADULT] = a;
	}
	void Station::update(PassType pt, int value) {
		passes[pt] += value;
	}
	unsigned Station::inStock(PassType pt) const {
		return passes[pt];
	}
	const std::string & Station::getName() const {
		return name;
	}
}