#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <fstream>
#include <string>
#include <strstream>

using namespace std;

void Input_file(string& str, string path);

void Write_str(string& str);

void Output_file(string& str);

void GoToXY(short position_Y);

void Show_text(const string str);

void Druk(string& str);

void Druk2(string &str);

char* Strchr(const char * str, int c);

int Strspn(const char* str1, const char* str2);

void Menu1();

void Menu2();

void First_page(int func, int& pos_key, int& key, string& str, string path, bool menu);

void Second_page(int func, int& pos_key, int& key, string& str, string path, bool menu);


