#pragma once

#include <filesystem>
#include <string>

class FileHandler
{
private:
	std::filesystem::path filepath;
	//FileReader reader;
	//FileWriter writer;
public:
	void read(std::string);
	//void write();
};
//class FileReader
//{
//
//};
//class FileWriter
//{
//
//};
