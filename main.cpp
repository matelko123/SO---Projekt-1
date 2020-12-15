#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
// #define orgFileName "lore.txt"
#define orgFileName "psychologia-milosci.txt"
#define endFileName "psychologia-milosci_done.txt"

using namespace std;

/* TODO
 ✅ Stworzyć funkcje do sprawdzania plikow a gdy plik nie istnieje to go tworzy
 ✅ Poprawiać stringi aby nie miały znakow specjalnych
 * Dodać więcej znakow specjalnych
 * Sortowanie
 */

// -------------------------------------------------

void throwError(int status=1, string msg="Some error"){
    cout<<msg<<endl;
    exit(status);
}

void initFileStream(fstream &plik, string fileName){
    plik.open(fileName);
    if(!plik || !plik.is_open()){
        plik.open(fileName, fstream::out);
        if(!plik || !plik.is_open())
            throwError(1, "Unable to open the file: " + fileName);
    }
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

// -------------------------------------------------

void prepareString(string &str){
    trim(str);                                                  // Trim string
    transform(str.begin(), str.end(),str.begin(), ::toupper);   // String to upper case

    int i=0;
    while(!isCharAlpha(str[i]) && i<str.length()) i++;

    int j=0;
    while(isCharAlpha(str[j]) && j<str.length()) j++;

    str = str.substr(i, j);
}

void prepareFile(fstream &org, fstream &plik){
    if(!org || !plik) throwError(1, "Corrupted file");

    string tmp;
    while(org>>tmp){
        prepareString(tmp);
        if(tmp.length() > 0) plik<<tmp<<endl;
    }
}

int countStringInFile(fstream &plik){
    if(!plik) throwError(1, "Corrupted file");
    
    plik.seekg(0);

    int count = 0;
    do {
         count++;
    }
    while(!plik.eof());

    return count;
}

int main(){
    fstream org;
    initFileStream(org, orgFileName);

    fstream plik;
    remove(endFileName);
    initFileStream(plik, endFileName);

    prepareFile(org, plik);

    org.close();
    plik.close();
    return 0;
}