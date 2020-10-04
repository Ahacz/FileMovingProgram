// FileMovingApp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "locale.h"
#include "FileHandler.h"
using std::cin;
using std::cout;

int main()
{
    setlocale(LC_CTYPE, "");
    FileHandler handler;
    std::string filePath;
    std::string movePath;
    cout << "Please enter a path to a file you want to move:\n";
    cin >> filePath;
    cout << "Please enter a path to destination directory:\n";
    cin >> movePath;
    handler.moveFile(filePath,movePath);
    cin.get();
}