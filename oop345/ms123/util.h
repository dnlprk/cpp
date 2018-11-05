#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include <string>


std::string trimSpace(std::string& s);
void csvRead(std::string& fileName, char delim, std::vector<std::vector<std::string>>& csvData);
void csvPrint(std::ostream& out, std::vector<std::vector<std::string>>& csvData);
bool validSlots(std::string s);
bool validTaskName(std::string s);
bool validSequenceNumber(std::string s);
bool validItemName(std::string s);
bool validCustomerName(std::string s);
bool validProductName(std::string s);