#ifndef __HELPER_H__
#define __HELPER_H__

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
#include <chrono>

#define FileName "./src/_text.txt"
#define DoneFileName "./src/_done.txt"

using namespace std;

class Projekt {
    private:
        vector<string> tab;
        fstream in;
        fstream out; 
    public:
        Projekt();
        ~Projekt();

        // Data load / save
        void loadDataFromFile();
        void savaDataToFile();

        // Prepare string
        void trim(string &str);
        bool isCharAlpha(const char &c);
        void prepareString(string &str);
        int getMaxLength();

        // Sort
        void countSort(const int exp);
        void radixSort();
};

void throwError(int status, string msg);

#endif // __HELPER_H__