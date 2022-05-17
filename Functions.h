#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>

using namespace std;

void Input_file(string& str, string path);

void Output_file(string& str);

void GoToXY(short position_Y);

void Show_text(const string str);

void Druk(const string str);

void Druk2(const string str);

void Strchr();

void Strspn();

void Menu1();

void Menu2();

void First_page(int func, int& pos_key, int& key, string& str, string path, bool menu);

void Second_page(int func, int& pos_key, int& key, string& str, string path, bool menu);


