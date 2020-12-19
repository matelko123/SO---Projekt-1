#include "fileHelper.h"
#include <string>
#include <vector>

void throwError(int status=1, string msg="Some error"){
    cout<<msg<<endl;
    exit(status);
}

void initFileStream(fstream &plik, string fileName){
    plik.open(fileName);
    if(!plik || !plik.is_open())
        throwError(1, "Unable to open the file: " + fileName);
    
}

bool isCharAlpha(const char &c){
    char znaki[] = {'.', ',', '\'', '"', '!', '?', '>', '<', '\\', '(', ')', ':', ';', '-', '_', '+', '=', '/', '*'};
    int length = sizeof(znaki)/sizeof(znaki[0]);

    for(int i=0; i<length; i++)
        if(c == znaki[i] || isdigit(c)) return false;
        
    return true;
}

void trim(string &str){
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
        return;
    
    size_t last = str.find_last_not_of(' ');
    str = str.substr(first, (last - first + 1));
}

int getMaxLength(const string tab[], const unsigned int rozm){
    int mx = 0;
    
    for(int i=0; i<rozm; i++){
        int len = tab[i].length();
        if(len > mx) mx = len;
    }

    return mx;
}

// -------------------------------------------------

void prepareString(string &str){
    trim(str);                                                  // Trim string
    transform(str.begin(), str.end(),str.begin(), ::toupper);   // String to upper case

    int i=0;
    while(!isCharAlpha(str[i]) && i<str.length()) i++;

    int j=i;
    while(isCharAlpha(str[j]) && j<str.length()) j++;

    str = str.substr(i, j);
}

void loadDataFromFile(fstream &plik, string tab[], unsigned int rozm){
    if(!plik) throwError(1, "Corrupted file");
    plik.seekg(0);

    int i = 0;
    string tmp;

    while(!plik.eof()){
        plik>>tmp;
        prepareString(tmp);
        if(tmp.length() > 0) {
            //cout<<tmp<<",\t";
            tab[i++] = tmp;
        }
    }
}

int getCountOfWords(fstream &plik){
    if(!plik) throwError(1, "Corrupted file");
    plik.seekg(0);

    int counter = 0;
    string tmp;

    plik.seekg(0);
    while(!plik.eof()){
        plik>>tmp;
        prepareString(tmp);
        if(tmp.length() > 0) {
            // cout<<tmp<<",\t";
            counter++;
        }
    }
    return counter;
}