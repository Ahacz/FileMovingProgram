#pragma once
#include "FileHandler.h"
#include <iostream>

namespace fs = std::filesystem;
void FileHandler::read(std::string fpath) {
	std::error_code ec;
	filepath = fpath;
	filestat = fs::status(fpath, ec);
	if (ec) {		//check whether status checking returned an error code.
		std::cout << "Uh oh, there was an error!\n" << ec.message() << '\n';
		return;
	}
	if (!fs::is_regular_file(filepath)) {
		std::cout << "This path does not lead to a file.\n";
	}
}
bool FileHandler::copy(std::string& srcstring, std::string& dststring) {
	fs::path src(srcstring);
	fs::path dst(dststring);
	//Copying files does its own error code reports, but doing it sooner clears up where the problem lies.
	filestat = fs::status(src, ec);
	if (ec) {		//check whether status checking returned an error code.
		std::cout << "Uh oh, there was an error with the source directory!\n" << ec.message() << '\n';
		return false;
	}
	filestat = fs::status(dst, ec);
	if (ec) {
		std::cout << "Uh oh, there was an error with the destination directory!\n" << ec.message() << '\n';
		return false;
	}
	if (!fs::is_regular_file(src)) {
		std::cout << "The source path does not lead to a file.\n";
		return false;
	}
	if (!fs::is_directory(dst)) {
		std::cout << "The destination path is not a directory.\n";
		return false;
	}
	dst /= src.filename();	//Modyfing this path variable is desirable as it helps the remove() method.
	if (fs::copy_file(src, dst, ec)) {
		std::cout << "Succesfully copied " << src.filename() << " to\n" << fs::absolute(dst).string();
		return true;
	}
	else {		//If copying failed, there should be an error code.
		std::cout << "Uh oh, there was an error during copying!\n" << ec.message() << '\n';
		return false;
	}
}
bool FileHandler::move(std::string& srcstring, std::string& dststring)
{
	fs::path src(srcstring);
	fs::path dst(dststring);
	if (copy(srcstring, dststring)) {	//Only get to removing the original file if copying is successful.
		if (fs::remove(src, ec)) {
			return true;
		}
		else {
			std::cout << "There was a problem removing the original file:\n" << ec.message() << '\n';
			dst /= src.filename();
			if (!fs::remove(dst, ec)) {	//Notify the user in case removing the destination file is also unsuccessful.
				std::cout << "Couldn't remove the copied file either...\n" << ec.message() << '\n';
			}
			return false;
		}
	}
	return false;
}
//class FileReader {
//private:
//public:
//};
//class FileWriter {
//private:
//public:
//};