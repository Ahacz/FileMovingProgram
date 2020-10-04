// FileMovingApp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "locale.h"
#include "FileHandler.h"
using std::cin;
using std::cout;

int main(int argc, char *argv[])
{
    setlocale(LC_CTYPE, "");
    FileHandler handler;
    std::string sourcePath;
    std::string destPath;
    if (argc < 3) {
        cout << "Please enter a path to a file you want to move:\n";
        cin >> sourcePath;
        cout << "Please enter a path to destination directory:\n";
        cin >> destPath;
    }
    else {
        sourcePath = argv[1];
        destPath = argv[2];
    }
    handler.move(sourcePath,destPath);
}