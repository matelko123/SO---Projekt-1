#include "fileHelper.h"
#include <string>
#include <vector>

void throwError(int status=1, string msg="Something went wrong"){
    cout<<msg<<endl;
    exit(status);
}

void trim(string &str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
        return;
    
    size_t last = str.find_last_not_of(' ');
    str = str.substr(first, (last - first + 1));
}

int getMaxLength(const string tab[], const int rozm){
    if(!tab || rozm <= 0) throwError(3, "Incorrect data.");
    int mx = 0;
    
    for(int i=0; i<rozm; i++){
        int len = tab[i].length();
        if(len > mx) mx = len;
    }

    return mx;
}

// -------------------------------------------------

bool isCharAlpha(const char &c){
    if(c >= 'A' && c <= 'Z') return true;
    else return false;
}

void prepareString(string &str){
    trim(str);                                                  // Trim string
    transform(str.begin(), str.end(), str.begin(), ::toupper);   // String to upper case

    int i = 0;
    while(!isCharAlpha(str[i]) && i<str.length()) i++;

    int j = i;
    while(isCharAlpha(str[j]) && j<str.length()) j++;

    str = str.substr(i, j-i);
}

void loadDataFromFile(fstream &plik, string tab[], const int rozm){
    if(!plik) throwError(1, "Corrupted file.");
    plik.seekg(0);

    int i = 0;
    string tmp;

    while(!plik.eof()){
        plik>>tmp;
        prepareString(tmp);
        if(tmp.length() > 0) tab[i++] = tmp;
    }
}

int getCountOfWords(fstream &plik){
    if(!plik || !plik.good()) throwError(1, "Corrupted file");
    plik.seekg(0);

    int counter = 0;
    string tmp;

    while(!plik.eof()){
        plik>>tmp;
        prepareString(tmp);
        if(tmp.length() > 0) counter++;
    }

    return counter;
}

void saveData(fstream &plik, string tab[], int rozm){
    if(!plik || !plik.good()) throwError(1, "Corrupted file");
    plik.seekg(0);

    for (int i = 0; i < rozm; i++)
        plik<<tab[i]<<endl;
}
