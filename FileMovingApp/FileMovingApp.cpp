// FileMovingApp.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
using std::cin;
using std::cout;

int main()
{
    std::string filePath;
    std::string movePath;
    cout << "Please enter a full path to a file you want to move:\n";
    cin >> filePath;
    cout << "Enter the destination directory:\n";
    cin >> movePath;
}