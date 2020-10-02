#pragma once

#include <filesystem>
#include <string>

class FileHandler
{
private:
	std::filesystem::path filepath;
	std::error_code ec;
	std::filesystem::file_status filestat;
	//FileReader reader;
	//FileWriter writer;
public:
	void read(std::string);
	bool copy(std::string&, std::string&);
	bool move(std::string&, std::string&);
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
