#include "Functions.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleTitle(L"LAB_8");
    bool menu = true;
    int func = 5, key = 0, pos_key = 0;
    string str, path;
      
    if (argc == 2)
    {
        path = argv[1];
    }
    else
    {
        cout << "Файл не был найден, введите его снова\n";
        cin >> path;
    }

    First_page(func, pos_key, key, str, path, menu);

    pos_key = 1;
    func -= 3;

    Second_page(func, pos_key, key, str, path, menu);

    
}