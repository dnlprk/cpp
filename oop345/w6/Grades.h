#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Grades
{
public:
	string * studentID = nullptr;
	double * grade = nullptr;
	int studentCount = 0;
	Grades();
	Grades(char* fileName) {
		fstream in(fileName, ios::in);

		if (in.is_open())
		{
			string line;

			while (!in.eof())
			{
				getline(in, line);
				if (line.size() > 1)
				{
					studentCount++;
				}
			}
			in.clear();
			in.seekg(0);

			studentID = new string[studentCount];
			grade = new double[studentCount];

			for (size_t i = 0; i < studentCount; i++)
			{
				in >> studentID[i];
				in >> grade[i];
			}
			in.close();
		}
	}
	~Grades() {
		delete[] studentID;
		delete[] grade;
	}
	template <typename T>
	void displayGrades(std::ostream& os, T letter) const {
		for (size_t i = 0; i < studentCount; i++)
		{
			os << studentID[i] << ' ' << grade[i] << ' ' << letter(grade[i]) << endl;
		}
	}

	Grades(const Grades&) = delete;
	void operator = (const Grades&) = delete;
};
