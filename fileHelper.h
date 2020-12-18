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

void prepareFile(fstream &org, fstream &plik);

int countStringInFile(fstream &plik);

#endif // __FILEHELPER_H__