#pragma once

#include <filesystem>
#include <string>

class FileHandler
{
private:
	std::filesystem::path filepath;
	std::error_code ec;
	std::filesystem::file_status filestat;
public:
	void read(std::string);
	bool copyFile(std::string&, std::string&);
	bool moveFile(std::string&, std::string&);
};

