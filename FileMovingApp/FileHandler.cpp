#pragma once
#include "FileHandler.h"
#include <iostream>

namespace fs = std::filesystem;
void FileHandler:: read(std::string fpath){
	std::error_code ec;
	filepath = fpath;
	fs::file_status filestat = fs::status(fpath,ec);
	if (filestat.type() == fs::file_type::not_found) {
		fs::path checkingpath;
		for (auto& e : filepath)
		{
			checkingpath /= e;
			if (fs::status(checkingpath).type() == fs::file_type::not_found) {
				std::cout << "Cannot access: " << checkingpath.string()
					<< "\nCouldn't find the file/directory or cannot access it.\n";
				return;			// Set a better failure condition later
			}
		}
	}
	if (!fs::is_regular_file(filepath)) {
		std::cout << "This path does not lead to a file.\n";
	}



}
//class FileReader {
//private:
//public:
//};
//class FileWriter {
//private:
//public:
//};