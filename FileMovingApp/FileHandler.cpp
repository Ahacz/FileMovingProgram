#pragma once
#include "FileHandler.h"
#include <iostream>

namespace fs = std::filesystem;
bool FileHandler::copyFile(std::string& srcPathString, std::string& dstPathString) {
	fs::path srcPath(srcPathString);
	fs::path dstPath(dstPathString);
	//Copying files does its own error code reports, but doing it sooner clears up where the problem lies.
	filestat = fs::status(srcPath, ec);
	if (ec) {		//check whether status checking returned an error code.
		std::cout << "There was an error with the source file path! Full path:\n" << fs::absolute(srcPath).string() <<'\n'
			<< ec.message() << '\n';
		return false;
	}
	filestat = fs::status(dstPath, ec);
	if (ec) {
		std::cout << "There was an error with the destination directory! Full path:\n" << fs::absolute(dstPath).string() << '\n' 
			<< ec.message() << '\n';
		return false;
	}
	if (!fs::is_regular_file(srcPath)) {
		std::cout << "The source path does not lead to a file.\n";
		return false;
	}
	if (!fs::is_directory(dstPath)) {
		std::cout << "The destination path is not a directory.\n";
		return false;
	}
	dstPath /= srcPath.filename();	//Append same filename to moved file.
	if (fs::copy_file(srcPath, dstPath, ec)) {
		return true;
	}
	else {		//If copying failed, there should be an error code.
		std::cout << "Uh oh, there was an error during copying!\n" << ec.message() << '\n';
		return false;
	}
}
bool FileHandler::moveFile(std::string& srcPathString, std::string& dstPathString)
{
	fs::path srcPath(srcPathString);
	fs::path dstPath(dstPathString);
	if (copyFile(srcPathString, dstPathString)) {	//Only get to removing the original file if copying is successful.
		if (fs::remove(srcPath, ec)) {
			std::cout << "Succesfully moved " << srcPath.filename() << " to\n" << fs::absolute(dstPath).string();
			return true;
		}
		else {
			std::cout << "There was a problem removing the original file:\n" << ec.message() << '\n';
			dstPath /= srcPath.filename();
			if (!fs::remove(dstPath, ec)) {	//Notify the user in case removing the destination file is also unsuccessful.
				std::cout << "Couldn't remove the copied file either...\n" << ec.message() << '\n';
			}
			return false;
		}
	}
	return false;
}