#ifndef __FILEHELPER_H__
#define __FILEHELPER_H__
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

void throwError(int status, string msg);

void initFileStream(fstream &plik, string fileName);

bool isCharAlpha(const char &c);

void trim(string &str);

void prepareString(string &str);

void loadDataFromFile(fstream &plik, string tab[], unsigned int rozm);

int getMaxLength(const string tab[], const unsigned int rozm);

int getCountOfWords(fstream &plik);

#endif // __FILEHELPER_H__