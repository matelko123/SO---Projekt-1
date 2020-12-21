#ifndef __FILEHELPER_H__
#define __FILEHELPER_H__
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void throwError(int status, string msg);

bool isCharAlpha(const char &c);

void trim(string &str);

void prepareString(string &str);

void loadDataFromFile(fstream &plik, string tab[], const int rozm);

int getMaxLength(const string tab[], const int rozm);

int getCountOfWords(fstream &plik);

void saveData(fstream &plik, string tab[], const int rozm);

#endif // __FILEHELPER_H__