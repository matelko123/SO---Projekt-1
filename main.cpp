#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#define orgFileName "psychologia-milosci.txt"
#define endFileName "psychologia-milosci_done.txt"

/* TODO
 ✅ Stworzyć funkcje do sprawdzania plikow a gdy plik nie istnieje to go tworzy
 * Poprawiać stringi aby nie miały znakow specjalnych
 */

using namespace std;

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

void prepareStringAplha(string &str){
    // String to upper case
    transform(str.begin(), str.end(),str.begin(), ::toupper);
}

void prepareFile(fstream &org, fstream &plik){
    if(!org || !plik) throwError(1, "Corrupted file");

    string tmp;
    while(org>>tmp){
        prepareStringAplha(tmp);
        plik<<tmp<<endl;
    }
}

int main(){
    fstream org;
    initFileStream(org, orgFileName);

    fstream plik;
    initFileStream(plik, endFileName);

    prepareFile(org, plik);

    org.close();
    plik.close();
    return 0;
}