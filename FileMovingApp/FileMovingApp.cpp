// FileMovingApp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include "FileHandler.h"
using std::cin;
using std::cout;

int main()
{
    FileHandler handler;
    std::string filePath;
    std::string movePath;
    cout << "Please enter a full path to a file you want to move:\n";
    cin >> filePath;
   /* cout << "Enter the destination directory:\n";
    cin >> movePath;*/
    handler.read(filePath);
}